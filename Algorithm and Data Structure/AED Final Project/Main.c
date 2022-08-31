/**********************************************/
/*****************PROJETO AED******************/
/***********Concurso de Arqueologia************/
/******************Autores*********************/
//       João Antunes - nº62709 - LEEC        //
//     Ricardo Guerra - nº63034 - LEEC        //
/**********************************************/

//Bibliotecas a utilizar no ficheiro Main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "terreno.h"
#include "iterador.h"

//Constantes a utilizar no ficheiro Main.c
#define MAXLINHA 50 //facultativa, meramente para tornar o vetor de caracteres, estático
#define MAXCOLUNA 50
#define HELPER " " //irá ser útil para o nosso interpretador ler cada palavra individualmente

//Protótipos de funções
terreno comecarJogo();

void interpretador(terreno tg);

void cmdRiqueza(terreno tg);

void cmdEstrela(terreno tg, char * nomeEquipa);

void cmdEscavacao(terreno tg, char * nomeEquipa, int x, int y);

void cmdReforco(terreno tg);

void cmdTerreno(terreno tg);

void cmdEquipa(terreno tg, int n_equipa);

void sair(terreno tg);



int main(void) { //função main
    terreno tg = comecarJogo();
    if (tg==NULL) //verificação
        return(0);
    interpretador(tg);
    sair(tg);
    return 1;
}

terreno comecarJogo() { //função para inicializar o jogo
    
    //variáveis a utilizar
    char input[50000], nomeEquipa[MAXLINHA], nomeMembro[MAXLINHA], sposicaoEquipa[MAXLINHA];
    char *token;
    int linhas, colunas, tesouro, n_equipas, n_membros, posicaoEquipa;
    int i, j=0, k;
    terreno tg;
    FILE *teams;
    
    fgets(input, 40, stdin);
    sscanf(input, "%d %d", &linhas, &colunas); //armazenamento do número de linhas e colunas
    tg = criaTerreno(linhas, colunas); //criação do terreno de acordo com o número de linhas e colunas
    
    for(i = 0; i<linhas; i++) {
        fgets(input, 50000, stdin);
        token = strtok(input, HELPER); //a função strktok auxiliará pois na string "token" ficará armazenado o conteúdo da string "input" até ser encontrada o carácter " " armazenado na varíavel "HELPER"
        while(token != NULL) { //verificação
            tesouro = atoi(token); //converte a leitura para um int
            atribuiTesouroTalhao(tg, i, j, tesouro); //atribui os tesouros talhão a talhão
            token = strtok(NULL, HELPER); //atualiza a string "token"
            j++; //incrementa o número de colunas
        }
        j=0;
    }
    //abre o ficheiro teams.txt
    teams = fopen("teams.txt", "r");
    if (teams == NULL) { //verificação da abertura do ficheiro
        printf("Erro a ler o ficheiro\n");
        return NULL;
    }

    fgets(input, 40, stdin);
    n_equipas = atoi(input); 
    criaDicionarioEquipas(tg, n_equipas); //criação do "dicionário" para as equipas, TAD que considerámos mais apropriada por poder ser trabalhada com uma "chave", do tipo inteiro ou string
    fgets(sposicaoEquipa, 40, stdin);
    token = strtok(sposicaoEquipa, HELPER); //atualização da variável "token" com a "posição da equipa"

    for (i=1; i<=n_equipas; i++) {
        j=1;
        posicaoEquipa = atoi(token); 

        while(fgets(input, 40, teams) != NULL) {
            n_membros = atoi(input);
            fgets(input, 40, teams);
            sscanf(input, "%[^\n]",nomeEquipa); //isola o nome da equipa, pois fará a leitura até ser detetado um "\n"
            if(j==posicaoEquipa) {
                criaEquipaTerreno(tg, nomeEquipa, n_membros); //criação da equipa associada a um determinado terreno
            }
            for (k=0; k<n_membros; k++){
                fgets(input, 40, teams);
                sscanf(input, "%[^\n]", nomeMembro); //isola o nome do membro, pois fará a leitura até ser detetado um "\n"
                if (j==posicaoEquipa) {
                    adicionaMembroEquipaTerreno(tg, nomeEquipa, nomeMembro); //adiciona esse membro à respetiva equipa
                }
            }
            j++; //é incrementado a variável auxiliar "j"
        }
        rewind(teams); //voltamos ao início do ficheiro "teams"
        token = strtok(NULL, HELPER); //é "esvaziada" a string "token"
    }
    fclose(teams); //fechamos o ficheiro
    fflush(teams); //e damos "flush" ao buffer
    return tg; //damos return ao terreno criado
}

