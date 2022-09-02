#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funcoescifra.h"

struct alfa{

    char frase_recebida[100];
    char frase_modificada[100];
    int codigo_recorrido;
};

char ConversaoCifra(char fraseescolhida[], int  codigo)
{
    char frase2_0[MAX]
    int i, helper, result;
    cifra c;

    c = (cifra) malloc(sizeof(struct alfa));

    c->codigo_recorrido=codigo;
    
    for(i=1;fraseescolhida[i]!='\0';i++){
        if((fraseescolhida[i]>='a')&&(fraseescolhida[i]<='z')){
            helper = fraseescolhida[i]+codigo;
            if(helper>'z'){
                result=helper-'a';
                helper=result;
                frase2_0[i]='a'+helper;
            }
            frase2_0[i]=helper;
            helper=0;
            result=0;
        }
    }
    return frase2_0;
}

void LerCifra(cifra c){

    c = (cifra) malloc(sizeof(struct alfa));

    int codigo;
    char linha[MAX];

    printf("Codigo:");
    scanf(" %d", &codigo);
    c->codigo_recorrido=codigo;
    printf("Texto: ");
    fgets(linha, MAX, stdin);
    sscanf(linha, "%s", c->frase_recebida);
}

void ApresentarCifra(cifra c){

    printf("Texto Cifrado: %s",c->frase_modificada);
    putchar('\n');
}

void EliminarCifra(cifra c){

    free(c);
}