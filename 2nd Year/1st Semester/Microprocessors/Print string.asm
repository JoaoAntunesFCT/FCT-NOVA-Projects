; multi-segment executable file template.

data segment
    ; add your data here!
    include emu8086.inc
    enter db 0dh, 0ah, 0
    strler db ?
ends

stack segment
    dw   128  dup(0)
ends

code segment
start:
    mov ax, data
    mov ds, ax
    mov es, ax
    mov di, offset strler
    call lerstring
    mov si, offset enter
    call printf
    mov si, offset strler
    call printf
    mov si, offset enter
    call printf
    mov si, offset strler
    call escreverstringCAPS
    mov ax,4c00h ; terminate program
    int 21h
    
;*****************************************************************
; printf - string output
; descricao: rotina que faz o output de uma string NULL terminated para o ecra
; input - si=deslocamento da string a escrever desde do inicio do segmento de dados
; output - nenhum
; destroi - al, si
;*****************************************************************
printf proc
L1:     mov al,byte ptr [si]
        or al,al
        jz fimprtstr
        call co
        inc si
        jmp L1
fimprtstr: ret
printf endp
    
;*****************************************************************
; co - caracter output
; descricao: rotina que faz o output de um caracter para o ecra
; input - al=caracter a escrever
; output - nenhum
; destroi - nada
;*****************************************************************
co proc
       push ax
       push dx
       mov ah,02H
       mov dl,al
       int 21H
       pop dx
       pop ax
       ret
co endp

;*****************************************************************
; lerstring - leitura da string
; descricao: rotina que faz a leitura da string introduzida
; input - nenhum
; output - nenhum
; destroi - nada
;*****************************************************************   
lerstring proc
       ler: call lercaracter ;chamada da funcao lercaracter
       mov [di], al          ;move para a posicao de memoria de di o valor em al
       inc di                ;incrementa o di
       cmp al, 0dh           ;comparar o valor em al com '0dh'
       je fimlerstring       ;se forem iguais, faz jump para o 'fimlerstring'
       jmp ler
       fimlerstring: mov [di], 0ah ;move para a posicao de memoria di o valor em 0ah
       ret            
lerstring endp
                     
;*****************************************************************
; lercaracter - leitura individual de cada caracter
; descricao: rotina que faz a leitura de cada caracter
; input - nenhum
; output - nenhum
; destroi - nada
;*****************************************************************    
lercaracter proc
       mov ah, 01h
       int 21h
       ret
lercaracter endp

;*****************************************************************
; escreverstringCAPS - escreve a string mas em CAPS
; descricao: rotina que faz o output de uma string (em CAPS) para o ecra 
; input - nenhum
; output - nenhum
; destroi - nada
;*****************************************************************    
escreverstringCAPS proc
       escreverc: mov al,byte ptr [si]
       cmp al, 0dh
       je fimescreverc
       cmp al, 61h
       jl noncaps
       sub al, 20h
       noncaps: call co
       inc si
       jmp escreverc
       fimescreverc: ret
escreverstringCAPS endp   

ends
end start ; set entry point and stop the assembler.
