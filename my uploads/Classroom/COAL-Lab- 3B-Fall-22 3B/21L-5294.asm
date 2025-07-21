[org 0x0100]
	jmp start
	
roll: db 5, 2, 9, 4
a: db 0
b: db 0
c: db 0
d: db 0

Mr1: db 0, 0, 0, 0	
Mr2: db 0, 0, 0, 0	
Mr3: db 0, 0, 0, 0	
Mr4: db 0, 0, 0, 0

Nr1: db 0, 0
Nr2: db 0, 0

Or1: dw 0, 0, 0
Or2: dw 0, 0, 0
Or3: dw 0, 0, 0

resulttext: db 'The result of Matrix Convolution is:', 0
Otext: db 'O = ', 0
walltext: db '|  , ,  |', 0

LoadMN:
	push ax
	
	mov al,byte[roll]
	mov byte[a],al
	mov al,byte[roll+1]
	mov byte[b],al
	mov al,byte[roll+2]
	mov byte[c],al
	mov al,byte[roll+3]
	mov byte[d],al
	
	mov al,byte[a]
	mov byte[Mr2+1],al
	mov al,byte[b]
	mov byte[Mr2+2],al
	mov al,byte[c]
	mov byte[Mr3+1],al
	mov al,byte[d]
	mov byte[Mr3+2],al
	
	mov al,byte[d]
	mov byte[Nr1+1],al
	mov al,byte[c]
	mov byte[Nr1+2],al
	mov al,byte[b]
	mov byte[Nr2+1],al
	mov al,byte[a]
	mov byte[Nr2+2],al
	
	
	
	pop ax
	ret
	
MatConv:
	push ax
	push cx
	push dx
	;a2
	xor ax,ax
	mov al,byte[a]
	mul byte[a]
	mov word[Or1],ax
	;b2
	xor ax,ax
	mov al,byte[b]
	mul byte[b]
	mov word[Or1+2],ax
	;c2
	xor ax,ax
	mov al,byte[c]
	mul byte[c]
	mov word[Or3],ax
	;d2
	xor ax,ax
	mov al,byte[d]
	mul byte[d]
	mov word[Or3+2],ax
	;2ab
	xor ax,ax
	mov al,byte[b]
	mul byte[a]
	shl ax,1
	mov word[Or1+1],ax
	;2ac
	xor ax,ax
	mov al,byte[a]
	mul byte[c]
	shl ax,1
	mov word[Or2],ax
	;2bd
	xor ax,ax
	mov al,byte[b]
	mul byte[d]
	shl ax,1
	mov word[Or2+2],ax
	;2cd
	xor ax,ax
	mov al,byte[c]
	mul byte[d]
	shl ax,1
	mov word[Or3+1],ax
	;2(ad + bc)
	;ad
	xor ax,ax
	mov al,byte[a]
	mul byte[d]
	mov cx,ax
	;bc
	xor ax,ax
	mov al,byte[c]
	mul byte[b]
	;ad+bc
	mov dx,ax
	add cx,dx
	;2(ad + bc)
	shl cx,1
	mov word[Or2+1],cx
	
	pop dx
	pop cx
	pop ax
	ret
	
PrintMat:
	push ax
	push cx
	
	call clrscr
	
	mov ax,5;x-pos
	push ax
	mov ax,3;y-pos
	push ax
	mov ax,0x07
	push ax
	mov ax,resulttext
	push ax
	call printtext
	
	mov ax,15;x-pos
	push ax
	mov ax,5;y-pos
	push ax
	mov ax,0x07
	push ax
	mov ax,Otext
	push ax
	call printtext
	
	mov bx,0
	
	l1: 
		mov ax,20;x-pos
		push ax
		mov ax,4;y-pos
		add ax,bx
		push ax
		mov ax,0x07
		push ax
		mov ax,walltext
		push ax
		call printtext
		add bx,1
		cmp bx,3
		jne l1
;	
;	mov bx,0
;	pn1:
;		mov ax,[Or1+bx]
;		push ax
;		mov ax,20
;		add ax,bx
;		push ax
;		mov ax,15
;		push ax
;		call printnum
;		add bx,4
;		cmp bx,12
;		jne pn1
;	mov bx,0
;	pn2:
;		mov ax,[Or2+bx]
;		push ax
;		mov ax,20
;		add ax,bx
;		push ax
;		mov ax,16
;		push ax
;		call printnum
;		add bx,4
;		cmp bx,12
;		jne pn2
;	mov bx,0
;	pn3:
;		mov ax,[Or3+bx]
;		push ax
;		mov ax,20
;		add ax,bx
;		push ax
;		mov ax,17
;		push ax
;		call printnum
;		add bx,4
;		cmp bx,12
;		jne pn3
	

	pop cx
	pop ax
	ret
printtext:
		push bp
		mov bp,sp
		push es
		push ax
		push cx
		push si
		push di
		
		push ds
		pop es
		mov di,[bp+4]
		mov cx,0xffff
		xor al,al
		repne scasb
		mov ax,0xffff
		sub ax,cx
		dec ax
		jz exit
		
		mov cx,ax
		mov ax,0xb800
		mov es,ax
		mov al,80
		mul byte[bp+8]
		add ax,[bp+10]
		shl ax,1
		mov di,ax
		mov si,[bp+4]
		mov ah,[bp+6]
		
		cld
		nextchar:
			lodsb
			stosw
			loop nextchar
		
		exit:
			pop di
			pop di
			pop di
			pop di
			pop di
			pop di
			
			ret 8
printnum:
	push bp
	mov bp,sp
	pusha
	
	mov ax,0xb800
	mov es,ax
	mov dl, [bp+6];y
	mov al,80
	mul dl
	add ax,[bp+8];x
	shl ax,1
	mov di,ax
	
	mov ax,[bp+4];number
	mov bx,10
	mov cx,0
	
	nextdigit:
		mov dx,0
		div bx
		add dl,0x30
		push dx
		inc cx
		cmp ax,0
		jnz nextdigit
		
	nextpos:
		pop dx
		mov dh,0x7
		mov [es:di],dx
		add di,2
		loop nextpos
		
	popa
	ret 6
			
start:
	call LoadMN
	call MatConv
	call PrintMat
	

	mov ax,0x4c00
	int 21h


