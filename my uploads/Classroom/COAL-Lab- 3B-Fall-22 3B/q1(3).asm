[org 0x0100]

jmp start

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
start:
	push 150
	call delay
	
	mov ax,0x4c00
	int 21h
	
	