;Laraib Akhtar 21L-5294
;Abdul Aziz 21L-5380

[org 0x0100]
	jmp start

wheel1: db ' 0 ~O~ 0 ', 0
geartext: db 'G E A R', 0
speedtext: db 'S P E E D', 0
count: dw 0
oiltext: dw 'OIL',0
temptext: dw 'TEMP',0
timetext: db 'Time: ', 0
speednum: db '000', 0
seconds: dw 0
tick: dw 0
minutes: dw 0

; Print Block-----------------------------------------
printblock:
    ;[bp+4] = y2 position
    ;[bp+6] = width
    ;[bp+8] = y1 position
    ;[bp+10] = x1 position 
    ;[bp+12] = color
	push bp
	mov bp,sp
	push es
	push ax
	push cx
	push dx
	push di
	
	mov ax,0xb800
	mov es,ax
    mov dl,0
    add dl,byte[bp+8];y1-position
    pb:
	    mov al,80
	    mul dl 
	    add ax, [bp+10] ; x1-position
	    shl ax,1
	    mov di,ax
	    mov ax,[bp+12] ; color
	    mov cx,[bp+6] ; width
	
	    cld
	    rep stosw

        add dl,1
        cmp dl, byte[bp+4] ; y2-position
        jne pb
	pop di
	pop dx
	pop cx
	pop ax
	pop es
	pop bp
	ret 10

; Print Text------------------------------------------
printtext:
    ;[bp+4] = message
    ;[bp+6] = color
    ;[bp+8] = starting y position
    ;[bp+10] = starting x position
	
	push bp
	mov bp,sp
	push es
	push ax
	push cx
	push si
	push di

	push ds
	pop es
	mov di,word[bp+4]
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
	mul byte [bp+8] ; y-pos
	add ax, [bp+10] ; x-pos
	shl ax,1
	mov di,ax
	mov si, word[bp+4] ; string
	mov ah, byte[bp+6] ; color

	cld
	nextchar:
		lodsb
		stosw
		loop nextchar
	
	exit:
		pop di
		pop si
		pop cx
		pop ax
		pop es
		pop bp
		ret 8

; printnum--------------------------------------------
printnum:
	; [bp+4] = number 
	; [bp+6] = y-pos
	; [bp+8] = x-pos
	; [bp+10]= color

	push bp
	mov bp, sp
	push es
	push ax
	push bx
	push cx
	push dx
	push di

	mov ax, 0xb800
	mov es, ax
	mov bx, 10
	mov cx, 0
	mov al,80
	mul byte [bp+6] ; y-pos
	add ax, [bp+8] ; x-pos
	shl ax,1
	mov di,ax
	
	mov ax, [bp+4] ; number
	nextdigit:	
		mov dx, 0
		div bx
		add dl, 0x30
		push dx
		inc cx
		cmp ax, 0
		jnz nextdigit


	nextpos:	
		pop dx
		mov dh, byte[bp+10] ; color
		mov [es:di], dx
		add di, 2
		loop nextpos

		pop di
		pop dx
		pop cx
		pop bx
		pop ax
		pop es
		pop bp
		ret 8

; Clearing Screen-------------------------------------                                     
clrscr:
	push 0x0720 ; color
	push 0 ; x1
	push 0 ; y1
	push 80 ; width
	push 24 ; y2
	call printblock

    ret

; Sky-------------------------------------------------
sky:
	push 0x0bdb ; color
	push 0 ; x1
	push 0 ; y1
	push 80 ; width
    push 8 ; y2
	call printblock

	ret

; Race Lights-----------------------------------------
racelights:
	;black background
	push 0x0720 ; color	
	push 0 ; x1	
	push 0 ; y1
	push 4 ; width
    push 7 ; y2
	call printblock
	;red light
	mov cx,0
	rl1:
		push  0x08db; color
		push 1 ; x1
		mov ax,1 ; y1
		add ax,cx
		push ax
		push 2 ; width
    	mov ax,2 ; y2
		add ax,cx
		push ax
		call printblock	
		add cx,2
		cmp cx, 6
		jne rl1


	ret


