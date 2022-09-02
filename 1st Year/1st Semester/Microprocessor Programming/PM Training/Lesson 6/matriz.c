#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

void escrever_coluna(char matriz[][20])
{
    int c=0;
    char x;
    __fpurge(stdin);
    printf("\nQue caracter que inserir?\n");
    scanf("%c",&x);
    printf("\nTabom chefe. Em que coluna?\n");
    scanf("%d",&c);
    for (int i=0;i<19;i++)
    {
        matriz[i][c-1]= x;
    }
}

void escrever_linha(char matriz[][20])
{
    int l=0;
    char x;
    __fpurge(stdin);
    printf("\nQue caracter que inserir?\n");
    scanf("%c",&x);
    printf("\nEm que linha?\n");
    scanf("%d",&l);
    for (int c=0;c<19;c++)
    {
        matriz[l][c]= x;
    }
}

void escrever_diagonal(char matriz[][20])
{
    printf("\nOk chefe, eu trato disso!\n");
    int i=0, j=0;
    int diagonal;
    char char1;

	__fpurge(stdin);
	printf ("\nQual o caractere que queres substituir?\n");
	scanf (" %c", &char1);
	printf ("\nOtimo. Agora qual a diagonal que desejas substituir entre -19 e 19: ");
	scanf (" %d", &diagonal);
	if (diagonal < 0)
	{
		i -= diagonal;
	}
	else
	{
		j += diagonal;
	}
	for ( ; i <= 19 && j <= 19; i++, j++)
		matriz[i][j] = char1;
}

void limpa_matriz(char matriz[][20])
{
    int i,j;
    char char2;
    __fpurge(stdin);
    printf("\nQue caracter que inserir?\n");
    scanf("%c",&char2); 

    for(i=0;i<=19;i++)
    {
	for(j=0;j<=20;j++)
	{
		printf(" %c", matriz[i][j]);
	}
        putchar('\n');
    }
    printf("\n\nSubstituicao terminada.\n\n");
}

void escrever_matriz(char matriz[][20])
{
	int i, j;

	for (i = 0; i <= 19; i++)
	{	for (j = 0; j <= 19; j++)
		{
			printf (" %c", matriz[i][j]);
		}
		printf("\n");
	}
}

void matriz_inicial(char matriz[][20])
{
   char nul='0';
   int i, j;
   for(i=0;i<=19;i++)
   {
	for(j=0;j<=20;j++)
	{
		matriz[i][j]=nul;
	}
   }
}

char  menu()
{
    char opc;
    char matriz[20][20];
    do
    {
        printf("\n1-escrever linha\n2-escrever coluna\n3-escrever diagonal\n4-limpar matriz\n5-escrever a matriz\ns-sair");
        printf("\nO que deseja fazer?");
        scanf(" %c",&opc);
        __fpurge(stdin);
	if(((int)opc<49 || (int)opc>53) && opc !='s')
	{
		continue;
	}
	else
	{
		return opc;
	}
    }
    while(1);
}

int main()
{
	
	char matriz[20][20];
	char opc;
	printf("\n\t\t||BEM-VINDO AO PROGRAMA LINHA||\n");
	matriz_inicial(matriz);
   do
   {
	opc=menu();
	switch(opc) 
        {
            case '1':
                escrever_linha(matriz);
                break;
            case '2':
                escrever_coluna(matriz);
                break;
            case '3':
                escrever_diagonal(matriz);
                break;
            case '4':
                limpa_matriz(matriz);
                break;
            case '5':
                escrever_matriz(matriz);
                break;
            case 's':
                printf("\nFoi bom ter te aqui camarada.\n");
                exit(1);
	}
   while(1);
}
