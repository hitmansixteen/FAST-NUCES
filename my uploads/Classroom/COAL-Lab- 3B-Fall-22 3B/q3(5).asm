[org 0x0100]

mov bx,0
mov ax, 9
mov dx, [freq]

l1:
cmp ax, [array+bx]
je l2
add bx,2
cmp bx, 44
je end1
jne l1

l2: 
add dx, 1
add bx,2
cmp bx, 44
je end1
jne l1

end1:
mov [freq], dx

mov ax, 0x4c00
int 0x21

array: dw 1, 9, 9, 9, 8, 8, 8, 8, 8, 8, 1, 1, 9, 9, 8, 8, 8, 8, 1, 9, 8, 8
freq: dw 0 