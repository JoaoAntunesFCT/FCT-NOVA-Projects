; multi-segment executable file template.

data segment
    ; add your data here 
    array db 1,2,3,4,5,86,7,8,109,8,7,6,5,23,100 ; array with 15 elements 
    elements EQU 15 ; constant 'elements' with value 15 
    Res db ? ; variable 'Res' without value

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
    mov bx, 0         ; set 'bx' value to 0
    
BACK_TO_ARRAY:
    mov al, array[bx] ; 'al' will be getting the value of the array in the 'bx' position
    
INCREMENT:
    add bx, 1         ; increment the 'bx' value
    cmp bx, elements  ; compare 'bx' value with 'elements'
    jg FINAL          ; if they are the same, all the range has been checked and it goes to the final stage
    cmp al, array[bx] ; if not, it will compare the value of 'al' with the value on the array[bx]
    jg INCREMENT      ; if 'al' is greater, it will go back to label 'INCREMENT' 
    jl BACK_TO_ARRAY  ;if the value on array[bx] is greater, it will go back to label 'BACK_TO_ARRAY'
    
FINAL:
    mov Res, al ; stores 'al' value in the variable 'Res'
    
    
           
    ; exit to operating system
    mov ax, 4c00h 
    int 21h    
ends

end start ; set entry point and stop the assembler.
