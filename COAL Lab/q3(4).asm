[org 0x0100]

mov ax, 200h
mov bx, 150h

mov ax, 50h
mov dx, 25h
mov [0x0250], ax
mov [0x0200], dx

mov bx, 0x0200
mov ax, [bx]; indirect addressing
mov cx, [0x0250]

mov ax, 0x4c00
int 21h

array: dw 1, 2, 7, 5, 10

