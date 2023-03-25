; multi-segment executable file template.

data segment
    op1 db ?
    op2 db ?
    res dw ?
    symb db ?
    enter db 0dh, 0ah, 0
    welcome db "Bem vindo/a a nossa calculadora!", 0
    operator db "Indique qual o operador: ", 0
    stnum db "Introduza o primeiro operando: ", 0
    ndnum db "Introduza o segundo operando: ", 0
    resultp1 db "O resultado de ", 0
    resultp2 db " e: ", 0
    error1 db "Operando ", 0
    error2 db " invalido.", 0
    operror db "Operador invalido.", 0
    thk db "Obrigado.", 0      
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
    
    ;Welcome
    mov si, offset welcome
    call printstr
    mov si, offset enter
    call printstr
    
    ;Read the OP
    RSYMB:
    mov si, offset operator
    call printstr
    call rsymbol
    cmp al, -1
    jne SYMBISOK
    mov si, offset enter
    call printstr
    mov si, offset operror
    call printstr
    mov si, offset enter
    call printstr
    jmp RSYMB
    
    SYMBISOK:
    mov symb, al
    mov si, offset enter
    call printstr
    
    ;Read the operands
    
    READOP1:
    mov si, offset stnum
    call printstr
    mov cl, 1
    call readop
    cmp al, -1
    jne OKOP1
    call operrorfunc
    jmp READOP1
    
    OKOP1:
    mov op1, al
    mov si, offset enter
    call printstr
    
    READOP2:
    mov si, offset ndnum
    call printstr
    mov cl, 2
    call readop
    cmp al, -1
    jne OKOP2
    call operrorfunc
    jmp READOP2
    
    OKOP2:
    mov op2, al
    mov si, offset enter
    call printstr
    cmp op1, -1
    je operrorfunc
    cmp op2, -1
    je operrorfunc
    
    ;Operands
    mov al, op1
    mov bl, op2
    mov ah, 0
    mov bh, 0
    cmp symb, 2bh
    jne NOTSUM
    call sum
    jmp OPEND
    
    NOTSUM:
    cmp symb, 2dh
    jne NOTSUBTRACT
    call subtraction
    jmp OPEND
    
    NOTSUBTRACT:
    cmp symb, 2ah
    jne NOTMULT
    call multiplication
    jmp OPEND
    
    NOTMULT:
    call division 
    
    OPEND:
    mov res, ax
    
    ;Write down result
    mov si, offset resultp1
    call printstr
    mov al, op1
    mov ah, 0
    call writefunc
    mov al, symb
    call printcfunc
    mov al, op2
    mov ah, 0 
    call writefunc
    mov si, offset resultp2
    call printstr
    mov ax, res
    call writefunc
    mov si, offset enter
    call printstr
    
    ;Shutdown Program
    mov si, offset thk
    call printstr

    mov ax, 4c00h ; exit to operating system.
    int 21h 
;*****************************************************************
; operrorfunc - (....)
; description - (....)
; input - (....)
; output - (......)
; destroy - (......)
;*****************************************************************
operrorfunc proc
    mov si, offset enter
    call printstr
    mov si, offset error1
    call printstr
    add cl, 48
    mov al, cl
    call printcfunc
    mov si, offset error2
    call printstr
    mov si, offset enter
    call printstr
    ret
operrorfunc endp
;*****************************************************************
; rsymbol - (....)
; description - (....)
; input - (....)
; output - (......)
; destroy - (......)
;*****************************************************************
rsymbol proc
    mov ah, 1
    int 21h
    cmp al, 2bh
    je JMPEND
    cmp al, 2dh
    je JMPEND
    cmp al, 2ah
    je jmpend
    cmp al, 5ch
    je JMPEND
    mov ax, -1 
    
    JMPEND:
    ret
rsymbol endp
;*****************************************************************
; readop - (....)
; description - (....)
; input - (....)
; output - (......)
; destroy - (......)
;*****************************************************************
readop proc
    mov dl, cl
    call readfunc
    cmp dl, 1
    jne NUM2
    mov op1, al
    ret
    
    NUM2:
    mov op2, al
    ret
readop endp    
;*****************************************************************
; readfunc - (....)
; description - (....)
; input - (....)
; output - (......)
; destroy - (......)
;*****************************************************************
readfunc proc
    mov bl, 0
    mov ah, 0
    mov ch, 10

    CYCLEREAD:
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
    jnc CYCLEREAD
    
    ERRORDETECTED:
    mov al, -1
    ret
    
    FINAL:
    mov al, bl
    ret     
readfunc endp 
;*****************************************************************
; writefunc - (....)
; description - (....)
; input - (....)
; output - (......)
; destroy - (......)
;*****************************************************************
writefunc proc
    mov bx, 10
    mov cx, 0
    
    SCANCYCLE:
    mov dx, 0
    div bx
    push dx
    inc cx
    cmp ax, 0
    jne SCANCYCLE
    
    WRITECYCLE:
    pop ax
    add ax, 48
    call printcfunc
    dec cx
    cmp cx, 0
    jnz WRITECYCLE
    ret
writefunc endp
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
    call printcfunc
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
     mov ah, 02h
     mov dl, al
     int 21h
     ret
printcfunc endp 

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
; multiplication - (....)
; description - (....)
; input - (....)
; output - (......)
; destroy - (......)
;*****************************************************************    
multiplication proc
    cmp ax, bx
    jnl OK
    xchg ax, bx
    
    OK:
    mov cx, bx
    mov bx, ax
    
    MULTICYCLE:
    call sum
    dec cx
    cmp cx, 1
    jne MULTICYCLE
    ret
multiplication endp
;*****************************************************************
; sum - (....)
; description - (....)
; input - (....)
; output - (......)
; destroy - (......)
;*****************************************************************    
sum proc
    add ax, bx
    jnc ENDSUM
    inc dx
    
    ENDSUM:
    ret
sum endp
;*****************************************************************
; division - (....)
; description - (....)
; input - (....)
; output - (......)
; destroy - (......)
;*****************************************************************    
division proc
    mov cx, -1
    
    CYCLEDIVISION:
    inc cx
    call subtraction
    cmp ax, 0
    jge CYCLEDIVISION
    mov ax, cx
    ret
division endp
;*****************************************************************
; subtraction - (....)
; description - (....)
; input - (....)
; output - (......)
; destroy - (......)
;*****************************************************************    
subtraction proc
    sub ax, bx
    ret
subtraction endp

ends

end start ; set entry point and stop the assembler.
