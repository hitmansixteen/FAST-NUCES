[org 0x0100]
jmp start
S1: dw -3, -1, 2, 5, 6, 8, 9
S2: dw -2, 2, 6, 7, 9
size1: dw 7
size2: dw 5
Difference: dw 0
size3: dw 0
flag: db 0
start:
mov si,0
mov di,0
outerloop:
	mov byte[flag], 0
	mov bx,0
innerloop:
	mov ax,[S1 + si]
	cmp ax,[S2 + bx]
	jnz l1
	mov byte[flag],1
l1:
	inc bx
	cmp bx,[size2]
	jnz innerloop
	
	cmp byte[flag], 1
	jnz l2
	mov word[Difference+di], ax
	inc di
l2:
	inc si
	cmp si,[size1]
	jnz outerloop
	
mov ax, 0x4c00
int 21h

	
	
	
	

mov ax,0x4c00
int 21h



	



	

	




