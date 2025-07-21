[org 0x0100]

jmp start

message1: db 'Name : Laraib Akhtar', 0
message2: db 'Institute : FAST Lahore', 0
message3: db 'Batch : 2021', 0
message4: db 'Roll #: 5294', 0
message5: db 'Email ID: l215294@lhr.edu.pk', 0
message6: db 'Address : Lahore, Pakistan', 0
message7: db 'Features: Hardworking, Smart, Tall', 0
clrscr: 
	pusha
	mov ax, 0xb800 
	mov es, ax
	xor di, di 
	mov ax, 0x0720 
	mov cx, 2000 
	cld 
	rep stosw
	popa
	ret 

delay:
	push bp
	mov bp,sp
	push bx
	push cx
	mov bx,[bp+4]
	d1:
		mov cx,0xffff
		d2:
			loop d2
		sub bx,1
		cmp bx,0
		jne d1
	pop cx
	pop bx
	pop bp
	ret 2

printstr: 
	push bp 
	mov bp, sp 
	pusha 
	push ds 
	pop es 
	mov di, [bp+4] 
	mov cx, 0xffff 
	xor al, al
	repne scasb
	mov ax, 0xffff  
	sub ax, cx 
	dec ax  
	jz exit
	mov cx, ax 
	mov ax, 0xb800 
	mov es, ax 
	mov al, 80
	mul byte [bp+8]  
	add ax, [bp+10] 
	shl ax, 1  
	mov di,ax  
	mov si, [bp+4] 
	mov ah, [bp+6] 
	cld 
	nextchar: lodsb 
	stosw 
	loop nextchar 
	exit: 
		popa 
		pop bp 
		ret 8 
		
scrollup: 
	push bp 
	mov bp,sp 
	push ax 
	push cx 
	push si 
	push di 
	push es 
	push ds 
	mov ax, 80 
	mul byte [bp+4]
	mov si, ax
	push si 
	shl si, 1 
	mov cx, 2000
	sub cx, ax 
	mov ax, 0xb800 
	mov es, ax 
	mov ds, ax 
	xor di, di 
	cld 
	rep movsw
	mov ax, 0x0720
	pop cx  
	rep stosw 
	
	pop ds 
	pop es 
	pop di 
	pop si 
	pop cx 
	pop ax 
	pop bp 
	ret 2
		
start:

	call clrscr
;1	
	push 15
	push 15
	push 0x07
	push message1
	call printstr	
	push 40
	call delay
	push 1
	call scrollup
;2	
	push 15
	push 15
	push 0x07
	push message2
	call printstr
	push 40
	call delay
	push 1
	call scrollup
;3	
	push 15
	push 15
	push 0x07
	push message3
	call printstr
	push 40
	call delay
	push 1
	call scrollup
;4	
	push 15
	push 15
	push 0x07
	push message4
	call printstr
	push 40
	call delay
	push 1
	call scrollup
;5	
	push 15
	push 15
	push 0x07
	push message5
	call printstr
	push 40
	call delay
	push 1
	call scrollup
;6	
	push 15
	push 15
	push 0x07
	push message6
	call printstr
	push 40
	call delay
	push 1
	call scrollup
;7	
	push 15
	push 15
	push 0x07
	push message7
	call printstr
	push 40
	call delay
	push 1
	call scrollup
	

	
	
	
	mov ax,0x4c00
	int 21h