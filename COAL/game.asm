;Laraib Akhtar 21L-5294
;Abdul Aziz 21L-5380

[org 0x0100]
	jmp start
message3: db 'i am fine'
length3: dw 9 
timer1: db 'P : 01 L : 01'
timerl1: dw 13 
timer2: db '0 0 m 00 . 0s'
timerl2: dw 13
speed000: db 'SPEED: 000'
speed000l: dw 10
wheel1: db ' 0 ~O~ 0  '
wheel1l: dw 10
RPM1: db '7 8 9 10  11'
RPM1l: dw 12
RPM2: db '6         12'
RPM2l: dw 12
RPM3: db '5  4  3  2 1'
RPM3l: dw 12
rpmtext: db 'r p m'
rpmtextl: dw 5
oiltext: db 'O I L'
oiltextl: dw 5
temptext: db 'T E M P'
temptextl: dw 7
starttext: db 'S  T  A  R  T'
starttextl: dw 13
firetext: db 'FIRE'
firetextl: dw 4
geartext: db 'G E A R'
geartextl: dw 7



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
    ;[bp+4] = message length
    ;[bp+6] = message
    ;[bp+8] = color
    ;[bp+10] = starting y position
    ;[bp+12] = starting x position
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
	mul byte [bp+10] ; y-position
	add ax, [bp+12] ; x-postion
	shl ax,1
	mov di,ax
	mov si,[bp+6] ; message
	mov cx,[bp+4] ; message length
	mov ah, [bp+8] ; color
	
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
; Clearing Screen-------------------------------------                                     
clrscr:
    mov ax,0x0720 ; color
	push ax
	mov ax,0 ; x1
	push ax
	mov ax,0 ; y1
	push ax
	mov ax, 80; width
	push ax
    mov ax,24 ; y2
	push ax
	call printblock

    ret
; Sky-------------------------------------------------
sky:
	mov ax,0x0bdb ; color
	push ax
	mov ax,0 ; x1
	push ax
	mov ax,0 ; y1
	push ax
	mov ax, 80 ; width
	push ax
    mov ax,8 ; y2
	push ax
	call printblock

	ret
; Race Lights-----------------------------------------
racelights:
	;black background
	mov ax,0x0720 ; color
	push ax
	mov ax,0 ; x1
	push ax
	mov ax,0 ; y1
	push ax
	mov ax, 10 ; width
	push ax
    mov ax,7 ; y2
	push ax
	call printblock
	;red light
	mov cx,0
	rl:
		mov ax,0x0cdb ; color
		push ax
		mov ax,2 ; x1
		push ax
		mov ax,1 ; y1
		add ax,cx
		push ax
		mov ax, 2 ; width
		push ax
    	mov ax,2 ; y2
		add ax,cx
		push ax
		call printblock

		mov ax,0x0cdb ; color
		push ax
		mov ax,6 ; x1
		push ax
		mov ax,1 ; y1
		add ax,cx
		push ax
		mov ax, 2 ; width
		push ax
    	mov ax,2 ; y2
		add ax,cx
		push ax
		call printblock

		add cx,2
		cmp cx,6
		jne rl

	ret
; Timer-----------------------------------------------    
timer:
	mov ax,0x78ce ; color
	push ax
	mov ax,65 ; x1
	push ax
	mov ax,0 ; y1
	push ax
	mov ax, 15 ; width
	push ax
    mov ax,5 ; y2
	push ax
	call printblock

	mov ax,0x0cdb ; color
	push ax
	mov ax,66 ; x1
	push ax
	mov ax,1 ; y1
	push ax
	mov ax, 13 ; width
	push ax
    mov ax,4 ; y2
	push ax
	call printblock

	mov ax,66 ; x-position
	push ax
	mov ax,1 ; y-position
	push ax
	mov ax,0x4f ; color
	push ax
	mov ax, timer1 ; text
	push ax
	push word [timerl1] ; text length
	call printtext

	mov cx,0
	tm:
		mov ax,66 ; x-position
		push ax
		mov ax,2 ; y-position
		add ax,cx
		push ax
		mov ax,0x4f ; color
		push ax
		mov ax, timer2 ; text
		push ax
		push word [timerl2] ; text length
		call printtext
		add cx,1
		cmp cx,2
		jne tm
	

	ret
