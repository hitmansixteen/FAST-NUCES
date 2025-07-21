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
	
	mov ax,0xb800
	mov ds,ax
	mov es,ax
	mov si,0
	mov di,2880
	mov cx,1120
	cld
	rep movsw

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