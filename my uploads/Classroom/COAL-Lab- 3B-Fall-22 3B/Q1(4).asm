[org 0x0100]
	jmp start
message1: db 'hello world'
length1: dw 11
message2: db 'how are you?'
length2: dw 12
message3: db 'i am fine'
length3: dw 9 

clrscr:
	push bp
	mov bp,sp
	push es
	push ax
	push cx
	push di
	
	mov ax,0xb800
	mov es,ax
	xor di,di
	add di, [bp+4]
	mov ax,[bp+8]
	mov cx,[bp+6]
	
	cld
	rep stosw
	pop di
	pop cx
	pop ax
	pop es
	pop bp
	ret 4

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

	mov ax,0x0720
	push ax
	mov ax,2000
	push ax
	mov al,0
	mov bl,80
	mul bl
	push ax
	call clrscr

	mov ax,0x09db
	push ax
	mov ax,640
	push ax
	mov al,0
	mov bl,160
	mul bl
	push ax
	call clrscr
	
	mov ax,30
	push ax
	mov ax,5
	push ax
	mov ax,10000100b
	push ax
	mov ax, message3
	push ax
	push word [length3]
	call printscr
	
	mov ax,0x0fdb
	push ax
	mov ax,640
	push ax
	mov al,8
	mov bl,160
	mul bl
	push ax
	call clrscr
	
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
	
	mov ax,0x02db
	push ax
	mov ax,720
	push ax
	mov al,16
	mov bl,160
	mul bl
	push ax
	call clrscr
	
	mov ax,60
	push ax
	mov ax,20
	push ax
	mov ax,4
	push ax
	mov ax, message1
	push ax
	push word [length1]
	call printscr
	
	mov ah,0x1
	int 21h
	
	mov ax,0x4c00
	int 21h



