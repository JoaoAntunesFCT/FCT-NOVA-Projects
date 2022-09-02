#ifndef TicketEstacionamento
#define TicketEstacionamento

/*constantes*/
#define DIM_MATRICULA 10
#define TAM_LIN_MAX 15
#define HORA_EM_MINUTOS 60

/*Tipos do TAD cases*/
typedef struct carros_no_estacionamento * ticket;

/********************************************************************
GeracaoTicket            --> Criar ticket

Parâmetros de entrada    --> matricula_a_receber: regista uma matrícula
                         --> hora: nº de horas de entrada
                         --> minuto: nº de minutos de entrada

Output                   --> t: uma estrutura que armazena os valores do ticket criado

Pre-condições            --> o tamanho da "matricula_a_receber" está limitada aos 10 caracteres
********************************************************************/
ticket GeracaoTicket(char * matricula_a_receber, int hora, int minuto);

/********************************************************************
AtualizacaoDoTicket       --> Coloca a hora de saída do veículo

Parâmetros de entrada    --> t: uma estrutura que armazena os valores do ticket criado
                         --> hora: nº de horas de saída                           
                         --> minuto: nº de minutos de saída

Output                   --> (nenhum)

Pre-condições            --> (nenhuma)
********************************************************************/
void AtualizacaoDoTicket(ticket t, int hora, int minuto);

/********************************************************************
CalcularIntervalo        --> Calcula o intervalo entre a entrada e a saída do veículo (em horas)

Parâmetros de entrada    --> t: uma estrutura que armazena os valores do ticket criado

Output                   --> duracao: intervalo decorrido entre a entrada e a saída

Pre-condições            --> (nenhuma)
********************************************************************/
int CalcularIntervalo(ticket t);

/********************************************************************
EliminarTicket           --> Apaga o ticket criado

Parâmetros de entrada    --> t: uma estrutura que armazena os valores do ticket criado

Output                   --> (nenhum)

Pre-condições            --> (nenhuma)
********************************************************************/
void EliminarTicket(ticket t);

/********************************************************************
TicketMatricula          --> 

Parâmetros de entrada    --> t: uma estrutura que armazena os valores do ticket criado

Output                   --> t->matricula: retorna o parâmetro "matricula" da estrutura "t"

Pre-condições            --> (nenhuma)
********************************************************************/
char * TicketMatricula(ticket t);

/********************************************************************
LerMatricula             --> Recebe a matrícula introduzida pelo utilizador

Parâmetros de entrada    --> matricula: matrícula digitada

Output                   --> (nenhum)

Pre-condições            --> (nenhuma)
********************************************************************/
void LerMatricula(char * matricula);

/********************************************************************
LerHora                  --> Regista a matrícula numa variável temporária bem com as horas introduzidas
                             (tanto de entrada como saída)

Parâmetros de entrada    --> mensagem: matrícula digitada
                             h: horas introduzidas (de entrada ou de saída, conforme)
                             m: minutos introduzidos (de entrada ou de saída, conforme)

Output                   --> (nenhum)

Pre-condições            --> (nenhuma)
********************************************************************/
void LerHora(char *mensagem, int * h, int * m);

/********************************************************************
ApresentarEstadia        --> Apresenta uma mensagem, especificando a matrícula, hora de entrada e saída,
                             e consequentemente a estadia no estacionamento

Parâmetros de entrada    --> periodo: tempo decorrido entre a entrada e a saída do veículo
                         --> t: uma estrutura que armazena os valores do ticket criado

Output                   --> (nenhum)

Pre-condições            --> (nenhuma)
********************************************************************/
void ApresentarEstadia(int periodo, ticket t);

#endif