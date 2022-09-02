#ifndef _H_MEMBRO
#define _H_MEMBRO

/* Tipo de dados: iterador */  //DICIONARIO!!
typedef struct _membrogerado * membro;

/* Prototipos das funcoes associadas a um iterador */

/***********************************************
criaEquipa - cria um membro.
Parametros:
	nomeMembro - nome da membro a gerar.
	classificacao - classificação da equipa.
    desclassificado
        - 0: o membro foi desclassficado.
        - 1: o membro (ainda) não foi desclassificado.
    clincenca
        - 0: o membro não tem licença para escavar.
        - 1: o membro (ainda) tem licença para escavar.
Retorno: 
Pre-condicoes:  
***********************************************/
membro criaMembro(char * nomeMembro);

/***********************************************
destroiMembro - destroi o membro m outrora criada.
Parametros:
	m - membro a destruir.
Retorno: (não existente)
Pre-condicoes: (não existentes)
***********************************************/
void destroiMembro(membro m);

/***********************************************
daNomeMembro - devolve o nome de um determinado arqueólogo.
Parametros:
	m - membro a analisar.
Retorno: m->nomeMembro - devolve o parâmetro 'nomeMembro' do membro 'm'.
Pre-condicoes: (não existentes)
***********************************************/
char * nomeMembro(membro m);

/***********************************************
meritoMembro - devolve o mérito de um determinado arqueólogo.
Parametros:
	m - membro a analisar.
Retorno: m->merito - devolve o parâmetro 'merito' do membro 'm'.
Pre-condicoes: (não existentes)
***********************************************/
int meritoMembro(membro m);

/***********************************************
penalizacoesMembro - devolve o número de penalizações de um determinado arqueólogo.
Parametros:
	m - membro a analisar.
Retorno: m->n_penalizacoes - devolve o parâmetro 'n_penalizacoes' do membro 'm'.
Pre-condicoes: (não existentes)
***********************************************/
int penalizacoesMembro(membro m);

/***********************************************
daMeritoMembro - adiciona um mérito determinado a um arqueólogo.
Parametros:
	m - membro a atribuir o mérito.
	merito - merito a adicionar.
Retorno: (não existente)
Pre-condicoes: (não existentes)
***********************************************/
void daMeritoMembro(membro m, int merito);

/***********************************************
daPenalizacaoMembro - adiciona uma penalizacao a um arqueólogo.
Parametros:
	m - membro a penalizar.
Retorno: (não existente)
Pre-condicoes: (não existentes)
***********************************************/
void daPenalizacaoMembro(membro m);

/***********************************************
tiraLicencaMembro - devolve se o membro possui ou não licença de escavação.
Parametros:
	m - membro a analisar.
Retorno: (não existente)
Pre-condicoes: (não existentes)
***********************************************/
void tiraLicencaMembro(membro m);

/***********************************************
temlicencaMembro - devolve se o membro possui ou não licença de escavação.
Parametros:
	m - membro a analisar.
Retorno: m->licenca - devolve o parâmetro 'licenca' do membro 'm'.
Pre-condicoes: (não existentes)
***********************************************/
int temLicencaMembro(membro m);

/***********************************************
moverMembro - move o arqueólogo, atualizando assim a sua posição.
Parametros:
	m - membro a mover.
	linhas - número de linhas a mover.
	colunas - número de colunas a mover.
Retorno:(não existente)
Pre-condicoes: (não existentes)
***********************************************/
void moverMembro(membro m, int linhas, int colunas);

/***********************************************
posicaoxMembro - devolve a posição no eixo 'x' do membro 'm'.
Parametros:
	m - membro a analisar.
Retorno: m->posicaox - devolve o parâmetro 'posicaox' do membro 'm'.
Pre-condicoes: (não existentes)
***********************************************/
int posicaoxMembro(membro m);

/***********************************************
posicaoyMembro - devolve a posição no eixo 'y' do membro 'm'.
Parametros:
	m - membro a analisar.
Retorno: m->posicaoy - devolve o parâmetro 'posicaoy' do membro 'm'.
Pre-condicoes: (não existentes)
***********************************************/
int posicaoyMembro(membro m);

#endif