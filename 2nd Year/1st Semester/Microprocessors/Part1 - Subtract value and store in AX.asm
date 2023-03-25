; multi-segment executable file template.

data segment
    ; add your data here 
    Num1 dw 3 ;variable 'Num1' defined with value 3
    Num2 dw 8 ;variable 'Num2' defined with value 8
    
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
    mov ax, Num1  ; moves to 'ax' the value of 'Num1'
    mov bx, Num2  ; moves to 'bx' the value of 'Num2'
    call subtraction
      
    ; exit to operating system
    mov ax, 4c00h
    int 21h
    
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    ;function SUBTRACTION: Subtracts 'bx' value to 'ax' value, storing the value in 'ax'
    ;input: ax, bx  
    ;destroy: ----
    ;output: ax  
    ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    subtraction PROC
    sub ax, bx
    RET 
        
ends

end start ; set entry point and stop the assembler.
