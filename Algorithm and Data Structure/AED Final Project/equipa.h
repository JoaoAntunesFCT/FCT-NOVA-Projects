#ifndef _H_EQUIPA
#define _H_EQUIPA

#define TAMMAX 41

/* Tipo de dados: iterador */

/***********************************************
struct _equipa{
    char * nomeEquipa;
    int expulsa;
    int proximo;
    int classificacaoEquipa;
    int capMembros;
    int n_membros;
    int n_desclassificados;
    sequencia membros;
}
***********************************************/
typedef struct _equipa * equipa;

/* Prototipos das funcoes associadas a um iterador */

/***********************************************
criaEquipa - cria uma equipa.
Parametros:
	nomeEquipa - nome da equipa a gerar.
    n_membros - número de membros da equipa.
Retorno: p - instância da estrutura equipa.
Pre-condicoes: (não existentes)
***********************************************/
equipa criaEquipa(char * nomeEquipa, int n_membros); //tem de começar sem membros

/***********************************************
destroiEquipa - liberta a memória ocupada pela instância da estrutura equipa p.
Parametros:
	p - equipa a destruir.
Retorno: (não existente)
Pre-condicoes: (não existentes)
***********************************************/
void destroiEquipa(equipa p);

/***********************************************
destroiEquipaMembros - liberta a memória ocupada pela instância da estrutura equipa p e os membros guardados na sua sequência.
Parametros:
	p - equipa a destruir.
Retorno: (não existente)
Pre-condicoes: (não existentes)
***********************************************/
//void destroiEquipaMembros(equipa p);

/***********************************************
nomeEquipa - envia o nome da equipa p.
Parametros:
	p - equipa a analisar.
Retorno: p->nomeEquipa - parâmetro "nomeEquipa" da equipa p.
Pre-condicoes: (não existentes) 
***********************************************/
char * nomeEquipa(equipa p);

/***********************************************
classificacaoEquipa - devolve a classificação da equipa.
Parametros:
	p - equipa a analisar.
Retorno: p->classificacaoEquipa - parâmetro "classificacaoEquipa" da equipa p.
Pre-condicoes: (não existentes) 
***********************************************/
int classificacaoEquipa(equipa p);

int desclassificadosEquipa(equipa p);

/***********************************************
licencaEquipa - devolve quantos membros da equipa têm licença.
Parametros:
	p - equipa a analisar.
Retorno: (p->capMembros - p->n_desclassificados) - retira o número de desclassificados ao número de membros da equipa p.
Pre-condicoes: (não existentes)  
***********************************************/
int licencaEquipa(equipa p);

/***********************************************
adicionaMembroEquipa - adiciona um membro (pointer) à sequencia membros.
Parametros:
	p - equipa a analisar.
    nomeMembro - nome do membro a adicionar.
Retorno: 1 - se adicionou || 0 - se não.
Pre-condicoes: (não existentes)
***********************************************/
void adicionaMembroEquipa(equipa p, char * nomeMembro);

/***********************************************
estrelaEquipa - devolve o nome do membro-estrela (membro com mais pontos) da equipa p.
Parametros:
	p - equipa a analisar.
Retorno: nome - nome do membro-estrela da equipa analisada.
Pre-condicoes: (não existentes)
***********************************************/
char * estrelaEquipa(equipa p);

/***********************************************
moverMembroEquipa - move o membro da equipa p para a posição 'x' e 'y' dada.
Parametros:
	p - equipa a analisar.
	x - posição 'x'
	y - posição 'y'
Retorno: nome - nome do membro-estrela da equipa analisada.
Pre-condicoes: (não existentes)
***********************************************/
void moverMembroEquipa(equipa p, int x, int y);

/***********************************************
posicaoxUltimoMembroEquipa - devolve a posição 'x' do último membro da equipa p.
Parametros:
	p - equipa a analisar.
Retorno: posicaoxMembro(elementoPosSequencia(p->membros, p->proximo)) - 
Pre-condicoes: (não existentes)
***********************************************/
int posicaoxUltimoMembroEquipa(equipa p);

/***********************************************
posicaoyUltimoMembroEquipa - devolve a posição 'y' do último membro da equipa p.
Parametros:
	p - equipa a analisar.
Retorno: posicaoMembro(elementoPosSequencia(p->membros, p->proximo)) - 
Pre-condicoes: (não existentes)
***********************************************/
int posicaoyUltimoMembroEquipa(equipa p);

/***********************************************
tiraLicencaUltimoMembroEquipa - retira a licença ao membro da equipa p.
Parametros:
	p - equipa a analisar.
Retorno: (não existente)
Pre-condicoes: (não existentes)
***********************************************/
void tiraLicencaUltimoMembroEquipa(equipa p);

/***********************************************
daMeritoUltimoMembroEquipa - atribui mérito ao membro da equipa p.
Parametros:
	p - equipa a analisar.
	classificacao - mérito a atribuir ao membro.
Retorno: (não existente)
Pre-condicoes: (não existentes)
***********************************************/
void daMeritoUltimoMembroEquipa(equipa p, int classificacao);

/***********************************************
daPenalizacaoUltimoMembroEquipa - atribui uma penalização ao membro da equipa p.
Parametros:
	p - equipa a analisar.
Retorno: (não existente)
Pre-condicoes: (não existentes)
***********************************************/
void daPenalizacaoUltimoMembroEquipa(equipa p);

/***********************************************
penalizacoesUltimoMembroEquipa - devolve o número de penalizações do membro da equipa p.
Parametros:
	p - equipa a analisar.
Retorno: penalizacoesMembro(elementoPosSequencia(p->membros, p->proximo)) - número de penalizações do membro da equipa p.
Pre-condicoes: (não existentes)
***********************************************/
int penalizacoesUltimoMembroEquipa(equipa p);

/***********************************************
proximoEquipa - exibe cada membro bem como o mérito de cada um, membros estes da equipa p.
Parametros:
	p - equipa a analisar.
Retorno: (não existente)
Pre-condicoes: (não existentes)
***********************************************/
void proximoEquipa(equipa p);

/***********************************************
expulsarEquipa - expulsa a equipa p.
Parametros:
	p - equipa a expulsar.
Retorno: nome - (não existente)
Pre-condicoes: (não existentes)
***********************************************/
void expulsarEquipa(equipa p);

/***********************************************
equipaExpulsa - averigua se a equipa p está expulsa.
Parametros:
	p - equipa a analisar.
Retorno: p->expulsa - devolve o parâmetro "expulsa" da equipa p.
Pre-condicoes: (não existentes)
***********************************************/
int equipaExpulsa(equipa p);

int existeMembroEquipa(equipa p, char * nome);


/***********************************************
reforcarEquipa - atribui um novo membro à equipa p.
Parametros:
	p - equipa a atribuir um determinado membro.
Retorno: 
Pre-condicoes:  
***********************************************/
//void reforcarEquipa(equipa p); para implementação futura

/***********************************************
contarMembros - devolve o número de membros existentes na equipa.
Parametros:
	p - 
Retorno: 
Pre-condicoes:  
***********************************************/
//int contarMembros(equipa p); para implementação futura




#endif