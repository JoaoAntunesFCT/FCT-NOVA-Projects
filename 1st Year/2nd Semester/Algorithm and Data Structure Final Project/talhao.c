#include <stdlib.h>
#include "talhao.h"

struct _talhaogerado{
    int riqueza; //riqueza existente no terreno
    int escavacoes; //escavações realizadas no terreno
};

talhao criaTalhao(void) { //criação do talhão
    talhao a = (talhao) malloc(sizeof(struct _talhaogerado)); //alocação de memória
    if (a==NULL) //verificação da alocação de memória
        return NULL;
    a->riqueza = 0; //a riqueza é inicializada a 0
    a->escavacoes = -1; //as escavações começam com o valor -1 de modo a facilitar a leitura do valor em funções futuras
    return a;
}

int escavarTalhao(talhao a) { //escavação de um determinado talhão
    int temp = a->riqueza; //armazenamento do valor da riqueza numa variável temporária 'temp'

    if (a->escavacoes == -1) { //caso ainda não tenha sido escavado
        a->riqueza = 0; //a riqueza é escavada, ficando assim a 0
        a->escavacoes++; //é incrementado o número de escavações feitas no talhão
        return temp; //é devolvida a riqueza 
    }
    else { //caso já tenha sido escavado
        a->escavacoes++; //incrementa-se o número de escavações realizadas no talhão
        return -a->escavacoes; //é devolvido o valor das escavações em negativo de modo a, após x10, decrementar esse valor ao mérito do jogador
    }
    
}

void daRiquezaTalhao(talhao a, int riqueza) { //atribui uma determinada riqueza a um talhão
    a->riqueza = riqueza;
}

int riquezaTalhao(talhao a) { //devolve a riqueza presente num talhão
    return a->riqueza;
}

int escavacoesTalhao(talhao a) { //devolve o número de escavações executadas num determinado talhão
    return a->escavacoes;
}