void interpretador(terreno tg) { //interpretador de comandos
    
    //variáveis a utilizar
    char input[MAXLINHA], cmd[MAXLINHA], nomeEquipa[MAXLINHA];
    int n_equipa, x, y;
    
    //strcpy(cmd, ConverterCmd(cmd));

    do {
        //receção dos comandos
        fgets(input, 100, stdin);
        sscanf(input, "%s", cmd);

        //análise do comando a utilizar
        if(strcmp(cmd, "riqueza")==0) {
            cmdRiqueza(tg);
        }
        else if(strcmp(cmd, "terreno")==0) {
            cmdTerreno(tg);
        }
        else if(strcmp(cmd, "estrela")==0) {
            sscanf(input, "%s %[^\n]", cmd, nomeEquipa);
            cmdEstrela(tg, nomeEquipa);
        }
        else if(strcmp(cmd, "escavacao")==0) {
            
            sscanf(input, "%s %d %d %[^\n]", cmd, &x, &y, nomeEquipa);
            cmdEscavacao(tg, nomeEquipa, x, y);
        }
        else if(strcmp(cmd, "reforco")==0) {
            cmdReforco(tg);
        }
        else if(strcmp(cmd, "equipa")==0) {
            sscanf(input, "%s %d", cmd, &n_equipa);
            cmdEquipa(tg, n_equipa);
        }
        else if (strcmp(cmd, "sair")!=0)
            printf("Comando invalido\n");
    } while(strcmp(cmd, "sair")!=0);
    
}

void cmdRiqueza(terreno tg) { //comando riqueza
    printf("Riqueza enterrada: %d\n", contaTesourosTerreno(tg));
}

void cmdTerreno(terreno tg) { //comando terreno
    int i, j;

    for(i=0; i<linhaTerreno(tg); i++) { //por cada linha do terreno
        for(j=0; j<colunaTerreno(tg); j++) { //e cada coluna do terreno
            if (existeRiquezaTerreno(tg, i, j)) //caso exista riqueza
                printf("*"); //é realizado o print de um "*"
            else //caso não exista riqueza nesse talhão
                printf("-"); //é realizado o print de um "-"
        }
        printf("\n"); //é executado um "\n" quando se conclui a análise de uma linha
    }
}

void cmdEstrela(terreno tg, char * nomeEquipa) { //comando estrela
    if(existeEquipaTerreno(tg, nomeEquipa) && !equipaExpulsaTerreno(tg, nomeEquipa)) //caso a equipa esteja presente no concurso gerado e não tenha sido expulsa
        printf("Estrela de %s: %s\n", nomeEquipa, estrelaEquipaTerreno(tg, nomeEquipa)); //o print é realizado com o nome da equipa e o respetivo membro "estrela"
    else //caso não se cumpra,
        printf("Equipa invalida\n"); //a equipa não cumpre as características necessárias
}

void cmdEscavacao(terreno tg, char * nomeEquipa, int x, int y) { //comando escavação
    if (x==0 && y==0) //caso as coordenadas "x" e "y" impostas pelo utilizado sejam ambas "0"
        printf("Salto invalido\n"); //o salto é inválido
    else if (!existeEquipaTerreno(tg, nomeEquipa) || equipaExpulsaTerreno(tg, nomeEquipa)) //caso a equipa não esteja presente no concurso ou já tenha sido expulsa
        printf("Equipa invalida\n"); //a equipa não cumpre as características necessárias
    else { //caso contrário,
        if(!escavacaoTerreno(tg, nomeEquipa, x, y)) //é executada a escavação do terreno, porém, não cumprindo os requisitos
            printf("%s foi expulsa\n", nomeEquipa); //a equipa será expulsa do concurso
    }
}

