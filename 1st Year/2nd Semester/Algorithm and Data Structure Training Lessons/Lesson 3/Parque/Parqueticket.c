/*import*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Parqueticket.h"
#include "Parque.h"

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
    printf("\n\nFUNCAO GERACAO TICKET HORA DE ENTRADA %d",t->h_entrada);
    t->m_entrada = minuto;
    printf("\n\nFUNCAO GERACAO TICKET MINUTO DE ENTRADA %d",t->m_entrada);
    return t;
}

void AtualizacaoDoTicket(ticket t, int hora, int minuto){

    t->h_saida = hora;
    t->m_saida = minuto;
    printf("\n\n FUNCAO CALCULAR INTERVALO entrada saida FINAL: %d %d\n\n", hora, minuto);
}

int CalcularIntervalo(ticket t){

    int duracao=0;
    int entrada_minutos=0, saida_minutos=0;
    int helper;

    printf("\n\nFUNCAO CALCULAR INTERVALO HORAS E MINUTOS: %d %d\n\n", t->h_entrada,t->m_entrada);
    entrada_minutos = (HorasMinutos(t->h_entrada)) + t->m_entrada;
    saida_minutos = (HorasMinutos(t->h_saida)) + t->m_saida;
    printf("\n\n FUNCAO CALCULAR INTERVALO entrada saida: %d %d\n\n", entrada_minutos, saida_minutos);
    helper = saida_minutos - entrada_minutos;
    duracao = helper/HORA_EM_MINUTOS;
    //printf("\n\n FUNCAO CALCULAR INTERVALO HELPER: %d %d\n\n", helper, duracao);

    if(helper%HORA_EM_MINUTOS!=0){

        duracao+=1;
    }

    printf("\n\n FUNCAO CALCULAR INTERVALO: %d\n\n", duracao);
    return duracao;
}

void EliminarTicket(ticket t){

    free(t);
}

char * TicketMatricula(ticket t){

    return t->matricula;
}

int HorasMinutos(int horas){

    printf(" \n\n%d\n\n", horas);
    return horas*HORA_EM_MINUTOS;
}