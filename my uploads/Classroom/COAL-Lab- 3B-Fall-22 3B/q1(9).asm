[org 0x0100]

mov ax, 0x1254; zf=cf=sf=of=0
mov bx, 0x0FFF; zf=cf=sf=of=0
add ax, 0xEDAB; zf=cf=of=0 sf=1
add ax, bx;     zf=sf=of=0 cf=1
add bx, 0xF001; sf=of=0 zf=cf=1


mov ax, 0x4c00
int 0x21

