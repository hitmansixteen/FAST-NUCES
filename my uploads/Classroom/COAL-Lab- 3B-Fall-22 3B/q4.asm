[org 0x0100]
	jmp start
d: db 0,0,0,0
r: db 0
l: db 0

activity4:
	push ax
	push si
	push dx
	
	mov bx,10h
	mov si,0
l1:	
	div bx
	mov byte [d+si],dl
	add si,1
	cmp ax,0
	mov dx,0
	jne l1
	
	pop dx
	pop si
	pop ax
	
	ret 2
	


start:
	mov ax, 5294h
	push ax
	call activity4
	mov si,0
	mov ax,0
l2:	
	add	al, byte [d+si]
	add si,1
	cmp si,4
	jne l2
	shr ax,2
	add ax,2
	mov byte [l], al
	
	
	
	mov ax,0x4c00
	int 21h
