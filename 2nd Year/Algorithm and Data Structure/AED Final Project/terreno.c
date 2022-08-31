#include <stdlib.h>
#include <string.h>
#include "terreno.h"
#include "equipa.h"
#include "dicionario.h"
#include "talhao.h"
#include "iterador.h"

struct _terrenogerado {
    int linhas; //número de linhas do terreno
    int colunas; //número de colunas do terreno
    talhao ** matriz; //matriz dinâmica para representar o terreno
    int n_equipasVagas; //número de vagas existentes para equipas entrarem no torneio
    int expulsas;
    dicionario equipasCompeticao; //apontador para as equipas associadas ao terreno
};

terreno criaTerreno(int linhas, int colunas){ //criação de um terreno
	
    terreno t =(terreno)malloc(sizeof(struct _terrenogerado)); //alocação de memória
    int i, j;

	if (t==NULL){ //verificação da alocação de memória
        return NULL;
    }

    t->matriz = malloc( (linhas+1) * sizeof(*t->matriz));
    for (i=0; i<=linhas; i++) {
        t->matriz[i] = malloc( (colunas+1) * sizeof(t->matriz[0]));
    }

    t->linhas=linhas; //atribuição do número de linhas ao terreno gerado
    t->colunas=colunas; //atribuição do número de colunas ao terreno gerado
    t->n_equipasVagas=0; //atribuição temporaria
    t->expulsas=0; //começa com todas a esquipas em jogo

    for(i=0; i<linhas; i++) { //irá percorrer cada linha, alocando posteriormente memória
        for(j=0;j<colunas;j++) {
            t->matriz[i][j] = criaTalhao();
        }    
    }
	return t;
}

void criaDicionarioEquipas(terreno t, int n_equipas) { //criação de um dicionário para armazenar as equipas presentes no concurso
    t->equipasCompeticao = criaDicionario(n_equipas, 1);
}

void destroiTerreno(terreno t) { //destrói o terreno criado
    int i,j; //variáveis auxiliares
    
    free(t->equipasCompeticao); //libertação da memória alocada para a geração das equipas
    for(i=0;i<t->linhas;j++){                     /*Duplo ciclo 'for'*/
        for(j=0;j<t->colunas;j++){                    /*utlidade:*/
            free(t->matriz[i][j]);   /*este vai libertar a memória alocada talhão a talhão*/
        }
    }
    free(t); //liberta a memória alocada para o terreno gerado

}

void atribuiTesouroTalhao(terreno t, int linha, int coluna, int tesouro) { //atribui o tesouro a um determinado talhão
    daRiquezaTalhao(t->matriz[linha][coluna], tesouro); //recorrendo à "matriz" e atribuindo
}

int linhaTerreno(terreno t) { //devolve o número de linhas do terreno
    return t->linhas;
}

int colunaTerreno(terreno t) { //devolve o número de colunas do terreno
    return t->colunas;
}

int contaTesourosTerreno(terreno t){ //contabiliza a riqueza total (presente no momento) do terreno
    int i,j, riqueza = 0;

    for(i=0;i<t->linhas;i++){
        for(j=0;j<t->colunas;j++){
            riqueza += riquezaTalhao(t->matriz[i][j]);
        }
    }
    return riqueza;
}

int existeRiquezaTerreno(terreno t, int linha, int coluna) { //averigua se existe riqueza num determinado talhão

    if(riquezaTalhao(t->matriz[linha][coluna])!=0){ //caso exista um valor diferente de 0 no talhão de coordenadas xlinha e ycoluna
        return 1; //valor '1' representativo e meramente orientador, valida a presença de tesouro
    }
    else{ 
        return 0; //valor '0' representativo e meramente orientador, valida a ausência de tesouro
    }
}

void criaEquipaTerreno(terreno t, char * nomeEquipa, int n_membros) { //adiciona uma equipa ao terreno
    equipa p = criaEquipa(nomeEquipa, n_membros); //criação da equipa
    adicionaElemDicionario(t->equipasCompeticao, nomeEquipa, p); //adicionando essa equipa ao dicionário criado para receber as equipas envolvidas no concurso
}

void adicionaMembroEquipaTerreno(terreno t, char * nomeEquipa, char * nomeMembro) { //adicionar membro a uma determinada equipa
    adicionaMembroEquipa(elementoDicionario(t->equipasCompeticao, nomeEquipa), nomeMembro);
}

char * estrelaEquipaTerreno(terreno t, char * nomeEquipa) { //devolve o membro "estrela" de uma determinada equipa
    return estrelaEquipa(elementoDicionario(t->equipasCompeticao, nomeEquipa));
}

int existeEquipaTerreno(terreno t, char * nomeEquipa) { //averigua se a equipa existe no concurso criado
    return existeElemDicionario(t->equipasCompeticao, nomeEquipa);
}

int existeMembroEquipaTerreno(terreno t, char * nomeEquipa, char * nomeMembro) { //averigua se a existe um determinado membro de uma equipa
    return existeMembroEquipa(elementoDicionario(t->equipasCompeticao, nomeEquipa), nomeMembro);
}