void cmdReforco(terreno tg) { //comando reforço
    char input[MAXLINHA], nomeEquipa[MAXLINHA], nomeMembro[MAXLINHA];

    fgets(input, 40, stdin);
    sscanf(input, "%[^\n]", nomeEquipa);
    fgets(input, 40, stdin);
    sscanf(input, "%[^\n]", nomeMembro);

    if (!existeEquipaTerreno(tg, nomeEquipa))
        printf("Equipa invalida\n");
    else if (existeMembroEquipaTerreno(tg, nomeEquipa, nomeMembro))
        printf("Arqueologo invalido\n");
    else
        adicionaMembroEquipaTerreno(tg, nomeEquipa, nomeMembro);
}

void cmdEquipa(terreno tg, int n_equipa) { //comando equipa
    
    //variáveis a utilizar
    char input[MAXLINHA], nomeEquipa[MAXLINHA], nomeMembro[MAXLINHA];
    int n_membros, i=1, j, existe = 0, criou = 0;
    FILE *teams;

    //abertura do ficheiro
    teams = fopen("teams.txt", "r");
    if (teams == NULL) { //verificação
        printf("Erro a ler o ficheiro\n");
    }
    else { //caso tenha sido aberto com sucesso
        while(fgets(input, 40, teams) != NULL) { //enquanto forem ocorridas com sucesso as respetivas leituras
            n_membros = atoi(input);
            fgets(input, 40, teams);
            sscanf(input, "%[^\n]",nomeEquipa); //as equipas serão lidas individualmente
            if(i==n_equipa) {
                existe = 1; //caso se comprove que ela existe no terreno
                if(!existeEquipaTerreno(tg, nomeEquipa)) {
                    criaEquipaTerreno(tg, nomeEquipa, n_membros); //essa equipa é criada
                    criou++; //confirma que a equipa foi criada
                }
            }
            for (j=0; j<n_membros; j++){
                fgets(input, 40, teams);
                sscanf(input, "%[^\n]", nomeMembro); //e cada membro será lido individualmente
                if (i==n_equipa && criou) {
                    adicionaMembroEquipaTerreno(tg, nomeEquipa, nomeMembro); //com sucesso, será adicionado o membro à equipa
                }
            }
            i++;
        }
        fclose(teams); //fechamos o ficheiro
        fflush(teams); //e damos "flush" ao buffer
    }
    if (existe && !criou) //caso a equipa não cumpra os parâmetros para ser adicionada
        printf("Equipa invalida\n");
    else if (!existe) //caso a equipa não exista
        printf("Equipa inexistente\n");
}

void sair(terreno tg) { //comando sair

    char * nomeEquipa = malloc(41*(sizeof(char)));
    int pontos, desclassificados, licenca;

    if (!existeEquipasTerreno(tg)) //caso já não existisse equipas no terreno
        printf("Todas as equipas foram expulsas.\n"); //todas foram expulsas
    else { //caso ainda existam,
        if(contaTesourosTerreno(tg)) //mas os tesouros não foram todos descobertos
            printf("Ainda havia tesouros por descobrir...\n"); //ainda haviam equipas presentes e tesouros por descobrir
        else //caso contrário, não haviam mais tesouros a descobrir
            printf("Todos os tesouros foram descobertos!\n");
        printf("classificacao\n");
        while(existeEquipasTerreno(tg)) { //recolha dos dados para exibir (de cada equipa) a sua classificação, número de desclassificados e número de licenças ativas
            strcpy(nomeEquipa, infoSairEquipaTerreno(tg, &pontos, &desclassificados, &licenca));
            printf("%s: %d pts; %d descl.; %d com lic.\n", nomeEquipa, pontos, desclassificados, licenca);
        }
    }
}