; Grass-----------------------------------------------    
grass:
	mov cx,0
	gr1:
		mov ax,0x2ab0 ; color
		push ax
		mov ax,0 ; x1
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

		mov ax,0x0fdb ; color
		push ax
		mov ax,25 ; x1
		sub ax,cx
		push ax
		mov ax,8 ; y1
		add ax,cx
		push ax
		mov ax, 1 ; width
		push ax
    	mov ax,9 ; y2
		add ax,cx
		push ax
		call printblock

		add cx,1
		cmp cx,8
		jne gr1
	mov cx,0
	gr2:
		mov ax,0x2ab0 ; color
		push ax
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

		mov ax,0x0fdb ; color
		push ax
		mov ax,55 ; x1
		add ax,cx
		push ax
		mov ax,8 ; y1
		add ax,cx
		push ax
		mov ax, 1 ; width
		push ax
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
	mov ax,0x08db ; color
	push ax
	mov ax,0 ; x1
	push ax
	mov ax,8 ; y1
	push ax
	mov ax, 80 ; width
	push ax
    mov ax,16 ; y2
	push ax
	call printblock
	
	mov cx,0
	rd:
		mov ax,0x0fdb ; color
		push ax
		mov ax,39 ; x1
		push ax
		mov ax,8 ; y1
		add ax,cx
		push ax
		mov ax, 1 ; width
		push ax
    	mov ax,9 ; y2
		add ax,cx
		push ax
		call printblock

		add cx,2
		cmp cx,8
		jne rd
	
	mov cx,0
	rd1:
		mov ax,0x0fdb ; color
		push ax
		mov ax,25 ; x1
		add ax,cx
		push ax
		mov ax,10 ; y1
		push ax
		mov ax, 1 ; width
		push ax
    	mov ax,11 ; y2
		push ax
		call printblock

		add cx,2
		cmp cx,32
		jne rd1
	
	mov cx,0
	rd2:
		mov ax,0x0fdb ; color
		push ax
		mov ax,24 ; x1
		add ax,cx
		push ax
		mov ax,11 ; y1
		push ax
		mov ax, 1 ; width
		push ax
    	mov ax,12 ; y2
		push ax
		call printblock

		add cx,2
		cmp cx,34
		jne rd2
	
	ret
; speed-----------------------------------------------   
speed:
	mov ax,11 ; x-position
	push ax
	mov ax,16 ; y-position
	push ax
	mov ax,0x0c ; color
	push ax
	mov ax, speed000 ; text
	push ax
	push word [speed000l] ; text length
	call printtext
	ret
; RPM-------------------------------------------------  
rpm:
	mov ax,0x0720 ; color
	push ax
	mov ax,34 ; x1
	push ax
	mov ax,18 ; y1
	push ax
	mov ax, 12 ; width
	push ax
    mov ax,23 ; y2
	push ax
	call printblock

	mov ax,34 ; x-position
	push ax
	mov ax,18 ; y-position
	push ax
	mov ax,0x0e ; color
	push ax
	mov ax, RPM1 ; text
	push ax
	push word [RPM1l] ; text length
	call printtext

	mov ax,34 ; x-position
	push ax
	mov ax,20 ; y-position
	push ax
	mov ax,0x0e ; color
	push ax
	mov ax, RPM2 ; text
	push ax
	push word [RPM2l] ; text length
	call printtext

	mov ax,34 ; x-position
	push ax
	mov ax,22 ; y-position
	push ax
	mov ax,0x0e ; color
	push ax
	mov ax, RPM3 ; text
	push ax
	push word [RPM3l] ; text length
	call printtext

	mov ax,37 ; x-position
	push ax
	mov ax,21 ; y-position
	push ax
	mov ax,0x0f ; color
	push ax
	mov ax, rpmtext ; text
	push ax
	push word [rpmtextl] ; text length
	call printtext

	mov ax,0x2ac1 ; color
	push ax
	mov ax,39 ; x1
	push ax
	mov ax,19 ; y1
	push ax
	mov ax, 1 ; width
	push ax
    mov ax,21 ; y2
	push ax
	call printblock

	ret
