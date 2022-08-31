#ifndef _H_TERRENO
#define _H_TERRENO

#include "iterador.h"
#include "equipa.h"

/* Tipo de dados: iterador */
typedef struct _terrenogerado * terreno;
/* Prototipos das funcoes associadas a um iterador */

/***********************************************
criaTerreno - cria um terreno.
Parametros:
	linhas - nº de linhas do terreno gerado.
	colunas - nº de colunas do terreno gerado.
	n_equipas - equipas em jogo.
Retorno: t - terreno criado.
Pre-condicoes: (não existentes)
***********************************************/
terreno criaTerreno(int linhas, int colunas);

/***********************************************
criaDicionarioEquipas - cria um dicionário para manipular as equipas que irão participar no concurso.
Parametros:
	t - terreno a receber o dicionário de equipas.
	n_equipas - equipas em jogo.
Retorno: (não existente)
Pre-condicoes: (não existentes)
***********************************************/
void criaDicionarioEquipas(terreno t, int n_equipas);

/***********************************************
destroiTerreno - destrói o terreno criado.
Parametros:
	t - terreno a destruir.
Retorno: (não existente)
Pre-condicoes: (não existentes)
***********************************************/
void destroiTerreno(terreno t);

/***********************************************
atribuiTesourosTerreno - adiciona um tesouro a um determinado talhão.
Parametros:
	t - terreno a atribuir os tesouros.
	linha - linha a manipular.
	coluna - coluna a manipular.
	tesouro - tesouro a adicionar ao talhão da respetiva "linha" e "coluna".
Retorno: (não existente)
Pre-condicoes: (não existentes)
***********************************************/
void atribuiTesouroTalhao(terreno t, int linha, int coluna, int tesouro);

/***********************************************
linhaTerreno - devolve o número de linha do terreno.
Parametros:
	t - terreno a analisar.
Retorno: t->colunas - parâmetro "colunas" do terreno "t".
Pre-condicoes: (não existentes)
***********************************************/
int linhaTerreno(terreno t);

/***********************************************
colunaTerreno - devolve o número de colunas do terreno.
Parametros:
	t - terreno a analisar.
Retorno: t->linhas - parâmetro "linhas" do terreno "t".
Pre-condicoes: (não existentes)
***********************************************/
int colunaTerreno(terreno t);

/***********************************************
contaTesourosTerreno - contabiliza a soma dos tesouros ainda presentes no terreno até ao momento.
Parametros:
	t - terreno a contabilizar os tesouros.
Retorno: riqueza - totalidade dos tesouros
Pre-condicoes: (não existentes)
***********************************************/
int contaTesourosTerreno(terreno t);

/***********************************************
existeRiquezaTerreno - vai verificar a existência de tesouro num determinado talhão de um respetivo terreno.
Parametros:
	t - terreno a facultar a existência de tesouro num determinado talhão.
	xlinha - indica a coordenada 'x' do talhão a verificar.
	ycoluna - fornece a coordenada 'y' do talhão a verificar.
Retorno: 1 - existe riqueza nesse talhão.
		 0 - não existe riqueza nesse talhão.
Pre-condicoes: (não existentes)
***********************************************/
int existeRiquezaTerreno(terreno t, int linha, int coluna);

/***********************************************
criaEquipaTerreno - é adicionada uma equipa ao concurso.
Parametros:
	t - terreno a receber a equipa.
	nomeEquipa - nome da equipa a adicionar.
	n_membros - número de membros que a equipa poderá possuir.
Retorno: (não existente)
Pre-condicoes: (não existentes)
***********************************************/
void criaEquipaTerreno(terreno t, char * nomeEquipa, int n_membros);

/***********************************************
adicionaMembroEquipaTerreno - é adicionado um membro a uma equipa.
Parametros:
	t - terreno a receber o membro.
	nomeEquipa - nome da equipa a ser manipulada.
	nomeMembro - nome do membro a ser adicionado.
Retorno: (não existente)
Pre-condicoes: (não existentes)
***********************************************/
void adicionaMembroEquipaTerreno(terreno t, char * nomeEquipa, char * nomeMembro);