void escavarTalhaoTerreno(terreno t, char * nomeEquipa, int x, int y) { //executa a escavação num determinado talhão do terreno
    int n = escavarTalhao(t->matriz[x][y]); //executa a escavação e guarda o valor do tesouro ou do número de escavações já executadas, conforme exista ainda o tesouro ou não, respetivamente
    int penalizacao; //variável auxiliar - irá ditar o número de pontos a penalizar o membro
    equipa p = elementoDicionario(t->equipasCompeticao, nomeEquipa);

    if (!escavacoesTalhao(t->matriz[x][y])) //caso o terreno ainda não tenha sido escavado
        daMeritoUltimoMembroEquipa(p, n); //é atualizado o mérito do membro
    else { //caso contrário,
        penalizacao = escavacoesTalhao(t->matriz[x][y]); //é averiguada qual o número de escavações feitas no talhão
        n = -10 * penalizacao; //para posteriormente x10 e definir o número de pontos a decrementar do mérito do membro
        daMeritoUltimoMembroEquipa(p, n); //atualiza o mérito ao membro
        daPenalizacaoUltimoMembroEquipa(p); //incrementa a penalização ao membro
    }
<<<<<<< HEAD
=======

>>>>>>> 7901ced5c69f66eb044e518b5cd5411df002299d
}

int escavacaoTerreno(terreno t, char * nomeEquipa, int x, int y) { //é averiguado os requisitos para proceder à escavação do terreno, escavação esta na função "escavarTalhaoTerreno"
    equipa p = elementoDicionario(t->equipasCompeticao, nomeEquipa);

    moverMembroEquipa(p, x, y);

    if (posicaoxUltimoMembroEquipa(p) >= t->linhas || posicaoxUltimoMembroEquipa(p) < 0 || posicaoyUltimoMembroEquipa(p) >= t->colunas || posicaoyUltimoMembroEquipa(p) < 0) { //caso o membro se mova para fora do terreno ou em sinal oposto
        tiraLicencaUltimoMembroEquipa(p); //é lhe tirada a licença
        if (!licencaEquipa(p)) { //caso não exista licenças na equipa,
            expulsarEquipa(p); //esta é expulsa
            t->expulsas++; //e é incrementado o número de equipas expulsas do concurso
            return 0; //é devolvido "0" como auxiliar
        } //caso ainda exista licenças,
        proximoEquipa (p); //passamos ao próximo membro da equipa com licença
        return 1; //é devolvido "1" como auxiliar
    }
    else { //caso se mova corretamente
        escavarTalhaoTerreno(t, nomeEquipa, posicaoxUltimoMembroEquipa(p), posicaoyUltimoMembroEquipa(p)); //é escavado o talhão
        proximoEquipa (p); //passamos ao próximo membro da equipa com licença
        return 1; //é devolvido "1" como auxiliar
    }
}

int existeEquipasTerreno(terreno t) { //averigua se ainda existem equipas no terreno
    if (t->expulsas == tamanhoDicionario(t->equipasCompeticao))
        return 0;
    else
        return 1;
}

int equipaExpulsaTerreno(terreno t, char * nomeEquipa) { //devolve o parâmetro de expulsão de uma determinada equipa
    return equipaExpulsa(elementoDicionario(t->equipasCompeticao, nomeEquipa));
}

iterador iteradorEquipas(terreno t) { //devolve um iterador para o dicionário que contém as equipas presentes no concurso
    return iteradorDicionario(t->equipasCompeticao);
}

char * infoSairEquipaTerreno(terreno t, int* pontos, int* desclassificados, int* licenca) { //informa a saída da equipa do terreno, armazenando os dados da mesma
    iterador it = iteradorDicionario(t->equipasCompeticao);
    char * nome = malloc(41*(sizeof(char)));
    int maxClass, minDesc, minLic;
    equipa p;

    while (temSeguinteIterador(it)) {
        p = seguinteIterador(it);
        if (!equipaExpulsa(p)) {
            strcpy(nome, nomeEquipa(p));
            maxClass = classificacaoEquipa(p);
            minDesc = desclassificadosEquipa(p);
            minLic = licencaEquipa(p);
        }
    } 

    destroiIterador(it);
    it = iteradorDicionario(t->equipasCompeticao);

    while (temSeguinteIterador(it)) {
        p = seguinteIterador(it);
        if (!equipaExpulsa(p)) {
            if (classificacaoEquipa(p) > maxClass) {
                strcpy(nome, nomeEquipa(p));
                maxClass = classificacaoEquipa(p);
                minDesc = desclassificadosEquipa(p);
                minLic = licencaEquipa(p);
            }
            else if (classificacaoEquipa(p) == maxClass) {
                if (desclassificadosEquipa(p) < minDesc) {
                    strcpy(nome, nomeEquipa(p));
                    minDesc = desclassificadosEquipa(p);
                    minLic = licencaEquipa(p);
                }
                else if (desclassificadosEquipa(p) == minDesc) {
                    if (licencaEquipa(p) < minLic) {
                        strcpy(nome, nomeEquipa(p));
                        minLic = licencaEquipa(p);
                    }
                    else if (licencaEquipa(p) == minLic) {
                        if (strcmp(nome, nomeEquipa(p)) > 0) {
                            strcpy(nome, nomeEquipa(p));
                        }
                    }
                }
            }
        }
    }
    destroiIterador (it);
    p = elementoDicionario(t->equipasCompeticao, nome);
    expulsarEquipa(p);
    t->expulsas++;
    (*pontos) = classificacaoEquipa(p);
    (*desclassificados) = desclassificadosEquipa(p);
    (*licenca) = licencaEquipa(p);
    return nomeEquipa(p);
}