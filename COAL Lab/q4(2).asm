[org 0x0100]

	mov ax, 5294
	mov bx, ax
	not bx
	mov cx, 0x1bcd
	xor cx, ax
	or bx, ax
	and bx, cx
	mov [f], bx
	
	

	mov ax, 0x4c00
	int 21h
	

f: dw 0