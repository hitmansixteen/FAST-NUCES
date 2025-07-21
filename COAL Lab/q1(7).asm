[org 0x0100]

mov ax, 25h
mov bx, 0
mov [temp], ax
mov ax, bx
mov bx, [temp]
mov cx, 0x270
mov ax, [array]
mov ax, [array+2]
mov ax, [array+4]

mov ax, 0x4c00
int 21h

array: dw 12, 25, 10
temp: dw 0