/***********************************************
estrelaEquipaTerreno - devolve o membro "estrela" de uma determinada equipa.
Parametros:
	t - terreno a ser analisado.
	nomeEquipa - nome da equipa a ser analisada.
Retorno: estrelaEquipa(elementoDicionario(t->equipasCompeticao, nomeEquipa)) - nome do membro estrela
Pre-condicoes: (não existentes)
***********************************************/
char * estrelaEquipaTerreno(terreno t, char * nomeEquipa);

/***********************************************
existeEquipaTerreno - averigua se a equipa existe no concurso criado.
Parametros:
	t - terreno a ser analisado.
	nomeEquipa - nome da equipa a ser analisada.
Retorno: existeElemDicionario(t->equipasCompeticao, nomeEquipa) - existência da equipa
Pre-condicoes: (não existentes)
***********************************************/
int existeEquipaTerreno(terreno t, char * nomeEquipa);

/***********************************************
existeMembroEquipaTerreno - averigua se o membro existe na equipa.
Parametros:
	t - terreno analisar.
	nomeEquipa - nome da equipa a analisar.
	nomeMembro - nome do membro a aferir existência.
Retorno: existeMembroEquipa(elementoDicionario(t->equipasCompeticao, nomeEquipa), nomeMembro) - existência de um determinado membro
Pre-condicoes: (não existentes)
***********************************************/
int existeMembroEquipaTerreno(terreno t, char * nomeEquipa, char * nomeMembro);

/***********************************************
escavarTalhaoTerreno - executa a escavação num determinado talhão do terreno.
Parametros:
	t - terreno a ser escavado.
	nomeEquipa - nome da equipa que irá escavar.
	x - posição na coordenada "x" a ser escavada.
	y - posição na coordenada "y" a ser escavada.
Retorno: (não existente)
Pre-condicoes: (não existentes)
***********************************************/
void escavarTalhaoTerreno(terreno t, char * nomeEquipa, int x, int y);

/***********************************************
escavacaoTerreno - é averiguado os requisitos para proceder à escavação do terreno, escavação esta na função "escavarTalhaoTerreno".
Parametros:
	t - terreno a ser escavado.
	nomeEquipa - nome da equipa que irá escavar.
	x - posição na coordenada "x" a ser escavada.
	y - posição na coordenada "y" a ser escavada.
Retorno: 1 - é possível escavar || 0 - não é possível realizar a escavação
Pre-condicoes: (não existentes)
***********************************************/
int escavacaoTerreno(terreno t, char * nomeEquipa, int x, int y);

/***********************************************
existeEquipasTerreno - averigua se ainda existem equipas no terreno.
Parametros:
	t - terreno a ser analisado.
Retorno: 1 - ainda existem equipas no terreno || 0 - não existem, todas foram expulsas
Pre-condicoes: (não existentes)
***********************************************/
int existeEquipasTerreno(terreno t);

/***********************************************
equipaExpulsaTerreno - devolve o parâmetro de expulsão de uma determinada equipa.
Parametros:
	t - terreno a ser analisado.
	nomeEquipa - equipa a ser analisada.
Retorno: equipaExpulsa(elementoDicionario(t->equipasCompeticao, nomeEquipa)) - esta função irá devolver o parâmetro "expulsa" da equipa p
Pre-condicoes: (não existentes)
***********************************************/
int equipaExpulsaTerreno(terreno t, char * nomeEquipa);

/***********************************************
iteradorEquipas - devolve um iterador para o dicionário que contém as equipas presentes no concurso.
Parametros:
	t - terreno a ser analisado.
Retorno: iteradorDicionario(t->equipasCompeticao) - iterador para o dicionário a consultar
Pre-condicoes: (não existentes)
***********************************************/
iterador iteradorEquipas(terreno t);

/***********************************************
infoSairEquipaTerreno - informa a saída da equipa do terreno, armazenando os dados da mesma.
Parametros:
	t - terreno a ser analisado.
	pontos - pontos da equipa.
	desclassificados - número de desclassificados da equipa.
	licenca - número de licenças ativas.
Retorno: nomeEquipa(p) - nome da equipa p, que consequentemente possui todos os dados sobre a mesma.
Pre-condicoes: (não existentes)
***********************************************/
char * infoSairEquipaTerreno(terreno t, int* pontos, int* desclassificados, int* licenca);


#endif