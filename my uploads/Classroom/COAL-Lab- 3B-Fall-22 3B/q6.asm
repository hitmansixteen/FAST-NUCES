[org 0x0100]

mov ax,[array]
mov bx,0

l1:
	add bx,2
	cmp [array+bx],ax
	jg max
	cmp [array+bx],cx
	jg max2

	cmp bx,22
	jne l1
	jmp end1

max:
	mov cx,ax
	mov ax,[array+bx]
	jmp l1

max2:
	mov cx,[array+bx]
	jmp l1

end1:
mov ax,0x4c00
int 0x21

array: dw 111, 999, 888, 888, 11, 99, 88, 88, 1, 9, 8, 8, 8