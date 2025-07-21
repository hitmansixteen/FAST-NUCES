	[org 0x0100] ;
	
	mov ax, 10;
	mov bx, 20;
	mov cx, 30;
	
	mov [temp],bx;
	mov bx,ax;
	mov ax,cx;
	mov cx,[temp];
	mov [temp],bx;
	mov bx,ax;
	mov ax,cx;
	mov cx,[temp];
	
	
	mov ax,0x4c00;
	int 0x21
	
temp: dw 0