; Grass-----------------------------------------------    
grass:
	mov cx,0
	gr1:
		push 0x2ab0 ; color
		push 0 ; x1
		mov ax,8 ; y1
		add ax,cx
		push ax
		mov ax, 25 ; width
		sub ax,cx
		push ax
    	mov ax,9 ; y2
		add ax,cx
		push ax
		call printblock

		push 0x0fdb ; color
		mov ax,25 ; x1
		sub ax,cx
		push ax
		mov ax,8 ; y1
		add ax,cx
		push ax
		push 1 ; width
    	mov ax,9 ; y2
		add ax,cx
		push ax
		call printblock

		add cx,1
		cmp cx,8
		jne gr1
	mov cx,0
	gr2:
		push 0x2ab0 ; color
		mov ax,55 ; x1
		add ax,cx
		push ax
		mov ax,8 ; y1
		add ax,cx
		push ax
		mov ax, 25 ; width
		sub ax,cx
		push ax
    	mov ax,9 ; y2
		add ax,cx
		push ax
		call printblock

		push 0x0fdb ; color
		mov ax,55 ; x1
		add ax,cx
		push ax
		mov ax,8 ; y1
		add ax,cx
		push ax
		push 1 ; width
    	mov ax,9 ; y2
		add ax,cx
		push ax
		call printblock

		add cx,1
		cmp cx,8
		jne gr2

	ret

; Road------------------------------------------------   
road:
	push 0x08db ; color
	push 0 ; x1
	push 8 ; y1
	push  80 ; width
    push 16 ; y2
	call printblock
	
	push 0x0fdb ; color
	push 39 ; x1
	push 8 ; y1
	push 1 ; width
	push 16 ; y2
	call printblock
	push 0x08db ; color
	push 39 ; x1
	mov ax,8
	push ax ; y1
	push 1 ; width
	mov ax, 10
    push ax ; y2
	call printblock

	ret
; gearfire--------------------------------------------
gear: 
	push 0x07db ; color
	push 70 ; x1
	push 19 ; y1
	push  10 ; width
    push 25 ; y2
	call printblock

	mov cx,0
	gf1:
		push 0x08db ; color
		mov ax,72 ; x1
		add ax,cx
		push ax
		push 20 ; y1
		push  1 ; width
    	push 24 ; y2
		call printblock
		add cx,3
		cmp cx,9
		jne gf1

	push 0x08db ; color
	push 73 ; x1
	push 22 ; y1
	push  6 ; width
    push 23 ; y2
	call printblock

	push 0x0720 ; color
	push 70 ; x1
	push 19 ; y1
	push  4 ; width
    push 21 ; y2
	call printblock

	push 72 ; x-position
	push 24 ; y-position
	push 0x7e ; color
	push  geartext ; text
	call printtext

	ret
; Board-----------------------------------------------  
board:
	push 0x08db ; color
	push 0 ; x1
	push 16 ; y1
	push  80 ; width
    push 25 ; y2
	call printblock

	push 0x07db ; color
	push 0 ; x1
	push 16 ; y1
	push  80 ; width
    push 17 ; y2
	call printblock

	call wheel
	call gear
	call speed
	call oiltemp
	call mirror
	call timerbox

	push 0x0ea7 ; color
	push 39 ; x1
	push 17 ; y1
	push  1 ; width
    push 18 ; y2
	call printblock

	ret

