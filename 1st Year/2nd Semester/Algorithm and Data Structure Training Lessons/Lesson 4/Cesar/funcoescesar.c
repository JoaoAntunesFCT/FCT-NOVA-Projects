#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "cesar.h"

struct beto{

    int codigosecreto;
    int linhas;
    char mensagem_utilizador[MAXLEN];
    char mensagem_cifrada[MAXLEN];
};

cesar CriarCesar(char * str, int  code, int n_linhas){

    cesar z;

    z = (cesar) malloc(sizeof(struct beto));
    
    if (z == NULL){
        
        return NULL;
    }
    strcpy(z->mensagem_utilizador, str);
    z->linhas=n_linhas;
    z->codigosecreto = code;
    return z;
}
int DeslocaSize(unsigned numero){

    if(numero>=1000000000){
        return 10;
    }
    if(numero>=100000000){
        return 9;
    }
    if(numero>=10000000){
        return 8;
    }
    if(numero>=1000000){
        return 7;
    }
    if(numero>=100000){
        return 6;
    }
    if(numero>=10000){
        return 5;
    }
    if(numero>=1000){
        return 4;
    }
    if(numero>=100){
        return 3;
    }
    if(numero>=10){
        return 2;
    }
    return 1;
}

void Cifragem(cesar z){

    int i;
    int _codigo[10],tamanhoinicial,tamanhodesloca;

    tamanhodesloca=DeslocaSize(z->linhas);
    tamanhoinicial=tamanhodesloca;

    for(tamanhodesloca=tamanhoinicial-1;tamanhodesloca>=0;tamanhodesloca--){

        _codigo[tamanhodesloca]= z->codigosecreto%10;
        z->codigosecreto /=10;
    }
    tamanhodesloca=0;

    for(i=0;i<strlen(z->mensagem_utilizador);i++){

        if((z->mensagem_utilizador[i]>='a')&&(z->mensagem_utilizador[i]<='z')){

            z->mensagem_cifrada[i] = z->mensagem_utilizador[i] + _codigo[tamanhodesloca];
            if(z->mensagem_cifrada[i]>'z'){

                z->mensagem_cifrada[i] = z->mensagem_cifrada[i] - 26;
            }
        }
        else{

            z->mensagem_cifrada[i] = z->mensagem_utilizador[i];
        }
        tamanhodesloca++;
        if(tamanhodesloca==tamanhoinicial){

            tamanhodesloca=0;
        }
    }
}

char * MensagemCesariana(cesar z){
    return z->mensagem_cifrada;
}

void DeleteCesar(cesar z){
    free(z);
}

