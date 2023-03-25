; multi-segment executable file template.

data segment
    num1 db ?
    
    
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
    
    call read
    mov num1, al
          
    mov ax, 4c00h ; exit to operating system.
    int 21h 
    
;*****************************************************************
; read - (....)
; description - (....)
; input - (....)
; output - (......)
; destroy - (......)
;*****************************************************************
readfunc proc
    mov bl, 0
    mov ah, 0
    mov ch, 10

    CYCLE:
    call readc
    cmp al, 0dh
    je FINAL
    cmp al, '0'
    jl ERRORDETECTED
    cmp al, '9'
    jg ERRORDETECTED
    sub al, '0'
    mov cl, al
    mov al, bl
    mul ch 
    jc ERRORDETECTED
    mov bl, al
    mov al, cl
    add bl, al
    jnc CYCLE
    
    ERRORDETECTED:
    mov al, -1
    ret
    
    FINAL:
    mov al, bl
    ret 
    
readfunc endp 

;*****************************************************************
; printstr - (....)
; description - (....)
; input - (....)
; output - (......)
; destroy - (......)
;*****************************************************************    
printstr proc
    
    PRINT:
    mov al, byte ptr[si]
    or al, al
    jz ENDPRINT
    call printc
    inc si
    jmp PRINT
    
    ENDPRINT:
    ret
printstr endp

;*****************************************************************
; printc - (....)
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

;*****************************************************************
; readstr - (....)
; description - (....)
; input - (....)
; output - (......)
; destroy - (......)
;*****************************************************************         
readstr proc
    
    READ:
    call readc
    mov [di], al
    inc di
    cmp al,0dh
    je ENDREAD
    jmp READ
    
    ENDREAD:
    mov [di], 0ah
    ret
readstr endp

;*****************************************************************
; readc - (....)
; description - (....)
; input - (....)
; output - (......)
; destroy - (......)
;*****************************************************************    
readc proc
    mov ah, 01h
    int 21h
    ret
readc endp

;*****************************************************************
; wstrcap - (....)
; description - (....)
; input - (....)
; output - (......)
; destroy - (......)
;*****************************************************************    
wstrcap proc
        
        PRINTC: 
        mov al,byte ptr [si]
        cmp al, 0dh
        je ENDPC
        cmp al,'a'
        jl NOTCAP
        sub al, 20h
        NOTCAP:
        call printc
        inc si
        jmp printc
        
        ENDPC: 
        ret
wstrcap endp

ends

end start ; set entry point and stop the assembler.
