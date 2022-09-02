#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define CONSTANTE   1

void titulo()
{	printf ("\n*JOGO DO SOBE E DESCE*\n");
}

int opcao()
{	int opcao1;

	do
	{	printf ("Valores por sorteio (1) ou manuais(2): ");
		scanf (" %d", &opcao1);
		if (opcao1 < 1 || opcao1 > 2)
		{	printf ("Erro na introducao de dados");
			continue;
		}
		else
			return opcao1;
	}
	while (1);
}

int aleatorio(int min, int max)
{	int randm;

	srand (time(NULL));
	randm = (rand() % (max - min + 1) + min);
	return randm;
}

int nivel()
{	int nivel1;

	do
	{	printf ("Escolha o nivel de jogo\n Nivel 1: entre 1 e 100\n Nivel 2: entre 1 e 1000\n Nivel 3: entre 1 e 10000\n\n Sua opcao: ");
		scanf (" %d", &nivel1);
		if (nivel1 > 3 || nivel1 < 1)
		{	printf ("Erro na introducao de dados");
			continue;
		}
		else
			return nivel1;
	}
	while (1);
}

int tent_conv(int op_tent)
{	int tent;

	switch (op_tent)
	{	
		case 1: tent = 10; break;
		case 2: tent = 15; break;
		case 3: tent = 20; break;
	}
	return tent;
}

int tentativas()
{	int op_tent, tent;

	do
	{	printf ("Escolha a opcao de maximo de tentativas\n Opcao 1: 10 tentativas\n Opcao 2: 15 tentativas\n Opcao 3: 20 tentativas\n\n Sua opcao: ");
		scanf (" %d", &op_tent);
		if (op_tent > 3 || op_tent < 1)
		{	printf ("Erro na introdução de dados\n");
			continue;
		}
		else
			break;
	}
	while (1);

	switch (op_tent)
	{	case 1: tent = 10; break;
		case 2: tent = 15; break;
		case 3: tent = 20; break;
	}
	return tent;
}

int maximo(int nivel1)
{	int max;
	switch (nivel1)
	{	case 1: max = 100; break;
		case 2:	max = 1000; break;
		case 3: max = 10000; break;
	}
	return max;
}

int numero(int max)
{	int num;

	do
	{	printf ("Insira o numero misterio, no intervalo entre 1 e %d: ", max);
		scanf (" %d", &num);
		if (num < 1 || num > max)
		{	printf ("Erro na introducao de dados\n");
			continue;
		}
		else
			return num;
	}
	while (1);
}

void jogo(int nivel1, int num, int tent, int max)
{
    int i, num_tent;

	printf ("Estamos a jogar com o nivel %d (1 a %d) e com um maximo de %d tentativas.\n\n", nivel1, max, tent);
	for (i = 1, tent -= 1; tent >= 0; tent--, i++)
	{	printf ("Diga um numero: ");
		scanf (" %d", &num_tent);
		if (num_tent > num)
			printf ("\nO numero misterio esta abaixo.\nAinda tem %d tentativas.\n", tent);
		else
		{	if (num_tent < num)
				printf ("\nO numero misterio esta acima.\nAinda tem %d tentativas.\n", tent);
			else
			{
			    printf ("\nParabens!\nAcertou em %d tentativas.\n", i);
			}
		}
	}
	printf ("Perdeu o jogo!\nEsgotou todas as tentativas.\n\n");
}

int final()
{
    char resp;

	printf ("Quer jogar outra vez (s ou n): ");
	scanf (" %c", &resp);
	return resp;
}

int main()
{	int num, max, nivel1, tent, opcao1, op_tent;
	char cont;

	do
	{	titulo();
                if (opcao() == CONSTANTE)
		{	nivel1 = aleatorio(1,3);
			max = maximo(nivel1);
			num = aleatorio (1,max);
			op_tent = aleatorio (1,3);
			tent = tent_conv(op_tent);
		}
		else
		{	nivel1 = nivel();
			max = maximo (nivel1);
			tent = tentativas();
			num = numero (max);
		}
		system ("clear");
		jogo (nivel1, num, tent, max);
		cont = final();
		if (cont == 'n')
		{
			printf ("Obrigado e adeus.\n");
			exit(1);
		}
	}
	while(1);
}
