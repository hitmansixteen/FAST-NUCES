[org 0x0100]
	jmp start
d: dw 0,0,0,0
r: dw 0
l: dw 0
f: dw 0

activity4:
	push ax
	push si
	push dx
	
	mov bx,10
	mov si,0
l1:	
	div bx
	mov byte [d+si],dl
	add si,2
	cmp ax,0
	mov dx,0
	jne l1
	
	pop dx
	pop si
	pop ax
	
	ret 2
	


start:
	mov ax, 5294
	push ax
	call activity4
	mov si,0
	mov ax,0
l2:	
	add	ax, word [d+si]
	add si,2
	cmp si,8
	jne l2
	shr ax,2
	mov word [r], ax
	add ax,2
	mov word [l], ax
	mov si , word[l]
l4:
	mov cx, si
l3:
	mul word [r]
	sub cx,1
	cmp cx,0
	jne l3
	sub si, 1
	cmp si,0
	jne l4
	
	mov word [f],ax
	mov word [f+2],dx
	
	
	
	
	
	
	
	
	
	
	
	
	
	mov ax,0x4c00
	int 21h