; Wheel-----------------------------------------------    
wheel:
	mov cx,0
	wh1:
		push 0x0720 ; color
		mov ax,35 ; x1
		shl cx,2
		sub ax,cx
		push ax
		shr cx,2
		mov ax,17 ; y1
		add ax,cx
		push ax
		push  5 ; width
    	mov ax,18 ; y2
		add ax,cx
		push ax
		call printblock

		push 0x0720 ; color
		mov ax,40 ; x1
		shl cx,2
		add ax,cx
		push ax
		shr cx,2
		mov ax,17 ; y1
		add ax,cx
		push ax
		push  5 ; width
    	mov ax,18 ; y2
		add ax,cx
		push ax
		call printblock

		add cx,1
		cmp cx,3
		jne wh1

	mov cx,0
	wh2:
		push 0x0720 ; color
		mov ax,27 ; x1
		sub ax,cx
		push ax
		mov ax,20 ; y1
		add ax,cx
		push ax
		push 1 ; width
    	mov ax,22 ; y2
		add ax,cx
		push ax
		call printblock

		push 0x0720 ; color
		mov ax,52 ; x1
		add ax,cx
		push ax
		mov ax,20 ; y1
		add ax,cx
		push ax
		push  1 ; width
    	mov ax,22 ; y2
		add ax,cx
		push ax
		call printblock

		add cx,1
		cmp cx,3
		jne wh2

	push 0x00db ; color
	push 25 ; x1
	push 24 ; y1
	push 30 ; width
    push 25 ; y2
	call printblock
	 
	push 35 ; x-position
	push 24 ; y-position
	push 0x70 ; color
	push  wheel1 ; text
	call printtext

	ret

; Stadium---------------------------------------------
stadium:

	push 0x4cfe ; color
	push 20 ; x1
	push 5 ; y1
	push  40 ; width
    push 7 ; y2
	call printblock
	
	push 0x07f4 ; color
	push 21 ; x1
	push 6 ; y1
	push  38 ; width
    push 7 ; y2
	call printblock

	mov cx,0
	stad:
		push 0x4cfe ; color
		mov ax,27 ; x1
		add ax,cx
		push ax
		push 4 ; y1
		push  1 ; width
    	push 5 ; y2
		call printblock
		add cx,5
		cmp cx,30
		jne stad

	push 0x4cfe ; color
	push 5 ; x1
	push 7 ; y1
	push  70 ; width
    push 8 ; y2
	call printblock

	ret
; Speed-----------------------------------------------
speed:
	push 35 ; x-position
	push 23 ; y-position
	push 0x07 ; color
	push  speedtext ; text
	call printtext
	push 38 ; x-position
	push 22 ; y-position
	push 0x47 ; color
	push  speednum ; text
	call printtext
	ret
; Delay-----------------------------------------------
delay:
	push bp
	mov bp,sp
	push cx
	push ax
	mov al, byte [bp+4]
	d1:
		mov cx, 0xffff
		d2:
			loop d2
		sub ax,1
		cmp ax,0
		jne d1
	pop ax
	pop cx
	pop bp
	ret 2
; Initialize------------------------------------------
initialize:
	call clrscr
	call sky
	call road
	call grass
	call board
	push 0
	call clouds
	call stadium
	call racelights
	push 18
	push 9
	call bush
	push 59
	push 9
	call bush

	ret
; Traffic Lights loop---------------------------------
trafficlight_loop:
	push 40
	call delay

	push 0x0cdb ; color
	push 1 ; x1
	push 1 ; y1
	push  2 ; width
    push 2 ; y2
	call printblock 
	push 40 ; delay amount
	call delay

	push 0x0edb ; color
	push 1 ; x1
	push 3 ; y1
	push  2 ; width
    push 4 ; y2
	call printblock
	push 40
	call delay

	push 0x0adb ; color
	push 1 ; x1
	push 5 ; y1
	push  2 ; width
    push 6 ; y2
	call printblock
	push 40
	call delay
	ret
; Clouds----------------------------------------------
clouds:
	push bp
	mov bp,sp
	push ax

	push 0x0fdb ; color
	mov ax,10
	add ax,[bp+4]
	push ax ; x1
	push 2 ; y1
	push  10 ; width
    push 3 ; y2
	call printblock
	push 0x0fdb ; color
	mov ax, 12
	add ax,[bp+4]
	push ax ; x1
	push 1 ; y1
	push  7 ; width
    push 4 ; y2
	call printblock
	pop ax
	pop bp
	ret 2
