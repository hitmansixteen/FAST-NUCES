	[org 0x0100] ;
	mov ax,[table];
	
	add ax,[table+2] ;
	
	add ax,[table+4];
	
	add ax,[table+6];
	
	add ax,[table+8];
 
	mov ax,0x4c00;
	int 0x21
	

table: dw 3, 6, 9, 12, 15