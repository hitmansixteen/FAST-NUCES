[org 0x0100]

mov ax, 5294h
mov cx,0
call func

mov ax, 0x4c00
int 21h
	
func:
	cmp ax,0
	je finish
	shr ax,1
	jnc func
	inc cx
	jmp func
finish:
	ret
	
	
	




	



	

	