; OILTEMP---------------------------------------------   
oiltemp:
	mov ax,0x0720 ; color
	push ax
	mov ax,14 ; x1
	push ax
	mov ax,20 ; y1
	push ax
	mov ax, 7 ; width
	push ax
    mov ax,23 ; y2
	push ax
	call printblock

	mov ax,15 ; x-position
	push ax
	mov ax,22 ; y-position
	push ax
	mov ax,0x0f ; color
	push ax
	mov ax, oiltext ; text
	push ax
	push word [oiltextl] ; text length
	call printtext

	mov ax,0x2ac1 ; color
	push ax
	mov ax,17 ; x1
	push ax
	mov ax,21 ; y1
	push ax
	mov ax, 1 ; width
	push ax
    mov ax,22 ; y2
	push ax
	call printblock

	mov ax,0x0720 ; color
	push ax
	mov ax,59 ; x1
	push ax
	mov ax,20 ; y1
	push ax
	mov ax, 7 ; width
	push ax
    mov ax,23 ; y2
	push ax
	call printblock

	mov ax,59 ; x-position
	push ax
	mov ax,22 ; y-position
	push ax
	mov ax,0x0f ; color
	push ax
	mov ax, temptext ; text
	push ax
	push word [temptextl] ; text length
	call printtext

	mov ax,0x2ac1 ; color
	push ax
	mov ax,62 ; x1
	push ax
	mov ax,21 ; y1
	push ax
	mov ax, 1 ; width
	push ax
    mov ax,22 ; y2
	push ax
	call printblock
	
	ret

; gearfire----------------------------------------------- 
gearfire: 
	mov ax,0x07db ; color
	push ax
	mov ax,70 ; x1
	push ax
	mov ax,19 ; y1
	push ax
	mov ax, 10 ; width
	push ax
    mov ax,25 ; y2
	push ax
	call printblock

	mov cx,0
	gf1:
		mov ax,0x08db ; color
		push ax
		mov ax,72 ; x1
		add ax,cx
		push ax
		mov ax,20 ; y1
		push ax
		mov ax, 1 ; width
		push ax
    	mov ax,24 ; y2
		push ax
		call printblock
		add cx,3
		cmp cx,9
		jne gf1

	mov ax,0x08db ; color
	push ax
	mov ax,73 ; x1
	push ax
	mov ax,22 ; y1
	push ax
	mov ax, 6 ; width
	push ax
    mov ax,23 ; y2
	push ax
	call printblock

	mov ax,0x0720 ; color
	push ax
	mov ax,70 ; x1
	push ax
	mov ax,19 ; y1
	push ax
	mov ax, 4 ; width
	push ax
    mov ax,21 ; y2
	push ax
	call printblock

	mov ax,8 ; x-position
	push ax
	mov ax,23 ; y-position
	push ax
	mov ax,0x0e ; color
	push ax
	mov ax, firetext ; text
	push ax
	push word [firetextl] ; text length
	call printtext

	mov ax,72 ; x-position
	push ax
	mov ax,24 ; y-position
	push ax
	mov ax,0x7e ; color
	push ax
	mov ax, geartext ; text
	push ax
	push word [geartextl] ; text length
	call printtext

	mov ax,0x6efe ; color
	push ax
	mov ax,10 ; x1
	push ax
	mov ax,22 ; y1
	push ax
	mov ax, 1 ; width
	push ax
    mov ax,23 ; y2
	push ax
	call printblock

	mov ax,0x6efe ; color
	push ax
	mov ax,10 ; x1
	push ax
	mov ax,22 ; y1
	push ax
	mov ax, 1 ; width
	push ax
    mov ax,23 ; y2
	push ax
	call printblock

	ret
; Board-----------------------------------------------  
board:
	mov ax,0x08db ; color
	push ax
	mov ax,0 ; x1
	push ax
	mov ax,16 ; y1
	push ax
	mov ax, 80 ; width
	push ax
    mov ax,25 ; y2
	push ax
	call printblock

	mov ax,0x07db ; color
	push ax
	mov ax,0 ; x1
	push ax
	mov ax,16 ; y1
	push ax
	mov ax, 80 ; width
	push ax
    mov ax,17 ; y2
	push ax
	call printblock

	call speed
	call rpm
	call oiltemp
	call wheel
	call gearfire

	ret

