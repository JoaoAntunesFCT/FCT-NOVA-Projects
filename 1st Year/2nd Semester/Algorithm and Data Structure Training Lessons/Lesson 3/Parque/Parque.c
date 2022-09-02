#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "Parque.h"
#include "Parqueticket.h"

#define Preco_1h 1.5
#define Preco_2h 1
#define Preco_3h 0.75

struct estacionamento{

    ticket * lugares;
    int numero_lugares;
    int ocupacao_total;
    float dinheiro;
};

_estacionamento GerarParque(int tamanhoparque){

    _estacionamento repouso;

    repouso = (_estacionamento) malloc(sizeof(struct estacionamento));

    if(repouso==NULL){

        return NULL;
    }
    repouso->lugares = (ticket *) malloc(sizeof(ticket)*tamanhoparque);
    if(repouso->lugares==NULL){

        free(repouso);
        return NULL;
    }
    repouso->numero_lugares = 0;
    repouso->ocupacao_total = tamanhoparque;
    repouso->dinheiro = 0.0;

    return repouso;
}

void DestroiParque(_estacionamento repouso){

    free(repouso->lugares);
    free(repouso);
}

void DestroiParqueTicket(_estacionamento repouso){

    int temp;
    for(temp=0;temp>repouso->numero_lugares;temp++){

        EliminarTicket(repouso->lugares[temp]);
    }
    free(repouso->lugares);
    free(repouso);
}

float CaixaDoParque(_estacionamento repouso){

    return repouso->dinheiro;
}

int LotacaoParque(_estacionamento repouso){

    return repouso->numero_lugares;
}

ticket DarTicketParque(_estacionamento repouso, int antes){

    return repouso->lugares[antes-1];
}

int VerificarExistenciaParque(_estacionamento repouso, char * matricula){

    int temp=0, verifica=0;

    while(temp<repouso->numero_lugares && verifica==0){

        if(strcmp(matricula, TicketMatricula(repouso->lugares[temp]))==0){

            verifica = 1;
        }
        temp++;
    }
    return verifica;
}

//FUNCOES EXCLUSIVAS DE QUANDO NAO EXISTE TICKET

void AdicionarTicketParque(_estacionamento repouso, char * matricula, int horas, int minutos){

    ticket t;

    t = GeracaoTicket(matricula, horas, minutos);
    repouso->lugares[repouso->numero_lugares++] = t;
}

int PosTicketParque(_estacionamento repouso, char * matricula){

    int temp=0, pos=-1;

    while(temp<repouso->numero_lugares && pos==-1){

        if(strcmp(matricula, TicketMatricula(repouso->lugares[temp]))==0){

            pos = temp;
        }
        temp++;
    }
    return temp;
}

float CalcularReceita(int tempo){

    printf("\n\nCALCULAR Intervalo (neste momento em minutos): %d\n\n",tempo);
    float receita=0.0;

    switch(tempo){

        case 3: receita = receita + Preco_2h;
        case 2: receita = receita + Preco_2h;
        case 1: receita = receita + Preco_1h; break;
        default: receita = receita + Preco_1h + 2*Preco_2h + Preco_3h*(tempo-3);
    }

    printf("\n\nReceita Calculada: %f\n\n",receita);
    return receita;
}

float RemoverTicketParque(_estacionamento repouso, char * matricula, int horas, int minutos){

    int pos, temp, duracao;
    ticket t;
    float receita;

    printf("\n\nFUNCAO REMOVERTICKETPARQUE HORAS E MINUTOS DE ENTRADA: %d %d\n\n",t->)

    pos = PosTicketParque(repouso, matricula);

    t = DarTicketParque(repouso, pos+1);

    AtualizacaoDoTicket(t, horas, minutos);

    duracao = CalcularIntervalo(t);

    receita = CalcularReceita(duracao);
    printf (" %f", receita);

    repouso->dinheiro = repouso->dinheiro + receita;

    for(temp=0;temp<repouso->numero_lugares;temp++){

        repouso->lugares[temp]=repouso->lugares[temp+1];

    }
    repouso->numero_lugares--;
    return receita;
}

void MainMenu(_estacionamento repouso){

    char frase[MAXSIZE_L], menu;

    fgets(frase,MAXSIZE_L,stdin);
    menu=toupper(frase[0]);
    while (menu!='X'){

        switch (menu){
            case 'E': EntradaCarroMenu(repouso, frase); break;
            case 'S': SaidaCarroMenu(repouso, frase); break;
            case 'C': SaldoMenu(repouso); break;
            case 'L': ListagemMenu(repouso); break;
            default: printf("Comando invalido.\n"); break;
        }
        fgets(frase,MAXSIZE_L,stdin);
        menu=toupper(frase[0]);
    }
    SairMenu(repouso);
}

void EntradaCarroMenu(_estacionamento repouso, char *frase){

    char car;
    int hora=0, minuto=0;
    char matricula[SIZEM];

    if(sscanf(frase,"%c %s %d:%d", &car, matricula, &hora, &minuto)!=4){
        printf("Dados invalidos.\n");
    }
    else{
        if(VerificarExistenciaParque(repouso,matricula))
            printf("Carro ja no parque.\n");
        else{
            AdicionarTicketParque(repouso,matricula,hora,minuto);
            printf("Entrada autorizada.\n");
        }
    }
}

void SaidaCarroMenu(_estacionamento repouso, char * frase){

    char car;
    int hora, minuto;
    char matricula[SIZEM];
    float valor;

    if(sscanf(frase,"%c %s %d:%d", &car, matricula, &hora, &minuto)!=4){
        printf("Dados invalidos.\n");
    }
    else{
        if(!VerificarExistenciaParque(repouso,matricula))
            printf("Carro nao existe no parque.\n");
        else{
            valor = RemoverTicketParque(repouso,matricula,hora,minuto);
            printf("Carro com matricula %s deve pagar %.2f euros.\n", matricula, valor);
        }
    }
}

void SaldoMenu(_estacionamento repouso){
    printf("Dinheiro em caixa : %.2f euros.\n", CaixaDoParque(repouso));
}

void ListagemMenu(_estacionamento repouso){

    int temp;
    ticket t;
    int teste = LotacaoParque(repouso);

    if (teste==0){
        printf("Parque sem carros.\n");
    }

    for(temp=1; temp<=teste; temp++){
        t = DarTicketParque(repouso, temp);
        printf("Matricula: %s\n",  TicketMatricula(t));
    }
}

void SairMenu(_estacionamento repouso){
    SaldoMenu(repouso);
    printf("%d carros no parque.\n", LotacaoParque(repouso));
}



