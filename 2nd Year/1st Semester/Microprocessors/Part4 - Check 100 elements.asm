; multi-segment executable file template.

data segment
    ; add your data here 
    array db 10 dup (1,2,3,4,5,86,7,8,109,8,160,6,5,23,100) ; array with 15 elements 
    elements EQU 100 ; constant 'elements' with value 15 
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
    mov bx, 0 ; define 'bx' value as 0
    
BACK_TO_ARRAY:
    mov al, array[bx] ; move 'array[bx]' value to 'al'
    mov cx, bx        ; move 'bx' value to 'cx'
    
INCREMENT:
    inc bx            ; increment 'bx'
    cmp bx,elements   ; compare 'bx' value with 'elements'
    jg FINAL          ; if 'bx' = 'elements', goes to label 'FINAL'
    cmp al, array[bx] ; compare 'al' value with 'array[bx]'
    ja INCREMENT      ; if 'al' is greater, it will jump to label 'INCREMENT'
    jb BACK_TO_ARRAY  ; if 'array[bx]' is greater, it will jump to label 'BACK_TO_ARRAY' 
    
FINAL:
    mov Res, cl       ; move 'cl' value to 'Res'
    
    
           
    ; exit to operating system
    mov ax, 4c00h 
    int 21h    
ends

end start ; set entry point and stop the assembler.