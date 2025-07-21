[org 0x0100]

jmp start

s: dw 11
sum: dw 0

pyramid:
    add [sum], ax

l1:
    dec ax
    add [sum], ax
    add [sum], ax
    cmp ax,0
    jne l1
    dec cx
    mov ax, cx
    cmp cx,0
    jne pyramid

    
    ret
    

start:
    mov ax, [s]
    mov cx, [s]

    call  pyramid

    mov dx, [sum]

mov ax, 0x4c00 
int 0x21