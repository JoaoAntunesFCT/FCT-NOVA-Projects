#include <stdio.h>
#include <string.h>
#include "funcoescifra.h"

int main (){

    cifra c;
    char frasealterada[MAX];

    /*Escolha do código e da frase a trocar*/
    LerCifra(cifra c);

    /*chamada da função*/
    frasealterada=ConversaoCifra(cifra c);
    
    /*exposição da frase alterada*/
    ApresentarCifra(cifra c);

    return 0; 
}