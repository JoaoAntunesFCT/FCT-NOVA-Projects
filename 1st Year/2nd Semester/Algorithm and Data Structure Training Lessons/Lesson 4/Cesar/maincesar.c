#include <stdio.h>
#include <string.h>

#include "cesar.h"


void LeituraCodigo(int * code);
void LeituraMensagem(char * fraseinalterada, int n_linhas, char * mensagemfinal);
void LeituraLinhas(int * n_linhas);
void ApresentacaoMensagemCifrada(cesar z);

int main()
{
    int code, n_linhas;
    char fraseinalterada[MAXLEN], mensagemfinal[MAXLEN];
    cesar z;

    //Leitura de Dados
    LeituraCodigo(&code);
    LeituraLinhas(&n_linhas);
    LeituraMensagem(fraseinalterada, n_linhas, mensagemfinal);
    z = CriarCesar(mensagemfinal,code,n_linhas);
    //Converter a frase
    Cifragem(z);
    //Apresentar mensagem
    MensagemCesariana(z);
    //Destruir cesar
    DeleteCesar(z);
    return 0;
}

void LeituraCodigo(int * code){

    char temp[MAXLEN];
    
    printf("Codigo: ");
    fgets(temp,MAXLEN,stdin);
    sscanf(temp, "%d", code);
}

void LeituraMensagem(char * fraseinalterada, int n_linhas, char * mensagemfinal){

    char temp[MAXLEN], helper;
    int i;

    printf("Texto:\n");
    for(i=0;i<n_linhas;i++){

       fgets(temp,MAXLEN,stdin);
       sscanf(temp,"%s",fraseinalterada);
       strcat(mensagemfinal,fraseinalterada);
       printf("\n%s\n", mensagemfinal);
    }
}

void LeituraLinhas(int * n_linhas){

    printf("Linhas: ");
    scanf("%d", n_linhas);
}

void ApresentacaoMensagemCifrada(cesar z){
    printf("Texto cifrado: %s\n", MensagemCesariana(z));
}