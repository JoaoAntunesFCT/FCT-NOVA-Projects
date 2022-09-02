#ifndef ParqueEstacionamento
#define ParqueEstacionamento

#include "Parqueticket.h"

#define SIZEM 10
#define MAXSIZE_L 30
#define MAXSIZE_SEATS 150
#define Preco_1h 1.5
#define Preco_2h 1
#define Preco_3h 0.75

typedef struct estacionamento * _estacionamento;

/********************************************************************
GerarParque              --> Criar um parque

Parâmetros de entrada    --> tamanhoparque: apresenta os lugares do parque

Output                   --> (nenhum)

Pre-condições            --> (nenhuma)
********************************************************************/
_estacionamento GerarParque(int tamanhoparque);

/********************************************************************
DestroiParque            --> Destrói o parque existente

Parâmetros de entrada    --> repouso: uma estrutura que armazena os valores do parque criado

Output                   --> (nenhum)

Pre-condições            --> (nenhuma)
********************************************************************/
void DestroiParque(_estacionamento repouso);

/********************************************************************
DestroiParqueTicket      --> Elimina um ticket associado a um conjunto de dados

Parâmetros de entrada    --> repouso: uma estrutura que armazena os valores do parque criado

Output                   --> (nenhum)

Pre-condições            --> (nenhuma)
********************************************************************/
void DestroiParqueTicket(_estacionamento repouso);

/********************************************************************
VerificarExistenciaParque--> Analisa a existência de um determinado ticket

Parâmetros de entrada    --> repouso: uma estrutura que armazena os valores do parque criado
                         --> matricula: matrícula associada a um determinado ticket

Output                   --> verifica: assume o valor '0' caso o carro não esteja 
                             presente no estacionamento e '1' caso esteja

Pre-condições            --> (nenhuma)
********************************************************************/
int VerificarExistenciaParque(_estacionamento repouso, char * matricula);

/********************************************************************
LotacaoParque            --> Exprime a quantidade de lugares ocupados no parque

Parâmetros de entrada    --> repouso: uma estrutura que armazena os valores do parque criado

Output                   --> (nenhum)

Pre-condições            --> (nenhuma)
********************************************************************/
int LotacaoParque(_estacionamento repouso);

/********************************************************************
RemoverTicketParque      --> 

Parâmetros de entrada    --> repouso: uma estrutura que armazena os valores do parque criado
                         --> matricula: matrícula associada a um determinado ticket

Output                   --> 

Pre-condições            --> 
********************************************************************/
float RemoverTicketParque(_estacionamento repouso, char * matricula, int horas, int minutos);

/********************************************************************
GeracaoTicket            --> 

Parâmetros de entrada    --> 
                         --> 
                         -->

Output                   --> 

Pre-condições            --> 
********************************************************************/
float CaixaDoParque(_estacionamento repouso);

/********************************************************************
GeracaoTicket            --> 

Parâmetros de entrada    --> 
                         --> 
                         -->

Output                   --> 

Pre-condições            --> 
********************************************************************/
ticket DarTicketParque(_estacionamento repouso, int possivel);

/********************************************************************/
/*************************DOESN'T NEED*******************************/
/***********************EXISTING TICKETS*****************************/
/********************************************************************/

/********************************************************************
GeracaoTicket            --> 

Parâmetros de entrada    --> 
                         --> 
                         -->

Output                   --> 

Pre-condições            --> 
********************************************************************/
void AdicionarTicketParque(_estacionamento repouso, char * matricula, int horas, int minutos);

/********************************************************************
GeracaoTicket            --> 

Parâmetros de entrada    --> 
                         --> 
                         -->

Output                   --> 

Pre-condições            --> 
********************************************************************/
int PosTicketParque(_estacionamento repouso, char * matricula);

/********************************************************************
GeracaoTicket            --> 

Parâmetros de entrada    --> 
                         --> 
                         -->

Output                   --> 

Pre-condições            --> 
********************************************************************/
float CalcularReceita(int tempo);

/********************************************************************/
/*************************MENU FUNCTIONS*****************************/
/********************************************************************/

/********************************************************************
GeracaoTicket            --> 

Parâmetros de entrada    --> 
                         --> 
                         -->

Output                   --> 

Pre-condições            --> 
********************************************************************/
void MainMenu(_estacionamento repouso);

/********************************************************************
GeracaoTicket            --> 

Parâmetros de entrada    --> 
                         --> 
                         -->

Output                   --> 

Pre-condições            --> 
********************************************************************/
void EntradaCarroMenu(_estacionamento repouso, char * linha);

/********************************************************************
GeracaoTicket            --> 

Parâmetros de entrada    --> 
                         --> 
                         -->

Output                   --> 

Pre-condições            --> 
********************************************************************/
void SaidaCarroMenu(_estacionamento repouso, char * linha);

/********************************************************************
GeracaoTicket            --> 

Parâmetros de entrada    --> 
                         --> 
                         -->

Output                   --> 

Pre-condições            --> 
********************************************************************/
void SaldoMenu(_estacionamento repouso);

/********************************************************************
GeracaoTicket            --> 

Parâmetros de entrada    --> 
                         --> 
                         -->

Output                   --> 

Pre-condições            --> 
********************************************************************/
void ListagemMenu(_estacionamento repouso);

/********************************************************************
GeracaoTicket            --> 

Parâmetros de entrada    --> 
                         --> 
                         -->

Output                   --> 

Pre-condições            --> 
********************************************************************/
void SairMenu(_estacionamento repouso);

#endif
