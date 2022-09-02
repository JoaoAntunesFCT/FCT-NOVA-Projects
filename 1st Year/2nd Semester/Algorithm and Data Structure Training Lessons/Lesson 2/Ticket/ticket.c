/*import*/
#include <string.h>
#include <stdlib.h>
#include "funcoesticket.h"

struct carros_no_estacionamento{

    char matricula[DIM_MATRICULA];
    int h_entrada, m_entrada;
    int h_saida, m_saida;
};

ticket GeracaoTicket(char * matricula_a_receber, int hora, int minuto){

    ticket t;

    t = (ticket) malloc(sizeof(struct carros_no_estacionamento));

    if(t==NULL){

        return NULL;
    }
    strcpy(t->matricula, matricula_a_receber);
    t->h_entrada = hora;
    t->m_entrada = minuto;

    return t;
}

void AtualizacaoDoTicket(ticket t, int hora, int minuto){

    t->h_saida = hora;
    t->m_saida = minuto;
}

int CalcularIntervalo(ticket t){

    int duracao=0;
    int entrada_minutos, saida_minutos;
    int helper;

    entrada_minutos = t->h_entrada * HORA_EM_MINUTOS + t->m_entrada;
    saida_minutos = t->h_saida * HORA_EM_MINUTOS + t->m_saida;

    helper = saida_minutos - entrada_minutos;
    duracao = helper/HORA_EM_MINUTOS;

    if(helper%HORA_EM_MINUTOS!=0){

        duracao+=1;
    }

    return duracao;
}

void EliminarTicket(ticket t){

    free(t);
}

char * TicketMatricula(ticket t){

    return t->matricula;
}

void LerMatricula(char * matricula){

    char linha[TAM_LIN_MAX];

    printf("Matricula: ");
    fgets(linha, TAM_LIN_MAX, stdin);
    sscanf(linha, "%s", matricula);
}

void LerHora(char *mensagem, int * h, int * m){

    char linha[TAM_LIN_MAX];

    printf("%s", mensagem);
    fgets(linha, TAM_LIN_MAX, stdin);
    sscanf(linha, "%d:%d", h ,m);
}

void ApresentarEstadia(int periodo, ticket t){

    printf("O carro com matricula %s teve uma estadia de %d horas\n", TicketMatricula(t), periodo);
}