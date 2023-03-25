; multi-segment executable file template

data segment
    ; add your data here
    NumA db 37 ;criada a variavel 'NumA' com o valor 37 
    NumB db 29 ;criada a variavel 'NumB' com o valor 29 
    Res db ? ;criada a variavel 'Res' sem valor
    
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
    mov al, NumA
    mov al, NumB
    mov Res, al        
    
    ; exit to operating system
    mov ax, 4c00h
    int 21h    
ends

end start ; set entry point and stop the assembler.
