[org 0x0100]
	jmp start
msg1: db 'Hi! I am Laraib', 0
msg2: db 'I am happy', 0
msg3: db 'I am from FAST', 0 
msg4: db 'My Roll # 21L-5294', 0

clrscr:
	
	push es
	push ax
	push cx
	push di
	
	mov ax,0xb800
	mov es, ax
	xor di,di
	mov ax,0x0720
	mov cx,2000
	
	cld
	rep stosw
	
	pop di 
	pop cx
	pop ax
	pop es
	ret
	
start:
	call clrscr

	mov ah,0x13
	mov al, 0
	mov bh, 0
	mov bl, 0x07
	mov dx, 0x0a03
	mov cx, 15
	push cs
	pop es
	mov bp, msg1
	int 0x10
	
	mov ah,0x00
	int 16h
	
	mov ah,0x13
	mov al, 0
	mov bh, 0
	mov bl, 0x07
	mov dx, 0x0b03
	mov cx, 10
	push cs
	pop es
	mov bp, msg2
	int 0x10
	
	mov ah,0
	int 16h
	
	mov ah,0x13
	mov al, 0
	mov bh, 0
	mov bl, 0x07
	mov dx, 0x0c03
	mov cx, 14
	push cs
	pop es
	mov bp, msg3
	int 0x10
	
	mov ah,0
	int 16h
	
	mov ah,0x13
	mov al, 0
	mov bh, 0
	mov bl, 0x07
	mov dx, 0x0d03
	mov cx, 18
	push cs
	pop es
	mov bp, msg4
	int 0x10
	
	mov ah,0
	int 16h
	
	mov ax,0x4c00
	int 0x21