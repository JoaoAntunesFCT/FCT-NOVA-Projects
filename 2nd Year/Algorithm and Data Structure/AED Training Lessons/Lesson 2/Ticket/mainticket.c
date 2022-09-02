/*import*/
#include <stdio.h>
#include "funcoesticket.h"

void LerMatricula(char * matricula);
void LerHora(char * mensagem, int * h, int * m);
void Duracao(int periodo, ticket t);

int main(void)
{
    /*declaracao das variaveis*/
    char matricula_a_receber[DIM_MATRICULA];
    int hora,minuto;
    int duracao;
    ticket t;

    /*obtencao dos dados*/
    LerMatricula(matricula_a_receber);
    LerHora("Entrada (hh:mm): ",&hora,&minuto);
    t = GeracaoTicket(matricula_a_receber,hora,minuto);
    
    /*calculos*/
    LerHora("Saida (hh:mm): ",&hora,&minuto);
    AtualizacaoDoTicket(t, hora, minuto);
    duracao = CalcularIntervalo(t);

    /*demonstracao dos resultados*/
    ApresentarEstadia(duracao,t);

    EliminarTicket(t);

    return 0;
}