; bush------------------------------------------------
bush:
	push bp
	mov bp,sp
	push ax

	push 0x02db ; color
	mov ax,[bp+6] ; x1
	push ax
	mov ax, [bp+4] ; y1
	push ax
	push 3 ; width
	mov ax, [bp+4] ; y2
	add ax,1
	push ax
	call printblock
	push 0x02db ; color
	mov ax,[bp+6] ; x1
	add ax,1	
	push ax
	mov ax, [bp+4] ; y1
	sub ax,1
	push ax
	push 1 ; width
	mov ax, [bp+4] ; y2
	push ax
	call printblock

	pop ax
	pop bp
	ret 4
; oiltemp---------------------------------------------
oiltemp:

	push 0x00db ; color
	push 59 ; x1
	push 18 ; y1
	push  5 ; width
    push 21 ; y2
	call printblock

	push 0x00db ; color
	push 59 ; x1
	push 22 ; y1
	push  5 ; width
    push 25 ; y2
	call printblock

	push 0x06db ; color
	push 59 ; x1
	push 19 ; y1
	push  5 ; width
    push 21 ; y2
	call printblock

	push 0x02db ; color
	push 59 ; x1
	push 23 ; y1
	push  5 ; width
    push 25 ; y2
	call printblock

	

	push 60 ; x-position
	push 18 ; y-position
	push 0x07 ; color
	push  oiltext ; text
	call printtext
	push 60 ; x-position
	push 22 ; y-position
	push 0x07 ; color
	push  temptext ; text
	call printtext
	ret
; mirror----------------------------------------------
mirror:
	push 0x07db ; color
	push 0 ; x1
	push 17 ; y1
	push  9 ; width
    push 20 ; y2
	call printblock
	push 0x2ab0 ; color
	push 0 ; x1
	push 17 ; y1
	push  3 ; width
    push 19 ; y2
	call printblock
	push 0x0fdb ; color
	push 3 ; x1
	push 17 ; y1
	push  1 ; width
    push 19 ; y2
	call printblock
	push 0x08db ; color
	push 4 ; x1
	push 17 ; y1
	push  4 ; width
    push  19; y2
	call printblock
	push 0x0fdb ; color
	push 6 ; x1
	push 18 ; y1
	push  1 ; width
    push 19 ; y2
	call printblock
	ret
; timerbox--------------------------------------------
timerbox:
	push 0x4020 ; color
	push 0 ; x1
	push 20 ; y1
	push  9 ; width
    push 24 ; y2
	call printblock
	push 0 ; x-position
	push 23 ; y-position
	push 0x47 ; color
	push  timetext ; text
	call printtext
	ret
; timer-----------------------------------------------
timer:
	push ax 

	inc word [cs:tick]; increment tick count 
	cmp word[cs:tick],18
	jne exit1

	mov word[cs:tick],0
	inc word[cs:seconds]
	cmp word[cs:seconds],10
	jb ti1
	push 0x47
	push 7
	push 23
	mov ax, word[cs:seconds]
	push ax
	call printnum ; print tick count 
	jmp ti2
	ti1:
		push 0x47
		push 8
		push 23
		mov ax, word[cs:seconds]
		push ax
		call printnum ; print tick count 
	ti2:
		cmp word[cs:seconds],60
		jne exit1
		mov word[cs:seconds],0
		inc word[cs:minutes]
		push 0x47
		push 7
		push 23
		mov ax, word[cs:seconds]
		push ax
		call printnum ; print tick count 
		push 0x47
		push 5
		push 23
		mov ax, word[cs:minutes]
		push ax
		call printnum ; print tick count 

	exit1:
		mov al, 0x20 
		out 0x20, al ; end of interrupt 
		pop ax 
		iret ; return from interrupt 
