/*************************bibliotecas a utilizar*******************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio_ext.h>
#include <string.h>
/************************constantes a utilizar*********************************/
#define TAM_AVIAO_MAX 200
#define TAM_FILA_MAX 7
/************************estruturas a utilizar*********************************/
typedef struct
{
    char occupied;
    char name[100];
    char checked_in;
    int id_luggage;
    int id_reservation_code;
}passageiro;

typedef struct
{
  passageiro auxiliar;
  char letra_da_posicao[TAM_AVIAO_MAX];
}posicao_do_voo;

typedef struct
{
  int lugares_executivos;
  int lugares_turisticos;
  int numero_de_filas;
}lugares_por_fila;
/******************************funcao random***********************************/
int randm(int min, int max)
{
  int valor_random;

  srand(time(NULL));
  valor_random=(rand()%(max-min+1)+min);

  return valor_random;
}
/*************************Contar lugares no aviao******************************/
lugares_por_fila contabilizar(int aviao_modelo)
{
  FILE *fp;
  int i,filas_executivas=0,filas_turisticas=0;
  char compare, aviao_nome[15],modelo_apresentado[TAM_AVIAO_MAX][TAM_FILA_MAX],comparativo[10]="abcd";
  lugares_por_fila aviao_selecionado;

  /*copiar o int para a string*/
  sprintf(aviao_nome,"Airbus%d",aviao_modelo);

  fp = fopen(aviao_nome,"r");

  if(fp==NULL)
  {
    printf("\nErro na leitura do ficheiro.\n");
    exit(1);
  }

  aviao_selecionado.numero_de_filas=0;
  aviao_selecionado.lugares_executivos=0;
  aviao_selecionado.lugares_turisticos=0;

  /*averiguar o termino duma linha*/
  for(compare=getc(fp);compare!=EOF;compare=getc(fp))
  {
    if(compare=='\n')
    {
      aviao_selecionado.numero_de_filas++;
    }
  }
  fclose(fp);
  fflush(fp); /*vai possiblitar a leitura do ficheiro num outro sitio pois essa informacao vai levar "flush" para o ficheiro*/

  fp = fopen(aviao_nome,"r");

  for(i=0;i<aviao_selecionado.numero_de_filas;i++)
  {
    while(fscanf(fp, "%s", modelo_apresentado[i])!=EOF)
    {
      if(strcmp(comparativo,modelo_apresentado[i])==0)
      {
        filas_executivas++;
      }
      else
      {
        filas_turisticas++;
      }
      putchar('\n');
    }
  }

  fclose(fp);
  fflush(fp);

  aviao_selecionado.lugares_executivos=filas_executivas*4;
  aviao_selecionado.lugares_turisticos=filas_turisticas*6;

  return aviao_selecionado;
}
/***********************mostrar ocupacao de um voo*****************************/
void mostrar_ocupacao()
{
  FILE *fp;
  int i, j,conta_exec=0, conta_tur=0, comprimento_nome_ficheiro, n_aviao, n_filas_exec=0;
  char confirmacao, verificacao_enter,nome_do_voo[100];
  posicao_do_voo lugar_do_voo;
  lugares_por_fila aviao_selecionado;

  do
  {
    system("clear");
    printf("\t\t FICHEIROS DE VOO\n\t\t   TuninhoVoa\n");
    /*SELECIONA-SE O NOME DO VOO*/
    printf("\nQual o voo que deseja ver a ocupacao?\n");
    printf("\nA sua opçao:\n");
    scanf(" %s", nome_do_voo);
    /*definir o comprimento do nome do voo*/
    comprimento_nome_ficheiro=strlen(nome_do_voo);
    /**************************************************/
    system("clear");
    __fpurge(stdin);

    printf("\nO nome do ficheiro que deseja ver a ocupacao e:\n");
    for(i=0;i<comprimento_nome_ficheiro;i++)
    {
      printf("%c",nome_do_voo[i]);
    }
    printf("\nDeseja verificar a ocupacao deste voo? (s) ou (n)\n");
    scanf(" %c", &confirmacao);
    switch(confirmacao)
    {
      case 's':
      case 'S':
                continue;
      case 'n':
      case 'N':
                return;
      default:
                printf("\nIntroduza uma opcao valida.\n");
    }
  }
  while(confirmacao!='s' && confirmacao!='S');
  fp = fopen(nome_do_voo,"rb");
  if(fp==NULL)
  {
    system("clear");
    printf("Nao foi possivel abrir a estrutura do modelo solicitado.\n\n");
    __fpurge(stdin);
    printf("\n\nPressione ENTER para fechar o programa.");
    scanf("%[^\n]c", &verificacao_enter);
    exit(1);
  }
  system("clear");

  fread(&n_aviao,sizeof(int),1,fp); /*ler o ficheiro de voo para averiguar qual o modelo do aviao*/

  aviao_selecionado=contabilizar(n_aviao);

  n_filas_exec=aviao_selecionado.lugares_executivos/4;

  for(i=0;i<aviao_selecionado.lugares_executivos;i++)
  {
    /*ficheiro,caminho a seguir em bits (1º tamanho da estrutura do pp em bits * 2º quantidade de vezes que iremos saltar esse tamanho de bits + tamanho de bits do primeiro int de modo a ignorarmos A318,A319...),SEEK_SET*/
    fseek(fp,sizeof(lugar_do_voo.auxiliar)*i+sizeof(int),SEEK_SET);
    /*a estrutura onde quero guardar dados, tamanho da estrutura do pp em bits, quantas vezes e que desejo ler esse tamanho de bits, e qual o pointer para o ficheiro*/
    fread(&lugar_do_voo.auxiliar,sizeof(lugar_do_voo.auxiliar),1,fp);

    if(lugar_do_voo.auxiliar.occupied!=0)
    {
      lugar_do_voo.letra_da_posicao[i]='.';
      conta_exec++;
      continue;
    }
    switch(i%4)
    {
      case 0: lugar_do_voo.letra_da_posicao[i]='a'; break;
      case 1: lugar_do_voo.letra_da_posicao[i]='b'; break;
      case 2: lugar_do_voo.letra_da_posicao[i]='c'; break;
      case 3: lugar_do_voo.letra_da_posicao[i]='d'; break;
    }
  }
  for(i=aviao_selecionado.lugares_executivos;i<aviao_selecionado.lugares_turisticos;i++)
  {
    fseek(fp,sizeof(lugar_do_voo.auxiliar)*i+sizeof(int),SEEK_SET);

    fread(&lugar_do_voo.auxiliar,sizeof(lugar_do_voo.auxiliar),1,fp);

    if(lugar_do_voo.auxiliar.occupied!=0)
    {
      lugar_do_voo.letra_da_posicao[i]='.';
      conta_tur++;
      continue;
    }
    switch(i%6)
    {
      case 0: lugar_do_voo.letra_da_posicao[i]='a'; break;
      case 1: lugar_do_voo.letra_da_posicao[i]='b'; break;
      case 2: lugar_do_voo.letra_da_posicao[i]='c'; break;
      case 3: lugar_do_voo.letra_da_posicao[i]='d'; break;
      case 4: lugar_do_voo.letra_da_posicao[i]='e'; break;
      case 5: lugar_do_voo.letra_da_posicao[i]='f'; break;
    }
  }

  for(i=0,j=1;i<aviao_selecionado.lugares_executivos;i+=4)
  {
    printf(" %c%c 0%d %c%c",lugar_do_voo.letra_da_posicao[i],lugar_do_voo.letra_da_posicao[i+1],j,lugar_do_voo.letra_da_posicao[i+2],lugar_do_voo.letra_da_posicao[i+3]);
    j++;
    putchar('\n');
  }
  for(i=0,j=n_filas_exec+1;i<aviao_selecionado.lugares_turisticos;i+=6)
  {
    if(j<10)
    {
      printf("%c%c%c 0%d %c%c%c",lugar_do_voo.letra_da_posicao[i],lugar_do_voo.letra_da_posicao[i+1],lugar_do_voo.letra_da_posicao[i+2],j,lugar_do_voo.letra_da_posicao[i+3],lugar_do_voo.letra_da_posicao[i+4],lugar_do_voo.letra_da_posicao[i+5]);
      j++;
      putchar('\n');
    }
    else
    {
      printf("%c%c%c %d %c%c%c",lugar_do_voo.letra_da_posicao[i],lugar_do_voo.letra_da_posicao[i+1],lugar_do_voo.letra_da_posicao[i+2],j,lugar_do_voo.letra_da_posicao[i+3],lugar_do_voo.letra_da_posicao[i+4],lugar_do_voo.letra_da_posicao[i+5]);
      j++;
      putchar('\n');
    }
  }
  fclose(fp);
  printf("\n\nEis a ocupacao do voo.\nOnde estiverem '.' e porque existe um lugar ocupado.\n\n\nExiste um total de %d lugares ocupados:\n  %d em classe executiva;\n  %d em classe turistica;", conta_exec+conta_tur, conta_exec, conta_tur);
  __fpurge(stdin);
  printf("\n\nPressione ENTER para retornar ao menu principal.");
  scanf("%[^\n]c", &verificacao_enter);
}
/************************efetuar reserva de um voo*****************************/
void mostrar_reservas()
{
  FILE *fp;
  int i, j, comprimento_nome_ficheiro, n_aviao, n_filas_exec=0;
  char confirmacao, verificacao_enter,nome_do_voo[100];
  posicao_do_voo lugar_do_voo;
  lugares_por_fila aviao_selecionado;

  do
  {
    system("clear");
    printf("\t\t RESERVAS NO VOO\n\t\t   TuninhoVoa\n");
    /*SELECIONA-SE O NOME DO VOO*/
    printf("\nQual o voo que deseja ver as reservas?\n");
    printf("\nA sua opçao:\n");
    scanf(" %s", nome_do_voo);
    comprimento_nome_ficheiro=strlen(nome_do_voo);
    /**************************************************/
    system("clear");
    __fpurge(stdin);

    printf("\nO nome do ficheiro que deseja ver a ocupacao e:\n");
    for(i=0;i<comprimento_nome_ficheiro;i++)
    {
      printf("%c",nome_do_voo[i]);
    }
    printf("\nDeseja verificar as reservas associadas a este voo? (s) ou (n)\n");
    scanf(" %c", &confirmacao);
    switch(confirmacao)
    {
      case 's':
      case 'S':
                continue;
      case 'n':
      case 'N':
                return;
      default:
                printf("\nIntroduza uma opcao valida.\n");
    }
  }
  while(confirmacao!='s' && confirmacao!='S');
  fp = fopen(nome_do_voo,"rb");
  if(fp==NULL)
  {
    system("clear");
    printf("Nao foi possivel abrir a estrutura do modelo solicitado.\n\n");
    __fpurge(stdin);
    printf("\n\nPressione ENTER para sair do programa.");
    scanf("%[^\n]c", &verificacao_enter);
    exit(1);
  }
  system("clear");

  fread(&n_aviao,sizeof(int),1,fp);

  aviao_selecionado=contabilizar(n_aviao);

  n_filas_exec=aviao_selecionado.lugares_executivos/4;

  printf("Passageiros de classe executiva:\n");
  printf("\nCOLUNA   FILA    NOME\n");
  for(i=0,j=1;i<aviao_selecionado.lugares_executivos;i++)
  {
    /*ficheiro,caminho a seguir em bits (1º tamanho da estrutura do pp em bits * 2º quantidade de vezes que iremos saltar esse tamanho de bits + tamanho de bits do primeiro int de modo a ignorarmos A318,A319...),SEEK_SET*/
    fseek(fp,sizeof(lugar_do_voo.auxiliar)*i+sizeof(int),SEEK_SET);
    /*a estrutura onde quero guardar dados, tamanho da estrutura do pp em bits, quantas vezes e que desejo ler esse tamanho de bits, e qual o pointer para o ficheiro*/
    fread(&lugar_do_voo.auxiliar,sizeof(lugar_do_voo.auxiliar),1,fp);

    switch(i%4)
    {
      case 0: lugar_do_voo.letra_da_posicao[i]='a'; break;
      case 1: lugar_do_voo.letra_da_posicao[i]='b'; break;
      case 2: lugar_do_voo.letra_da_posicao[i]='c'; break;
      case 3: lugar_do_voo.letra_da_posicao[i]='d'; break;
    }
    if(lugar_do_voo.auxiliar.occupied!=0)
    {
      printf("%c         0%d     %s\n",lugar_do_voo.letra_da_posicao[i],j,lugar_do_voo.auxiliar.name);
      continue;
    }
  }

  printf("\n\nPassageiros de classe turistica:\n");
  printf("\nCOLUNA   FILA    NOME\n");
  for(i=aviao_selecionado.lugares_executivos,j=n_filas_exec;i<aviao_selecionado.lugares_turisticos;i++)
  {
    fseek(fp,sizeof(lugar_do_voo.auxiliar)*i+sizeof(int),SEEK_SET);

    fread(&lugar_do_voo.auxiliar,sizeof(lugar_do_voo.auxiliar),1,fp);

    switch(i%6)
    {
      case 0: lugar_do_voo.letra_da_posicao[i]='a'; break;
      case 1: lugar_do_voo.letra_da_posicao[i]='b'; break;
      case 2: lugar_do_voo.letra_da_posicao[i]='c'; break;
      case 3: lugar_do_voo.letra_da_posicao[i]='d'; break;
      case 4: lugar_do_voo.letra_da_posicao[i]='e'; break;
      case 5: lugar_do_voo.letra_da_posicao[i]='f'; break;
    }
    if(lugar_do_voo.auxiliar.occupied!=0)
    {
      if(j<10)
      {
        printf("%c         0%d     %s\n",lugar_do_voo.letra_da_posicao[i],j,lugar_do_voo.auxiliar.name);
        continue;
      }
      else
      {
        printf("%c         %d     %s\n",lugar_do_voo.letra_da_posicao[i],j,lugar_do_voo.auxiliar.name);
        continue;
      }
    }
  }
  fclose(fp);
  printf("\n\nEis as reservas associadas a este voo.\nOnde estavam '.' foram retirados os dados do lugar por corresponder a uma reserva.\n");
  __fpurge(stdin);
  printf("\n\nPressione ENTER para retornar ao menu principal.");
  scanf("%[^\n]c", &verificacao_enter);
}
/***************************criacao de um voo**********************************/
void atribuir_voo()
{
  FILE *fp;
  int i, modelo, n_filas, lugares_totais, comprimento_nome_ficheiro=0;
  char escolha_modelo_aviao, confirmacao, verificacao_enter, escolha_nome_ficheiro[100];
  lugares_por_fila aviao_selecionado;

  do
  {
    system("clear");
    printf("\t\t CRIACAO DO VOO\n\t\t   TuninhoVoa\n");
    /*SELECIONA-SE O NOME DO FICHEIRO*/
    printf("\nEscolha o nome do seu voo.\n");
    printf("\nA sua opçao:\n");
    scanf(" %s", escolha_nome_ficheiro);
    comprimento_nome_ficheiro=strlen(escolha_nome_ficheiro);
    /**************************************************/
    system("clear");
    __fpurge(stdin);
    do
    {
      printf("\nO nome atribuido ao ficheiro foi:\n");
      for(i=0;i<comprimento_nome_ficheiro;i++)
      {
        printf("%c",escolha_nome_ficheiro[i]);
      }
      printf("\nDeseja criar o ficheiro? (s) ou (n)\n");
      scanf(" %c", &confirmacao);
      {
        if(confirmacao=='s' || confirmacao=='S')
        {
          continue;
        }
        else
        {
          return;
        }
      }
    }
    while(confirmacao!='s' && confirmacao!='S');
    system("clear");
    putchar('\n');
    printf("\n\t\t MODELOS DE AVIAO\n\t\t   TuninhoVoa\n");
    /*SELECIONA-SE O MODELO*/
    printf("\n1 - AIRBUS 318\n2 - AIRBUS 319\n3 - AIRBUS 320\n4 - AIRBUS 321\n5 - Retornar ao menu principal");
    /**************************************************/
    printf("\n\nEscolha o modelo ao qual quer associar o seu voo.\n");
    scanf(" %c", &escolha_modelo_aviao);

    switch(escolha_modelo_aviao)
    {
      case '1': modelo=318; break;
      case '2': modelo=319; break;
      case '3': modelo=320; break;
      case '4': modelo=321; break;
      case '5': return;
      default: printf("\nPor favor introduza uma opçao valida.\n");
    }
  }
  while(escolha_modelo_aviao<1 && escolha_modelo_aviao>5);

  aviao_selecionado=contabilizar(modelo);

  n_filas=aviao_selecionado.numero_de_filas;
  lugares_totais=aviao_selecionado.lugares_turisticos+aviao_selecionado.lugares_executivos;

  fp = fopen(escolha_nome_ficheiro,"wb");

  fwrite(&modelo,sizeof(int),1,fp);

  /*este for ira criar estruturas individuais para cada lugar, inicializando com '0'*/
  for(i=0;i<lugares_totais;i++)
  {
    passageiro lugar_individual;

    lugar_individual.occupied=0;
    lugar_individual.name[100]='\0';
    lugar_individual.checked_in=0;
    lugar_individual.id_luggage=0;
    lugar_individual.id_reservation_code=0;

    fwrite(&lugar_individual,sizeof(passageiro),1,fp);
  }
  fclose(fp);

  printf("O ficheiro criado esta associado ao aviao Airbus%d e tem %d filas e um total de %d lugares (vazios).",modelo,n_filas,lugares_totais);
  __fpurge(stdin);
  printf("\n\nPressione ENTER para retornar ao menu principal.");
  scanf("%[^\n]c", &verificacao_enter);
}
/**********************Mostrar estrutura do aviao******************************/
void estruturamenu()
{
  FILE *fp;
  char escolha_estrutura, verificacao_enter, comparativo[10]="abcd",modelo_apresentado[TAM_AVIAO_MAX][TAM_FILA_MAX];
  int i, n_aviao=0,n_filas=0,n_filas_tur=0,n_filas_exec=0;
  lugares_por_fila aviao_selecionado;

  system("clear");

  do
  {
    printf("\t\t MODELOS DE AVIAO\n\t\t   TuninhoVoa\n");
    /*SELECIONA-SE O MODELO*/
    printf("\n1 - AIRBUS 318\n2 - AIRBUS 319\n3 - AIRBUS 320\n4 - AIRBUS 321\n5 - Retornar ao menu principal");
    /**************************************************/
    printf("\nA sua opçao:\n");
    scanf(" %c", &escolha_estrutura);
    switch(escolha_estrutura)
    {
      case '1': fp = fopen("Airbus318","r"); n_aviao=318; break;
      case '2': fp = fopen("Airbus319","r"); n_aviao=319; break;
      case '3': fp = fopen("Airbus320","r"); n_aviao=320; break;
      case '4': fp = fopen("Airbus321","r"); n_aviao=321; break;
      case '5': return;
      default: printf("\nPor favor introduza uma opçao valida.\n");
    }
    if(fp==NULL)
    {
      printf("Nao foi possivel abrir a estrutura do modelo solicitado.\n");
      continue;
    }
  }
  while(escolha_estrutura<1 && escolha_estrutura>5);

  aviao_selecionado=contabilizar(n_aviao);

  n_filas=aviao_selecionado.numero_de_filas;
  n_filas_tur=aviao_selecionado.lugares_turisticos/6;
  n_filas_exec=aviao_selecionado.lugares_executivos/4;

  system("clear");
  printf("\nO ficheiro do aviao foi aberto com sucesso.\n\n\n");
  for(i=0;i<n_filas+1;i++)
  {
    while(fscanf(fp, "%s", modelo_apresentado[i])!=EOF)
    {
      if(strcmp(comparativo,modelo_apresentado[i])==0)
      {
        printf(" %s",modelo_apresentado[i]);
      }
      else
      {
        printf("%s",modelo_apresentado[i]);
      }
    putchar('\n');
    }
  }
  fclose(fp);

  printf("\nO modelo Airbus%d possui:\n\n %d filas de classe executiva (%d lugares);\n %d filas de classe turistica (%d lugares);\n\nTotal: %d lugares\n",n_aviao,n_filas_exec,aviao_selecionado.lugares_executivos,n_filas_tur,aviao_selecionado.lugares_turisticos,aviao_selecionado.lugares_turisticos+aviao_selecionado.lugares_executivos);

  __fpurge(stdin);
  printf("\n\nPressione ENTER para retornar ao menu principal.");
  scanf("%[^\n]c", &verificacao_enter);
}
/***************************menu da aplicacao**********************************/
void printmenu()
{
  int escolha_exemplo;

  do
  {
    system("clear");
    printf("\t\t COMPANHIA AEREA\n\t\t     TuninhoVoa\n");
    /*GRUPO 1 - MANIPULACAO BASICA DE FICHEIROS E VISUALIZACAO SIMPLES DE INFORMACAO*/
    printf("\n0 - Sair\n1 - Mostrar a estrutura de um aviao\n2 - Mostrar a ocupacao de um voo\n3 - Mostrar o nome dos passageiros com reserva num voo\n");
    /*GRUPO 2 - TRATAMENTO ELABORADO DE INFORMACAO*/
    printf("6 - Atribuir um aviao a um voo (abertura de voo)\n");
    /**************************************************/
    printf("\nA sua opçao:\n");
    scanf(" %d", &escolha_exemplo);
    if(escolha_exemplo<0 ||escolha_exemplo>9)
    {
      continue;
    }
    switch(escolha_exemplo)
    {
      /*GRUPO 1*/
      case 0: printf("\nSaindo do programa, obrigado.\n"); exit(1);
      case 1: estruturamenu(); break;
      case 2: mostrar_ocupacao(); break;
      case 3: mostrar_reservas(); break;

      /*GRUPO 2*/
      case 6: atribuir_voo(); break;
    }
  }
  while(escolha_exemplo!=0);
}
/******************************funcao main*************************************/
int main()
{
  printmenu();
}
