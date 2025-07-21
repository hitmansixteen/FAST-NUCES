[org 0x0100]

mov ax,4
mov dx,ax
mov bx,dx
mov cx,bx
sub cx,2

l1:

mov bx,cx

l2:

add dx,ax
sub bx,1
jne l2

mov ax,dx
sub cx,1
jne l1




mov ax,0x4c00
int 0x21