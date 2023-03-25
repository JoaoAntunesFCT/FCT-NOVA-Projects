; multi-segment executable file template.

data segment
    ; add your data here
    NumA db 37 ; variable 'NumA' with value 37
    NumB db 29 ; variable 'Numb' with value 29
    res db ? ; variable 'Res' without value
    
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
    mov al, NumA ; move 'NumA' value to 'al'
    cmp al, NumB ; compare 'NumB' value with 'al'
    jg BIGGER    
    mov al, NumB ; compare 'NumB' value with 'al'
    
BIGGER:
    cmp al, Res  ; move 'Res' value to 'al'
    jg FINAL
    mov al, Res  ; compare 'Res' value with 'al'
FINAL:
    mov Res, al  ; move 'Res' value to 'al'
  
    ; exit to operating system
    mov ax, 4c00h
    int 21h    
ends

end start ; set entry point and stop the assembler
