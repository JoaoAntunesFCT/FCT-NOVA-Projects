; multi-segment executable file template.

data segment
    ; add your data here 
    Num1 dw 150  ; variable 'Num1' defined with value 150
    Num2 dw 100  ; variable 'Num2' defined with value 100
    res dd ?     ; array with undefined size

ends

stack segment
    dw   128  dup(0)
ends

code segment
start:
; set segment registers:
    mov ax, data
    mov ds, ax
    mov es, ax

    ; add your code here
    mov ax, Num1  ; moves to 'ax' the value in 'Num1'
    mov bx, Num2  ; moves to 'bx' the value in 'Num2'
    call sum      ; evoques the 'sum' function
    mov res[0], ax
    mov res[1], dx
    jmp FINAL
    
    sum proc      
    mov dx, 0     ; moves to 'dx' the value '0'
    add ax, bx    ; adds to 'ax' the value on 'bx'
    jnc NotCarry  ; if carry does happen, it will just continue
    inc dx        ; increments the value of 'dx'
    
NotCarry:
    RET
    
FINAL:
    ; exit to operating system
    mov ax, 4c00h 
    int 21h    
ends

end start ; set entry point and stop the assembler.
