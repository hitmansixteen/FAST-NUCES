[org 0x0100]
	jmp start

scroll:
	push bp
	mov bp, sp
	push ax
	push cx
	push si
	push di
	push es
	push ds
	
	mov ax,80
	mul byte [bp+4]
	mov si,ax
	push si
	shl si,1
	mov cx, 2000
	sub cx, ax
	mov ax, 0xb800
	mov es, ax
	mov ds,ax
	xor di, di
	cld
	rep movsw
	mov ax,0x0720
	pop cx
	pop ds
	pop es
	pop di
	pop si
	pop cx
	pop ax
	pop bp

	ret 2
	
start:

	push 5
	call scroll
	
	
	mov ax,0x4c00
	int 0x21