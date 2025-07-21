[org 0x0100]

mov ax, [array]
mov [max], ax
mov bx, 0

l1:

add bx, 2
mov ax, [array + bx]
cmp ax, [max]
jg l2
cmp bx, 24
jne l1
je end1

l2:

mov [max], ax
cmp bx, 24
jne l1

end1:

mov ax, 0x4c00
int 0x21

array: dw 111, 999, 888, 888, 11, 99, 88, 88, 1, 9, 8, 8
max: dw 0