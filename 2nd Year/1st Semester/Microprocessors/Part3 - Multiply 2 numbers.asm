; multi-segment executable file template.

data segment
    ; add your data here 
    Num1 dw 100  ; variable 'Num1' is defined with value 100
    Num2 dw 100  ; variable 'Num2' is defined with value 100
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
    mov ax, 0      ; moves to 'ax' the value 0
    mov bx, Num1   ; moves to 'bx' the value in 'Num1'
    mov cx, Num2   ; moves to 'cx' the value in 'Num2'
    mov dx, 0      ; moves to 'dx' the value 0
    call mult      ; calls the function 'mult'
    mov res[0], ax ; moves the 'ax' value to the first position of the array
    mov res[1], dx ; moves the 'dx' value to the second position of the array
    jmp FINAL      
    
FINAL:
    ; exit to operating system
    mov ax, 4c00h 
    int 21h 
    
mult PROC          ; function 'mult'
    cmp bx, Num2   ; compares the value in 'bx' with the one in 'Num2'
    jnb CYCLE
    mov bx, Num2   ; moves to 'bx' the value in 'Num2'
    mov cx, Num1   ; moves to 'cx' the value in 'Num1'
CYCLE:
    call sum       ; calls function 'sum'
    dec cx         ; decreases by one the number in 'cx'
    cmp cx, 0      ; compares the value in 'cx' with '0'
    jne CYCLE
    RET
    mult endp      ; end of function 'mult'
    
sum PROC           ; function 'sum'
    add ax, bx
    jnc ENDSUM
    inc dx
    
ENDSUM:
    RET
    
    sum endp
    
ends

end start ; set entry point and stop the assembler.
