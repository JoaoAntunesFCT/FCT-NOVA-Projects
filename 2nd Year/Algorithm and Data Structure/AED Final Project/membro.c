#include <stdlib.h>
#include <string.h>
#include "membro.h"
#include "equipa.h"


struct _membrogerado{
    char * nomeMembro; //nome do arqueólogo
    int posicaox;
    int posicaoy;
    int merito; //mérito do respetivo arqueólogo que irá sendo incrementado ou decrementado conforme o seu desempenho
    int n_penalizacoes; //número de penalizações do arqueólogo em questão que irá sendo incrementado conforme o seu desempenho
    int licenca; // 1 - Possui licença para escavar || 0 - Não possui licença para escavar
};

membro criaMembro(char * nomeMembro){ //cria o membro
	
    membro m =(membro)malloc(sizeof(struct _membrogerado)); //alocação de memória

    if (m==NULL){ //verificação da alocação de memória
        return NULL;
    }

    m->nomeMembro = (char *) malloc(strlen(nomeMembro) + 1); //alocação de memóra da string nomeMembro
    
    if (m->nomeMembro==NULL){ //verificação da alocação de memória
        return NULL;
    }

    strcpy(m->nomeMembro,nomeMembro);
    m->posicaox=-1; //posição x inicial
    m->posicaoy=-1; //posição y inicial
    m->merito=0; //ainda não possui mérito
    m->n_penalizacoes=0; //ainda não sofreu penalizações
    m->licenca=1; // como possui licença de escavação por natureza, este valor é inicializado a 1

    return m;
}

void destroiMembro(membro m) { //destrói o membro, libertando a memória
    free(m);
}

char * nomeMembro(membro m) { //devolve o nome do membro
    return m->nomeMembro;
}

int meritoMembro(membro m) { //devolve o mérito do membro
    return m->merito;
}

int penalizacoesMembro(membro m) { //devolve o número de penalizações do membro
    return m->n_penalizacoes;
}

void daMeritoMembro(membro m, int merito) { //atualiza o valor do mérito do membro
    m->merito += merito; 
}

void daPenalizacaoMembro(membro m) { //incrementa o número de penalizações do membro
    m->n_penalizacoes += 1;
}

void tiraLicencaMembro(membro m) { //retira a licença do membro
    m->licenca = 0;
}

int temLicencaMembro(membro m) { //devolve a licença do membro
    return m->licenca;
}

void moverMembro(membro m, int linhas, int colunas) { //move o membro nas coordenadas "x" e "y" conforme a vontade do utilizador
    m->posicaox += linhas; //incrementa a posicaox de acordo com o acréscimo do valor 'linhas'
    m->posicaoy += colunas; //incrementa a posicaoy de acordo com o acréscimo do valor 'colunas'
}

int posicaoxMembro(membro m) { //devolve a posição do membro na coordenada "x"
    return m->posicaox;
}

int posicaoyMembro(membro m) { //devolve a posição do membro na coordenada "y"
    return m->posicaoy;
}


