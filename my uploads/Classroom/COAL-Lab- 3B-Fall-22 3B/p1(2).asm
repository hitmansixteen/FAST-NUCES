[org 0x0100]
	jmp start

palindrome:
	push bp
	mov bp, sp
	
	mov ax, [bp+4]
	push ax
	mov bx,ax
	
	
	pop bp
	ret 2

start:
	push 01111110b
	call palindrome
	
	mov ax,0x4c00
	int 0x21