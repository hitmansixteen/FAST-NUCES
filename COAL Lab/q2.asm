[org 0x0100]

mov ax, 0
mov cx,[n1]

l1:
add ax,[n1]
sub cx, 1
jne l1




mov ax, 0x4c00
int 0x21

n1: dw 4



