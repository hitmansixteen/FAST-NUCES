[org 0x0100]
jmp start

oldisr: dd 0
global_x: dw 10
message: db 'lahore da pawa akhtar lawa',0
buffer: times 80 dw 0

scrollup: 
    push bp 
    mov bp,sp 
    push ax 
    push cx 
    push si 
    push di 
    push es 
    push ds 

    mov     ax, 0xb800  
    mov     ds, ax
    mov     si, 0
    mov     ax, cs
    mov     es, ax
    mov     di, buffer
    mov     cx, 80
    cld
    rep     movsw 

    mov ax, 80 
    mul byte [bp+4] 
    mov si, ax 
   
    shl si, 1 
    mov cx, 2000 
    sub cx, ax 
    mov ax, 0xb800 
    mov es, ax 
    mov ds, ax 
    xor di, di
    cld 
    rep movsw

    mov     ax, 0xb800      
    mov     es, ax
    mov     di, 3840
    mov     ax, cs
    mov     ds, ax
    mov     si, buffer
    mov     cx, 80

    cld
    rep     movsw 

    pop ds 
    pop es 
    pop di 
    pop si 
    pop cx 
    pop ax 
    pop bp 
    ret 2 

printstr: 
    push bp 
    mov bp, sp 
    push es 
    push ax 
    push cx 
    push si 
    push di 
    push ds 
    pop es 
    mov di, [bp+4] 
    mov cx, 0xffff 
    xor al, al 
    repne scasb  
    mov ax, 0xffff  
    sub ax, cx 
    dec ax 
    jz exit 
    mov cx, ax 
    mov ax, 0xb800 
    mov es, ax 
    mov al, 80 
    mul byte [bp+8] 
    add ax, [bp+10] 
    shl ax, 1 
    mov di,ax 
    mov si, [bp+4]
    mov ah, [bp+6] 
    cld 
    nextchar: lodsb 
    stosw 
    loop nextchar 
    exit: pop di 
    pop si 
    pop cx 
    pop ax 
    pop es 
    pop bp 
    ret 8 


 
; keyboard interrupt service routine 
kbisr: 
	push ax 
	push es 
	mov ax, 0xb800 
	mov es, ax 
	

    push 1
	call scrollup

	nomatch: 
		pop es 
		pop ax 
		jmp far [cs:oldisr] 



start:

	xor ax, ax 
	mov es, ax 
	mov ax, [es:8*4] 
	mov [oldisr], ax 
	mov ax, [es:8*4+2] 
	mov [oldisr+2], ax 

    push 30
    push 5
    push 0x07
    push message
    call printstr

	cli 
	mov word [es:8*4], kbisr
	mov [es:8*4+2], cs 
	sti 
	mov dx, start 
	add dx, 15 
	mov cl, 4 
	shr dx, cl 
	mov ax, 0x3100 
	int 0x21 