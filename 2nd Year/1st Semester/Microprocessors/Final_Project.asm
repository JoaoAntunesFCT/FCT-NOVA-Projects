; multi-segment executable file template.

data segment
        ;Menu
   titulo db "   Bem vindo ao Game of Life     ", 0
   opcao1 db "        Jogar                 ", 0
   opcao2 db "      Carregar              ", 0
   opcao3 db "       Guardar               ", 0
   opcao4 db "        Top5                  ", 0
   opcao5 db "      Creditos              ", 0
   opcao6 db "        Sair                  ", 0
   espaco db 20 dup(0) ;20 espacos
        ;Jogo
   inscricao db " Insere o teu nome: "
   geracao db "GERACAO:                  "
   celulas db "CELULAS:                  "
   iniciar db " INICIAR                      "
   sairjogo db "SAIR                        "
   nr_geracao db 0
   nr_celulas db 0
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
    mov ah, 1
    int 21h             
    
    call Menu
    call SelecionarOpcaoMenu
    
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
    mov al, 12h
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
    call EscreveString30
    add dl, 5
    add dh, 4
    
    
    ;Primeiro botao
    lea bp, opcao1
    call EscreveString20
    add dh, 3           ;Espaco para o prox
                        ;botao
    ;Segundo botao
    lea bp, opcao2
    call EscreveString20
    add dh, 3 
    
    ;Terceiro botao
    lea bp, opcao3
    call EscreveString20
    add dh, 3 
        
    ;Quarto botao
    lea bp, opcao4
    call EscreveString20
    add dh, 3
    
    ;Quinto botao 
    lea bp, opcao5
    call EscreveString20
    add dh, 3
    
    ;Sexto botao
    lea bp, opcao6
    call EscreveString20_EXIT
    
    pop bp
    ret                   
Menu endp


;***************************************
;***************************************
; Escreve uma string dojogo
; Parametros: String, Coordenadas do 
;inicio da String
EscreveString30 proc
    mov al, 1
    mov bh, 0
    mov bl, 04fh
    mov cx, 30
    mov ah, 13h
    int 10h
    ret
EscreveString30 endp 

EscreveString20 proc
    mov al, 1
    mov bh, 0
    mov bl, 08fh     ;cor das letras e do fundo
    mov cx, 20       ;comprimento da linha branca
    mov ah, 13h
    int 10h
    ret
EscreveString20 endp

EscreveString20_EXIT proc
    mov al, 1
    mov bh, 0
    mov bl, 0Cfh     ;cor das letras e do fundo
    mov cx, 20       ;comprimento da linha branca
    mov ah, 13h
    int 10h
    ret
EscreveString20_EXIT endp 

EscreveString10 proc
    mov al, 1
    mov bh, 0
    mov bl, 01fh
    mov cx, 10
    mov ah, 13h
    int 10h
    ret
EscreveString10 endp 
                    
EscreveString5 proc
    mov al, 1
    mov bh, 0
    mov bl, 0c0h
    mov cx, 5
    mov ah, 13h
    int 10h
    ret
EscreveString5 endp 

;***************************************
;***************************************
; Faz um loop infinito ate o utilizador
;selecionar um dos espacos ou fora
SelecionarOpcaoMenu proc
    RepMenu:
    mov ax, 0
    int 33h        ;Servico BIOS para o rato acho eu
    cmp ax, 0FFFFh ;
    jne ErroMenu
    mov ax, 3      ;posicao e cliques do rato
    int 33h        ;reset do rato
    cmp bx, 1 
    jne RepMenu
        cmp cx, 158   ;fora esquerda
        jle RepMenu
        cmp cx, 1300  ;fora direita
        jg RepMenu
        cmp dx, 30   ;fora cima
        jle RepMenu
        cmp dx, 140  ;fora baixo
        jg RepMenu
        cmp dx, 48 
        jle Op1     
        cmp dx, 64
        jle RepMenu
        cmp dx,72 
        jle Op2
        cmp dx, 88
        jle RepMenu
        cmp dx, 96
        jle Op3
        cmp dx, 112
        jle RepMenu
        cmp dx, 120
        jle Op4
        cmp dx, 136
        jle RepMenu
        cmp dx, 144
        jle Op5
        cmp dx, 160
        jle RepMenu
        cmp dx, 168
        jle Op6
    
        ErroMenu:
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
SelecionarOpcaoMenu endp


;***************************************
;***************************************
; FUNCAO JOGAR-MUDAR ESTA PARTE
Jogar proc
    call LimpaEcra
    call InscricaoJogador
    call LimpaEcra
    
    ;meter isto numa funcao
    ;basicamente escreve o menu do jogo
    mov dl, 0
    mov dh, 0
    mov cx, 20
    
    lea bp, geracao
    call EscreveString30
    mov dl, 12
    lea bp, celulas
    call EscreveString20
    mov dl, 25
    lea bp, iniciar
    call EscreveString10
    mov dl, 35
    lea bp, sairjogo
    call EscreveString5
    
    
    
    ret
Jogar endp


;***************************************
;***************************************
; Inscreve o jogador e guarda o nome
InscricaoJogador proc
    mov dl, 10          ;Coluna
    mov dh, 6           ;Linha
    mov cx, 20     ;porque????????
    
    lea bp, espaco
    call EscreveString20
    inc dh 
    lea bp, inscricao
    call EscreveString20
    inc dh
    lea bp, espaco
    call EscreveString20
    mov ah, 2           ;por o cursor no sitio
    int 10h
    call LerJogador
    ret
InscricaoJogador endp


;***************************************
;***************************************    
; SelecionarJogar --NAO ACABADO--
;inclui: "iniciar", "sair" e os quadrados
SelecionarJogar proc
    RepJogar:
    mov ax, 0
    int 33h
    cmp ax, 0FFFFh
    jne ErroJogar
    mov ax, 3
    int 33h
    cmp bx, 1
    jne RepJogar
        ;fazer os butoes e testar
        ;com printf a seguir
        ErroJogar:
            mov cx, 0
            jmp Fim
    
    ret
SelecionarJogar endp


;***************************************
;***************************************
; FUNCAO CARREGAR-MUDAR ESTA PARTE
Carregar proc
    ;call LimpaEcra
    ret    
Carregar endp


;***************************************
;***************************************
; FUNCAO GUARDAR-MUDAR ESTA PARTE
Guardar proc
    ;call LimpaEcra
    ret    
Guardar endp


;***************************************
;***************************************
; FUNCAO TOP5-MUDAR ESTA PARTE
Top5 proc
    ;call LimpaEcra
    ret    
Top5 endp


;***************************************
;***************************************
; FUNCAO CREDITOS-MUDAR ESTA PARTE
Creditos proc
    ;call LimpaEcra
    ret    
Creditos endp


;***************************************
;***************************************
; FUNCAO SAIR-MUDAR ESTA PARTE
Sair proc
    ;call LimpaEcra
    ret    
Sair endp


;***************************************
;***************************************
; Limpa o ecra
LimpaEcra proc
    push ax
        
    mov ax, 12h
    int 10h
         
    pop ax
    ret 
LimpaEcra endp 


;***************************************
;***************************************
; Le uma string de tamanho variavel
LerJogador proc
   mov di, offset nomejogador
   Ler: call LerChar
        mov [di], al
        inc di
        cmp al, 0dh
        je FimLeitura
        jmp Ler
        FimLeitura: mov [di], 0ah
        ret 
LerJogador endp

LerChar proc
    mov ah, 01h
    int 21h
    ret
LerChar endp


end start ; set entry point and stop the assembler