; Wheel-----------------------------------------------    
wheel:
	mov cx,0
	wh1:
		mov ax,0x0720 ; color
		push ax
		mov ax,35 ; x1
		shl cx,2
		sub ax,cx
		push ax
		shr cx,2
		mov ax,15 ; y1
		add ax,cx
		push ax
		mov ax, 5 ; width
		push ax
    	mov ax,16 ; y2
		add ax,cx
		push ax
		call printblock

		mov ax,0x0720 ; color
		push ax
		mov ax,40 ; x1
		shl cx,2
		add ax,cx
		push ax
		shr cx,2
		mov ax,15 ; y1
		add ax,cx
		push ax
		mov ax, 5 ; width
		push ax
    	mov ax,16 ; y2
		add ax,cx
		push ax
		call printblock

		add cx,1
		cmp cx,3
		jne wh1

	mov cx,0
	wh2:
		mov ax,0x0720 ; color
		push ax
		mov ax,27 ; x1
		sub ax,cx
		push ax
		mov ax,18 ; y1
		add ax,cx
		push ax
		mov ax,1 ; width
		push ax
    	mov ax,20 ; y2
		add ax,cx
		push ax
		call printblock

		mov ax,0x0720 ; color
		push ax
		mov ax,52 ; x1
		add ax,cx
		push ax
		mov ax,18 ; y1
		add ax,cx
		push ax
		mov ax, 1 ; width
		push ax
    	mov ax,20 ; y2
		add ax,cx
		push ax
		call printblock

		add cx,1
		cmp cx,3
		jne wh2
	mov cx,0
	wh3:
		mov ax,0x0720 ; color
		push ax
		mov ax,25 ; x1
		push ax
		mov ax,22 ; y1
		add ax,cx
		push ax
		mov ax,1 ; width
		push ax
    	mov ax,23 ; y2
		add ax,cx
		push ax
		call printblock

		mov ax,0x0720 ; color
		push ax
		mov ax,54 ; x1
		push ax
		mov ax,22 ; y1
		add ax,cx
		push ax
		mov ax, 1 ; width
		push ax
    	mov ax,23 ; y2
		add ax,cx
		push ax
		call printblock

		add cx,1
		cmp cx,2
		jne wh3

	mov ax,0x0720 ; color
	push ax
	mov ax,25 ; x1
	push ax
	mov ax,24 ; y1
	push ax
	mov ax, 30 ; width
	push ax
    mov ax,25 ; y2
	push ax
	call printblock

	mov ax,35 ; x-position
	push ax
	mov ax,24 ; y-position
	push ax
	mov ax,0x70 ; color
	push ax
	mov ax, wheel1 ; text
	push ax
	push word [wheel1l] ; text length
	call printtext




	ret

; Stands----------------------------------------------
stands:
	mov cx,0
	sta:
		mov ax,0x07db ; color
		push ax
		mov ax,2 ; x1
		add ax,cx
		push ax
		mov ax,3 ; y1
		push ax
		mov ax, 3 ; width
		push ax
    	mov ax,13 ; y2
		push ax
		call printblock
		add cx,70
		cmp cx,140
		jne sta
	mov ax,0x07db ; color
	push ax
	mov ax,2 ; x1
	push ax
	mov ax,0 ; y1
	push ax
	mov ax, 78 ; width
	push ax
    mov ax,1 ; y2
	push ax
	call printblock

	mov ax,33 ; x-position
	push ax
	mov ax,0 ; y-position
	push ax
	mov ax,0x70 ; color
	push ax
	mov ax, starttext ; text
	push ax
	push word [starttextl] ; text length
	call printtext
	
	ret
; Stadium---------------------------------------------
stadium:

	mov ax,0x4cfe ; color
	push ax
	mov ax,20 ; x1
	push ax
	mov ax,5 ; y1
	push ax
	mov ax, 40 ; width
	push ax
    mov ax,7 ; y2
	push ax
	call printblock
	mov ax,0x4cfe ; color
	push ax
	mov ax,25 ; x1
	push ax
	mov ax,3 ; y1
	push ax
	mov ax, 30 ; width
	push ax
    mov ax,5 ; y2
	push ax
	call printblock

	mov ax,0x07f4 ; color
	push ax
	mov ax,21 ; x1
	push ax
	mov ax,6 ; y1
	push ax
	mov ax, 38 ; width
	push ax
    mov ax,7 ; y2
	push ax
	call printblock
	mov ax,0x07f4 ; color
	push ax
	mov ax,26 ; x1
	push ax
	mov ax,4 ; y1
	push ax
	mov ax, 28 ; width
	push ax
    mov ax,5 ; y2
	push ax
	call printblock

	mov cx,0
	stad:
		mov ax,0x4cfe ; color
		push ax
		mov ax,27 ; x1
		add ax,cx
		push ax
		mov ax,2 ; y1
		push ax
		mov ax, 1 ; width
		push ax
    	mov ax,3 ; y2
		push ax
		call printblock
		add cx,5
		cmp cx,30
		jne stad

	mov ax,0x4cfe ; color
	push ax
	mov ax,5 ; x1
	push ax
	mov ax,7 ; y1
	push ax
	mov ax, 70 ; width
	push ax
    mov ax,8 ; y2
	push ax
	call printblock

	call stands
	ret
; Start-----------------------------------------------
start:

	call clrscr
	call sky
	call road
	call grass
	call board
	call stadium
	call racelights
	call timer
	
    
	
	
	
	mov ah,0x1
	int 21h
	
	mov ax,0x4c00
	int 21h

