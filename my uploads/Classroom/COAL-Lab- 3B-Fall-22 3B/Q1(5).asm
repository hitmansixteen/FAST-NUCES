[org 0x0100]
	jmp start
message1: db 'hello world'
length1: dw 11
message2: db 'how are you?'
length2: dw 12
message3: db 'i am fine'
length3: dw 9 

clrscr:
	push es
	push ax
	push cx
	push di
	
	mov ax,0xb800
	mov es,ax
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

printscr:
	push bp
	mov bp,sp
	push es
	push ax
	push cx
	push si
	push di
	
	mov ax,0xb800
	mov es,ax
	mov al,80
	mul byte [bp+10]
	add ax, [bp+12]
	shl ax,1
	mov di,ax
	mov si,[bp+6]
	mov cx,[bp+4]
	mov ah, [bp+8]
	
	cld
nextchar:
	lodsb
	stosw
	loop nextchar
	
	pop di
	pop si
	pop cx
	pop ax
	pop es
	pop bp
	ret 10

start:
	call clrscr
	
	mov ax,30
	push ax
	mov ax,20
	push ax
	mov ax,1
	push ax
	mov ax, message1
	push ax
	push word [length1]
	call printscr
	
	mov ax,20
	push ax
	mov ax,10
	push ax
	mov ax,3
	push ax
	mov ax, message2
	push ax
	push word [length2]
	call printscr
	
	mov ax,60
	push ax
	mov ax,5
	push ax
	mov ax,2
	push ax
	mov ax, message3
	push ax
	push word [length3]
	call printscr
	
	mov ah,0x1
	int 21h
	
	mov ax,0x4c00
	int 21h



