[org 0x0100]
jmp start

multiplication:
    mov ax,5294h
    mov bx,ax
    not bx
    mov [num],ax
    mov [num+2],bx
    mov cl, 16 
    mov [multiplicand],ax
    mov [multiplier], bx
    mov dx,[multiplier]

checkbit:
    shr dx,1 
    jnc skip
    mov ax,[multiplicand]
    add [result],ax
    mov ax,[multiplicand+2]
    adc [result+2],ax

skip:
    shl word [multiplicand],1
    rcl word [multiplicand+2],1
    dec cl
    jnz checkbit

    ret

addition:
    mov ax,[num]
    mov bx,[result]
    add ax,bx
    mov [f],ax
    mov ax,[num+2]
    mov bx,[result+2]
    adc ax,bx
    mov [f+2],ax

    ret

start:

    call multiplication
    
    call addition

    mov ax,0x4c00
    int 0x21

    f: dd 0
    num: dd 0
    multiplicand: dd 0
    multiplier: dw 0
    result: dd 0