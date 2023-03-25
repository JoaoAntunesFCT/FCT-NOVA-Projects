; multi-segment executable file template.

data segment
    size dw 10
    sizeresult dw 7
    NumeroElementosTabela db 3
    Tabela1 db "Bola      ","Salto     ","Futebol   "
    Tabela2 db "Bola      ","Golo      ","Futebol   "
    TabelaDeResultados db "True  ","False "
    enter db 0dh, 0ah, 0
    
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
    
    cld
    lea si, Tabela1
    lea di, Tabela2
    mov ax, size
    
    mov dl, NumeroElementosTabela
    
    call compare
    call printresult 
          
    mov ax, 4c00h ; exit to operating system.
    int 21h 
    
;*****************************************************************
; compare -  Compare the words on the tables, pointed by di and si
; description - Stores the values in the array pointed by bx
; input - ax: size of the words || dl - number of words in each table
; output - (......)
; destroy - (......)
;*****************************************************************
compare proc
    push dx
    push cx
    push bx
    xor dh, dh
    ; cycle for each pair of words (checks char by char)
    Cycle:
        mov cx, ax
        repe cmpsb        ; repe - repetes cx while  ZF=1 || cmpsb - compare bytes pointed by si and di
        jnz Different     ; jump if not zero (if the characters are different, skips to next pair of words)
        mov [bx], 1       ; sets [bx] value to '1'
        jmp Verify
    ; if exists an different char in the string
    Different:           
        add si, cx  ; adds cx value to si
        add di, cx  ; adds cx value to si
        mov [bx],0  ; sets [bx] value to '0'
    ; checks if it was the last pair of words
    Verify:        
        inc bx      ; increments 'bx' value
        inc dh     ; increments 'dh' value
        cmp dh, dl  ; checks if it was the last pair of words
        jne Cycle   ; if not equal, it goes back to cycle to check the next pair of words
    pop bx
    pop cx
    pop dx
    ret
compare endp 

;*****************************************************************
; printresult - prints the result of each pair of words that were compared
; description - (....)
; input - bx - pointer for the results || dl - number of words in each table
; output - (......)
; destroy - (......)
;*****************************************************************    
printresult proc 
    push bx
    push si
    push dx 
    
    NextResult:
        lea si, TabelaDeResultados  
        cmp [bx], 1 ; that means that bx was positive for both words being equal
        jne NotEqual
        jmp PrintFinalTable
        
    NotEqual:
        add si, sizeresult
        
    PrintFinalTable: 
        call printstr
        lea si, enter
        call printstr
        inc bx
        dec dl
        cmp dl, 0
        je EndPrintResult
        jmp NextResult 
        
    EndPrintResult:
        pop dx
        pop si
        pop bx
        ret
        
printresult endp 
;*****************************************************************
; printstr - (....)
; description - (....)
; input - (....)
; output - (......)
; destroy - (......)
;*****************************************************************    
printstr proc 
    push ax
    Print:
        mov al, byte ptr [si] 
        or al, al
        jz EndPrint      
        call printcfunc
        inc si
        jmp Print 
    EndPrint:
        pop ax
        ret   
printstr endp
;*****************************************************************
; printcfunc - (....)
; description - (....)
; input - (....)
; output - (......)
; destroy - (......)
;*****************************************************************         
printcfunc proc
    push ax
    push dx
    mov ah, 02h
    mov dl, al
    int 21h
    pop dx
    pop ax
    ret 
printcfunc endp

ends

end start ; set entry point and stop the assembler.
