; multi-segment executable file template.

data segment
   titulo db "   Bem vindo ao Game of Life     ", 0
   opcao1 db "       Jogar                 ", 0
   opcao2 db "      Carregar              ", 0
   opcao3 db "       Guardar               ", 0
   opcao4 db "        Top5                  ", 0
   opcao5 db "      Creditos              ", 0
   opcao6 db "        Sair                  ", 0
   inscricao db " Insere o teu nome: "
   espaco db 20 dup(0)
   nomejogador db ?  
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
    
    xor ax, ax
    call ModoVideo
    call Menu
    call SelecionarOpcao
    
        cmp cx, 1
        jne Comp2
        call Jogar
    
    Comp2:
        cmp cx, 2
        jne Comp3
        call Carregar
    
    Comp3:
        cmp cx, 3
        jne Comp4
        call Guardar
        
    Comp4:
        cmp cx, 4
        jne Comp5:
        call Top5
        
    Comp5:
        cmp cx, 5
        jne Comp6:
        call Creditos
        
    Comp6:
        cmp cx, 6
        jne Final
        call Sair    
    
    Final:
    mov ax, 4c00h ; exit to operating system.
    int 21h    
ends


;***************************************
;***************************************
; Ativa o modo de video       
; Parametros: ah-Modo de video
ModoVideo proc
    push ax
    mov ah, 00
    int 10h
    pop ax
    ret
ModoVideo endp


;***************************************
;***************************************
; Apresenta o menu do jogo
Menu proc
    push bp
    mov dl, 5          ;Coluna de inicio
    mov dh, 1           ;Linha de inicio
    
    ;Titulo
    lea bp, titulo
    call EscreveTituloMenu
    add dl, 5
    add dh, 4
    
    
    ;Primeiro botao
    lea bp, opcao1
    call EscreveString
    add dh, 3           ;Espaco para o prox
                        ;botao
    ;Segundo botao
    lea bp, opcao2
    call EscreveString
    add dh, 3
    
    ;Terceiro botao
    lea bp, opcao3
    call EscreveString
    add dh, 3
    
    ;Quarto botao
    lea bp, opcao4
    call EscreveString
    add dh, 3
    
    ;Quinto botao
    lea bp, opcao5
    call EscreveString
    add dh, 3
    
    ;Sexto botao
    lea bp, opcao6
    call EscreveString
    
    pop bp
    ret                   
Menu endp


;***************************************
;***************************************
; Escreve o titulo dojogo
; Parametros: String, Coordenadas do 
;inicio da String
EscreveTituloMenu proc
    mov al, 1
    mov bh, 0
    mov bl, 02eh
    mov cx, 30
    mov ah, 13h
    int 10h
    ret
EscreveTituloMenu endp 


;***************************************
;***************************************
; Escreve uma string no menu do jogo
; Parametros: String, Coordenadas do 
;inicio da String
EscreveString proc
    mov al, 1
    mov bh, 0
    mov bl, 04eh     ;cor das letras e do fundo
    mov cx, 20       ;comprimento da linha branca
    mov ah, 13h
    int 10h
    ret
EscreveString endp


;***************************************
;***************************************
; Faz um loop infinito ate o utilizador
;selecionar um dos espacos ou fora
SelecionarOpcao proc
    Repete:
    mov ax, 0
    int 33h        ;int do rato(?)
    cmp ax, 0FFFFh ;o q e isto?
    jne Erro
    mov ax, 3
    int 33h
    cmp bx, 1 
    jne Repete
        cmp cx, 80   ;fora esquerda
        jle Repete
        cmp cx, 240  ;fora direita
        jg Repete
        cmp dx, 40   ;fora cima
        jle Repete
        cmp dx, 168  ;fora baixo
        jg Repete
        cmp dx, 48 
        jle Op1     
        cmp dx, 64
        jle Repete
        cmp dx,72 
        jle Op2
        cmp dx, 88
        jle Repete
        cmp dx, 96
        jle Op3
        cmp dx, 112
        jle Repete
        cmp dx, 120
        jle Op4
        cmp dx, 136
        jle Repete
        cmp dx, 144
        jle Op5
        cmp dx, 160
        jle Repete
        cmp dx, 168
        jle Op6
    
        Erro:
            mov cx, 0
            jmp Fim
        Op1:
            mov cx, 1
            jmp Fim
        Op2:
            mov cx, 2
            jmp Fim
        Op3:
            mov cx, 3
            jmp Fim
        Op4:
            mov cx, 4
            jmp Fim
        Op5:
            mov cx, 5
            jmp Fim
        Op6:
            mov cx, 6
            jmp Fim
            
        Fim:
            ret
SelecionarOpcao endp


;***************************************
;***************************************
; FUNCAO JOGAR-MUDAR ESTA PARTE
Jogar proc
    call LimpaEcra
    mov dl, 10          ;Coluna
    mov dh, 6           ;Linha
    mov cx, 20
    
    lea bp, espaco
    call EscreveString
    inc dh 
    lea bp, inscricao
    call EscreveString
    inc dh
    lea bp, espaco
    call EscreveString
    mov ah, 2           ;por o cursor no sitio
    int 10h
    call LerString
    ;depois de testar, apagar
    ;fazr aqui um printf do nome
    ;fzr antes mais uma linha vermelha
    
Jogar endp


;***************************************
;***************************************
; FUNCAO CARREGAR-MUDAR ESTA PARTE
Carregar proc
    call LimpaEcra    
Carregar endp


;***************************************
;***************************************
; FUNCAO GUARDAR-MUDAR ESTA PARTE
Guardar proc
    call LimpaEcra    
Guardar endp


;***************************************
;***************************************
; FUNCAO TOP5-MUDAR ESTA PARTE
Top5 proc
    call LimpaEcra    
Top5 endp


;***************************************
;***************************************
; FUNCAO CREDITOS-MUDAR ESTA PARTE
Creditos proc
    call LimpaEcra    
Creditos endp


;***************************************
;***************************************
; FUNCAO SAIR-MUDAR ESTA PARTE
Sair proc
    call LimpaEcra    
Sair endp


;***************************************
;***************************************
; Limpa o ecra
LimpaEcra proc
    push ax
        
    mov ah, 07h
    xor bh, bh
    xor al, al
    xor cx, cx ;
    mov dh, 25 ;Coordenadas dos cantos
    mov dl, 40 ;
    int 10h
         
    pop ax
    ret 
LimpaEcra endp 


;***************************************
;***************************************
; Le uma string de tamanho variavel
LerString proc
   mov di, offset nomejogador
   Ler: call LerChar
        mov [di], al
        inc di
        cmp al, 0dh
        je FimLeitura
        jmp Ler
        FimLeitura: mov [di], 0ah
        ret 
LerString endp

LerChar proc
    mov ah, 01h
    int 21h
    ret
LerChar endp


end start ; set entry point and stop the assembler.


;**********OBSERVACOES NAO VISIVEIS**********
;o printf dos menus nao esta bom, imprime as cenas todas q estao a frente da string