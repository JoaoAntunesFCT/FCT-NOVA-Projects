#ifndef _H_TALHAO
#define _H_TALHAO

/* Tipo de dados: iterador */

/***********************************************
struct _talhaogerado{
    int riqueza;
    int escavacoes;
}
***********************************************/
typedef struct _talhaogerado * talhao;

/* Prototipos das funcoes associadas a um iterador */

/***********************************************
criaTalhao - cria um talhão.
Parametros:
	(não existentes)
Retorno: a - instância da estrutura talhão.
Pre-condicoes: (não existentes)
***********************************************/
talhao criaTalhao(void);

/***********************************************
criaEquipa - realiza uma escavação no talhão a.
Parametros:
	a - talhão a escavar.
Retorno: caso o talhão não esteja vazio:
            temp - tesouro presente no talhão.
        caso o talhão esteja já escavado:
            a->escavacoes - número de escavações associadas ao talhão a.
Pre-condicoes: (não existentes)
***********************************************/
int escavarTalhao(talhao a);

/***********************************************
daRiquezaTalhao - atribui ao talhão 'a' uma determinada 'riqueza' enviada como parâmetro.
Parametros:
	a - talhão a manipular.
    riqueza - riqueza a atribuir ao talhão a.
Retorno: (não existente)
Pre-condicoes: (não existentes)
***********************************************/
void daRiquezaTalhao(talhao a, int riqueza);

/***********************************************
riquezaTalhao - devolve a riqueza associada a um determinado talhão 'a'.
Parametros:
	a - talhão a analisar.
Retorno: a->riqueza - devolve o parâmetro 'riqueza' do talhão 'a'.
Pre-condicoes: (não existentes)
***********************************************/
int riquezaTalhao(talhao a);

/***********************************************
escavacoesTalhao - devolve o número de escavações associadas a um determinado talhão 'a'.
Parametros:
	a - talhão a analisar.
Retorno: a->escavacoes - devolve o parâmetro 'escavacoes' do talhão 'a'.
Pre-condicoes: (não existentes)
***********************************************/
int escavacoesTalhao(talhao a);

#endif