#include <stdlib.h>
#include <string.h>
#include "equipa.h"
#include "membro.h"
#include "sequencia.h"
#include "iterador.h"

struct _equipa{
    char * nomeEquipa; //nome da equipa 
    int expulsa; //número que afere se está expulsa ou não
    int proximo; // começa em 1, o membro "1" a jogar
    int classificacaoEquipa; //classificação da equipa
    int totalMembros; //capacidade da equipa em relação a membros
    int n_membros; //número de membros no momento
    int n_desclassificados; //número de membros desclassificados
    sequencia membros; //sequência de membros
};

equipa criaEquipa(char * nomeEquipa, int n_membros) {
    
    equipa p =(equipa)malloc(sizeof(struct _equipa)); //alocação de memória do struct equipa p

    if (p==NULL){ //verificação da alocação de memória
        return NULL;
    }

    p->nomeEquipa = (char *) malloc(strlen(nomeEquipa) + 1); //alocação de memóra da string nomeEquipa

    if (p->nomeEquipa==NULL){ //verificação da alocação de memória
        return NULL;
    }
 
    p->membros = criaSequencia(n_membros); //cria a sequencia para os arqueologos

    strcpy(p->nomeEquipa,nomeEquipa); //nome da equipa
    p->expulsa=0; //começa classificada
    p->proximo=1; //o primeiro membro a jogar
    p->classificacaoEquipa=0; //ainda não possui classificação
    p->totalMembros=0; //número de elementos maximos da equipa
    p->n_membros=0; //número de elementos da equipa
    p->n_desclassificados=0; //ainda não possui membros desclassificados
    return p;
}

void destroiEquipa(equipa p) { //destrói a equipa, libertando memória
    free(p);
}

/*void destroiEquipaMembros(equipa p) {
    destroiSeqElems(p->membros, destroiMembro);
}*/

char * nomeEquipa(equipa p) { //devolve o nome da equipa
    return p->nomeEquipa;

}

int classificacaoEquipa(equipa p) { //devolve a classifcação da equipa
    return p->classificacaoEquipa;
}

int desclassificadosEquipa(equipa p) { //devolve o número de desclassificados presentes na equipa
    return p->n_desclassificados;
}

int licencaEquipa(equipa p) { //devolve o número de membros (presentes na equipa) com licença
    return p->totalMembros - p->n_desclassificados;
}

void adicionaMembroEquipa(equipa p, char * nomeMembro) { //adiciona um membro à equipa
    membro m = criaMembro(nomeMembro); //criação do membro
    
    p->n_membros++;
    p->totalMembros++;
    adicionaPosSequencia(p->membros, m, p->n_membros);
}

char * estrelaEquipa(equipa p) { //devolve o membro estrela presente na equipa

    int i, maxMer = 0, minPen = 0; //variáveis auxiliares
    char * nome; //string recetora do nome
    membro m;
    nome = malloc(41*(sizeof(char))); //alocação de memória para receção do nome
    m = elementoPosSequencia(p->membros, 1);

    for (i=p->n_membros; i > 0; i--) { //ao longo de todos os membros da equipa
        if (temLicencaMembro(m)) { //caso o membro da equipa tenha licença
            strcpy(nome, nomeMembro(m)); //é atribuído o nome do membro ao "nome"
            maxMer = meritoMembro(m); //o mérito é atualizado para este membro 
            minPen = penalizacoesMembro(m); //bem como as suas penalizações
        }
        m = elementoPosSequencia(p->membros, i); //passando ao próximo membro
    }
    for (i=1; i <= p->n_membros; i++) { //percorrendo novamente os membros
        if (temLicencaMembro(m)) { //caso este tenha licença
            if (meritoMembro(m) > maxMer) { //e o mérito seja superior ao guardado na variável "maxMer"
                maxMer = meritoMembro(m); //o mérito é atualizado
                minPen = penalizacoesMembro(m); //bem como o número de penalizações
                strcpy(nome, nomeMembro(m)); //e, claro, o nome do membro com a característica "estrela"
            }
            else if (meritoMembro(m) == maxMer) { //caso o mérito seja igual ao guardado na varíavel "maxMer"
                if (penalizacoesMembro(m) < minPen) { //iremos averiguar se o membro a analisar tem menor penalizações
                    minPen = penalizacoesMembro(m); //se sim, iremos atualizar o número de penalizações para esse membro
                    strcpy(nome, nomeMembro(m)); //bem como atualizar o nome do membro com a característica "estrela"
                }
                else if (penalizacoesMembro(m) == minPen) { //se possuírem igual número de penalizações
                    if (strcmp(nome, nomeMembro(m)) > 0) {
                        strcpy(nome, nomeMembro(m)); //atualizaremos apenas o nome do membro com a característica "estrela"
                    }
                }
            }
        }
        m = elementoPosSequencia(p->membros, i+1); //avançando para o próximo membro
    }
    return nome; //devolve o nome do membro "estrela"
}

void moverMembroEquipa(equipa p, int x, int y) { //move o membro nas coordenadas "x" e "y"
    moverMembro(elementoPosSequencia(p->membros, p->proximo), x, y);
}

int posicaoxUltimoMembroEquipa(equipa p) { //devolve a posição na coordenada "x" do último membro da equipa a ser trabalhado
    return posicaoxMembro(elementoPosSequencia(p->membros, p->proximo));
}

int posicaoyUltimoMembroEquipa(equipa p) { //devolve a posição na coordenada "y" do último membro da equipa a ser trabalhado
    return posicaoyMembro(elementoPosSequencia(p->membros, p->proximo));
}

void tiraLicencaUltimoMembroEquipa(equipa p) {
    tiraLicencaMembro(elementoPosSequencia(p->membros, p->proximo));
    p->n_desclassificados++;
}

void daMeritoUltimoMembroEquipa(equipa p, int classificacao) { //devolve o mérito do último membro da equipa a ser trabalhado
    daMeritoMembro(elementoPosSequencia(p->membros, p->proximo), classificacao);
    p->classificacaoEquipa += classificacao;
}

void daPenalizacaoUltimoMembroEquipa(equipa p) { //incrementa o número de penalizações do último membro da equipa a ser trabalhado
    daPenalizacaoMembro(elementoPosSequencia(p->membros, p->proximo));
}

int penalizacoesUltimoMembroEquipa(equipa p) { //devolve o número de penalizações do último membro da equipa a ser trabalhado
    return penalizacoesMembro(elementoPosSequencia(p->membros, p->proximo));
}

void proximoEquipa (equipa p) { //transporta as atenções para o próximo membro da equipa a ser trabalhado
    do {
        if(p->proximo==p->n_membros)
            p->proximo = 1;
        else
            p->proximo++;
    } while (!temLicencaMembro(elementoPosSequencia(p->membros, p->proximo)));
}

void expulsarEquipa (equipa p) { //expulsa a equipa do concurso
    p->expulsa = 1;
}

int equipaExpulsa (equipa p) { //devolve se a equipa está expulsa do concurso
    return p->expulsa;
}

int existeMembroEquipa(equipa p, char * nome) {
    iterador it = iteradorSequencia(p->membros);
    
    while(temSeguinteIterador(it)) {
        if (!strcmp(nome, nomeMembro(seguinteIterador(it))))
            return 1;
    }
    destroiIterador(it);
    return 0;
}