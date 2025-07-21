[org 0x0100]

	mov ax, 5294
	mov bx, 1100110011001100b
	mov dx, 0011001100110011b

	and bx,ax
	and dx,ax

	shr bx,2
	shl dx,2
	or bx,dx

	mov ax,bx

	mov ax, 0x4c00
	int 21h