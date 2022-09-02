#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

#define bool int
#define TRUE 1
#define FALSE 0

#define MAX_WORD_LENGTH 21
#define MAX_TEXT_LENGTH 81
#define MAX_WORD 20

int escolha_user(int *frase_user, int *palavra_user)
{
	__fpurge(stdin);
	printf("\nEscolha um numero de uma frase(1-7):\n");
	scanf(" %d", frase_user);
	printf("\nEscolha uma palavra(1-6):\n");
	scanf(" %d", palavra_user);
	system("clear");
}

void menu(char *fra_menu[], char *pal_menu[])
{
	int inicial;
	printf("\n\n\n\t\t******************\n\t\t*WORK IN PROGRESS*\n\t\t******************\n\n\n");

	printf("\nAs frases presentes no programa:\n\n");
	for(inicial=0; inicial<=6; inicial++)
	{
		printf("%d - %s\n", inicial+1, fra_menu[inicial]);
  	}
	printf("\nAs palavras presentes no programa:\n\n");
	for(inicial=0; inicial<=5; inicial++)
	{
    		printf("%d - %s\n", inicial+1, pal_menu[inicial]);
  	}
}

void ver_se_contem(char **frasecheck, char **palavracheck)
{
	char *verificar;
	verificar = strstr(*frasecheck, *palavracheck);
	if(verificar)
	{
		printf("A palavra '%s' esta presente na frase '%s'", *palavracheck, *frasecheck);
	}
	else
	{
		printf("A palavra '%s' nao esta presente na frase '%s'", *palavracheck, *frasecheck);
	} 
}

int main()
{
	char frase1 [MAX_TEXT_LENGTH] = "A string thats contains a dog and a cat";
	char frase2 [MAX_TEXT_LENGTH] = "A string that contains camel and mouse";
	char frase3 [MAX_TEXT_LENGTH] = "The dog was eating with the horse";
	char frase4 [MAX_TEXT_LENGTH] = "The camel drunk all the water";
	char frase5 [MAX_TEXT_LENGTH] = "The mouse entered into the pipe";
	char frase6 [MAX_TEXT_LENGTH] = "Uma string pode conter dog ou camel";
	char frase7 [MAX_TEXT_LENGTH] = "The horse is bigger than the dog";
	char palavra1 [MAX_WORD_LENGTH] = "dog";
	char palavra2 [MAX_WORD_LENGTH] = "horse";
	char palavra3 [MAX_WORD_LENGTH] = "cat";
	char palavra4 [MAX_WORD_LENGTH] = "mouse";
	char palavra5 [MAX_WORD_LENGTH] = "camel";
	char palavra6 [MAX_WORD_LENGTH] = "pig";

	char *frase_ptr [MAX_WORD];
	char *pal_ptr [MAX_WORD];
	char ** frasecheck, ** palavracheck;
	int frase_user, palavra_user;

	frase_ptr [0] = frase1;
        frase_ptr [1] = frase2;
        frase_ptr [2] = frase3;
        frase_ptr [3] = frase4;
        frase_ptr [4] = frase5;
        frase_ptr [5] = frase6;
        frase_ptr [6] = frase7;
	pal_ptr [0] = palavra1;
        pal_ptr [1] = palavra2;
        pal_ptr [2] = palavra3;
        pal_ptr [3] = palavra4;
        pal_ptr [4] = palavra5;
        pal_ptr [5] = palavra6;

	while(1)
	{
		menu(frase_ptr, pal_ptr);
		escolha_user(&frase_user, &palavra_user);

		frasecheck= &frase_ptr[frase_user-1];
		palavracheck= &pal_ptr[palavra_user-1];
		ver_se_contem(frasecheck, palavracheck);
	}
}
