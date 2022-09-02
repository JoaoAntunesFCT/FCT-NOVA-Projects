#ifndef AlfabetoCifra
#define AlfabetoCifra
#define MAX 100

/*Tipos do TAD cases*/
typedef struct alfa * cifra;

/********************************************************************
conversao                --> irá copiar o conteúdo da frase, convertendo

Parâmetros de entrada    --> frase_escolhida: string que contém os caracteres que vão ser convertidos
                         --> codigo: número inteiro

Output                   --> frase_final: frase obtida através da conversão segundo o código

Pre-condições            --> codigo: tem que ser um integer
********************************************************************/
void ConversaoCifra(char fraseescolhida[], int  codigo);

/********************************************************************
conversao                --> 

Parâmetros de entrada    --> 
                         --> 

Output                   --> 

Pre-condições            --> 
********************************************************************/
void LerCifra(cifra c);

/********************************************************************
conversao                --> 

Parâmetros de entrada    --> 
                         --> 

Output                   --> 

Pre-condições            --> 
********************************************************************/
void ApresentarCifra(cifra c);

/********************************************************************
conversao                --> 

Parâmetros de entrada    --> 
                         --> 

Output                   --> 

Pre-condições            --> 
********************************************************************/
void EliminarCifra(cifra c);

#endif