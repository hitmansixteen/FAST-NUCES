	[org 0x0100] ;
	mov ax,[table];
	mov bx,[table+2];
	add ax, bx;
	mov bx, [table+4];
	add ax,bx;
	mov bx, [table+6];
	add ax,bx;
	mov bx, [table+8];
	add ax,bx;
 
	mov ax,0x4c00;
	int 0x21
	

table: dw 3, 6, 9, 12, 15