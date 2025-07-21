[org 0x0100]

jmp start
;Clear Screen
clrscr:	
	mov ax, 0xb800
	mov es, ax
	xor di,di
	mov ax,0x0720
	mov cx,2000

	cld
	rep stosw
			
	ret

;Delay
delay:				
	pusha
	

	mov bx,2	
	b1:		
		mov cx, 0xFFFF
		b2:
			loop b2
		dec bx
		cmp bx,0
		jne b1
	
	popa
	ret

borderAsterisk:		
	push bp
	mov bp, sp
	pusha

	mov ax, 0xb800
	mov es, ax

	mov di, 0

	mov ah, 01110000b
	mov al, '*'

	mov bh, 0x07
	mov bl, 0x20

LefttoRight:		
	mov cx, 80

	l1:					
		mov [es:di], ax

		call delay

		mov [es:di], bx

		call delay

		add di, 2

		loop l1

		sub di, 2


	RightToBottom:		
		mov cx, 25
		
	l2:					
		mov [es:di], ax

		call delay

		mov [es:di], bx

		call delay

		add di, 160

		loop l2

		sub di, 160


	BottomToLeft:		
		mov cx, 80

	l3:					
		mov [es:di], ax

		call delay

		mov [es:di], bx

		call delay

		sub di, 2

		loop l3

		add di, 2


	LefttoTop:			
		mov cx, 25
		
	l4:				
		mov [es:di], ax

		call delay

		mov [es:di], bx

		call delay

		sub di, 160

		loop l4

		add di, 160

		jmp LefttoRight


	return:				
	popa
	pop bp
	ret

start:		call clrscr

			call borderAsterisk
	
			mov ax, 0x4c00
			int 21h