; turn------------------------------------------------
turn:
	push 0x2ab0 ; color
	push 0 ; x1
	push 8 ; y1
	push 25 ; width
	push 16 ; y2
	call printblock

	push 0x0fdb ; color
	push 25 ; x1
	push 8 ; y1
	push 1 ; width
	push 16 ; y2
	call printblock

		ret
; tree--------------------------------------------
tree:
	push 0x2020 ; color
	push 59 ; x1
	push 3 ; y1
	push  6 ; width
    push 4 ; y2
	call printblock
	
	push 0x2020 ; color
	push 57 ; x1
	push 4 ; y1
	push  10 ; width
    push 5 ; y2
	call printblock
	push 0x6020 ; color
	push 61 ; x1
	push 5 ; y1
	push  2 ; width
    push 8 ; y2
	call printblock

	push 0x2020 ; color
	push 19 ; x1
	push 3 ; y1
	push  6 ; width
    push 4 ; y2
	call printblock
	
	push 0x2020 ; color
	push 17 ; x1
	push 4 ; y1
	push  10 ; width
    push 5 ; y2
	call printblock
	push 0x6020 ; color
	push 21 ; x1
	push 5 ; y1
	push  2 ; width
    push 8 ; y2
	call printblock

 	ret
; Interrupt hook--------------------------------------
hook:
	push es
	push ax
	xor ax, ax 
	mov es, ax ; point es to IVT base 
	cli ; disable interrupts 
	mov word [es:8*4], timer; store offset at n*4 
	mov [es:8*4+2], cs ; store segment at n*4+2 
	sti ; enable interrupts 
	pop ax
	pop es
	ret
; Start-----------------------------------------------
start:
	call initialize
	call trafficlight_loop
	call hook
	mov bx,0
	mainloop1:
		call sky
		call racelights
		push bx
		call clouds
		call stadium
		mov dx,0
		roadloop1:
			;white line
			push 0x0fdb ; color
			push 39 ; x1
			push 8 ; y1
			push 1 ; width
			push 16 ; y2
			call printblock

			; road banane ka harba
			push 0x08db ; color
			push 39 ; x1
			mov ax,8
			add ax,dx
			push ax ; y1
			push 1 ; width
			mov ax, 10
			add ax,dx
    		push ax ; y2
			call printblock

			;bush
			call grass
			mov ax, 18
			sub ax,dx
			push ax
			mov ax, 9
			add ax,dx
			push ax
			call bush

			mov ax, 59
			add ax,dx
			push ax
			mov ax, 9
			add ax,dx
			push ax
			call bush

			push 3
			call delay
			add dx,1
			cmp dx,7
			jne roadloop1
		add bx,1
		cmp bx,10
		jne mainloop1

	call sky
	call racelights
	call clouds
	call tree
	call turn
	push 25
	call delay
	call road
	call grass

	mov bx,0
	mainloop2:
		call sky
		call racelights
		push bx
		call clouds
		call tree
		mov dx,0
		roadloop2:
			;white line
			push 0x0fdb ; color
			push 39 ; x1
			push 8 ; y1
			push 1 ; width
			push 16 ; y2
			call printblock

			; road banane ka harba
			push 0x08db ; color
			push 39 ; x1
			mov ax,8
			add ax,dx
			push ax ; y1
			push 1 ; width
			mov ax, 10
			add ax,dx
    		push ax ; y2
			call printblock

			;bush
			call grass
			mov ax, 18
			sub ax,dx
			push ax
			mov ax, 9
			add ax,dx
			push ax
			call bush

			mov ax, 59
			add ax,dx
			push ax
			mov ax, 9
			add ax,dx
			push ax
			call bush

			push 3
			call delay
			add dx,1
			cmp dx,7
			jne roadloop2
		add bx,1
		cmp bx,30
		jne mainloop2

	mov dx, start ; end of resident portion 
	add dx, 15 ; round up to next para 
	mov cl, 4 
	shr dx, cl ; number of paras 
	mov ax, 0x3100 ; terminate and stay resident 
	int 0x21

	


	

	

