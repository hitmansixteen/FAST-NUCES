[org 0x0100]

    mov ax, [array]
    mov bx, 0
    mov dx, 0
    mov cx, 12

l1: add ax, [array + bx]
    add bx, 2
    sub cx, 1
    jnz l1



mov ax, 0x4c00
int 21h

array: dw 111, 999, 888, 888, 11, 99, 88, 88, 1, 9, 8, 8
