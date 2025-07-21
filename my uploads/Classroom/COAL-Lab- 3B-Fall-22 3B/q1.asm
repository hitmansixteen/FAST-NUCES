[org 0x0100]
jmp start

oldisr: dd 0

message: db 'laraib akhtar',0

printstr: push bp 
 mov bp, sp 
 push es 
 push ax 
 push cx 
 push si 
 push di 
 push ds 
 pop es ; load ds in es 
 mov di, [bp+4] ; point di to string 
 mov cx, 0xffff ; load maximum number in cx 
 xor al, al ; load a zero in al 
 repne scasb ; find zero in the string 
 mov ax, 0xffff ; load maximum number in ax 
 sub ax, cx ; find change in cx 
 dec ax ; exclude null from length 
 jz exit ; no printing if string is empty
 mov cx, ax ; load string length in cx 
 mov ax, 0xb800 
 mov es, ax ; point es to video base 
 mov al, 80 ; load al with columns per row 
 mul byte [bp+8] ; multiply with y position 
 add ax, [bp+10] ; add x position 
 shl ax, 1 ; turn into byte offset 
 mov di,ax ; point di to required location 
 mov si, [bp+4] ; point si to string 
 mov ah, [bp+6] ; load attribute in ah 
 cld ; auto increment mode 
nextchar: lodsb ; load next char in al 
 stosw ; print char/attribute pair 
 loop nextchar ; repeat for the whole string 
exit: pop di 
 pop si 
 pop cx 
 pop ax 
 pop es 
 pop bp 
 ret 8 

;Clear Screen
clrscr:	
	mov ax, 0xb800
	mov es, ax
	xor di,di
	mov ax,0x0720
	mov cx,2000

	cld
	rep stosw
			
	ret
 
; keyboard interrupt service routine 
kbisr: 
	push ax 
	push es 
	mov ax, 0xb800 
	mov es, ax ; point es to video memory 
	
	push cs
	pop ds
	in al, 0x60 ; read a char from keyboard port 
	
	cmp al,0x2a
	jne nextcmp
	push 35
	push 15
	push 0x0f
	push message
	call printstr
	jmp exit1
	nextcmp:
		cmp al,0xaa
		jne nomatch
		call clrscr
		jmp exit1
	nomatch: 
		pop es 
		pop ax 
		jmp far [cs:oldisr] ; call the original ISR 
	exit1: 
		mov al, 0x20 
		out 0x20, al ; send EOI to PIC 
		pop es 
		pop ax 
		iret 

start:
	xor ax, ax 
	mov es, ax ; point es to IVT base 
	mov ax, [es:9*4] 
	mov [oldisr], ax ; save offset of old routine 
	mov ax, [es:9*4+2] 
	mov [oldisr+2], ax ; save segment of old routine 
	cli ; disable interrupts 
	mov word [es:9*4], kbisr ; store offset at n*4 
	mov [es:9*4+2], cs ; store segment at n*4+2 
	sti ; enable interrupts 
	mov dx, start ; end of resident portion 
	add dx, 15 ; round up to next para 
	mov cl, 4 
	shr dx, cl ; number of paras 
	mov ax, 0x3100 ; terminate and stay resident 
	int 0x21 