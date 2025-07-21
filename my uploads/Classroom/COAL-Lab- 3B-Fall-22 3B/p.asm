[org 0x0100]
jmp start

oldisr: dd 0

message1: db 'Hi, you pressed a',0
message2: db 'Hi, you pressed b',0
message3: db 'Hi, you entered wrong credentials',0

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
 


start:
	
	mov ah,0
	int 16h
	call clrscr
	
	mov ah,0
	int 16h
	cmp al,41h
	jne l1
	push 35
	push 15
	push 0x0f
	push message1
	call printstr
	jmp exit2
	l1:
	cmp al,42h
	jne exit1
	push 35
	push 15
	push 0x0f
	push message2
	call printstr
	jmp exit2
	
	exit1:
		push 35
		push 15
		push 0x0f
		push message3
		call printstr
		
	exit2:mov ax,0x4c00
	int 21h