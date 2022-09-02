#include <stdio.h>

int main()
{
	unsigned int ano1=0, mes1=0, dia1=0;
	unsigned int ano2=0, mes2=0, dia2=0;

	printf("Escreva para a data1 o dia, mês e ano como inteiros: ");
	scanf(" %u %u %u", &dia1, &mes1, &ano1);
	printf("Escreva para a data2 o dia, mês e ano como inteiros: "); 
        scanf(" %u %u %u", &dia2, &mes2, &ano2);
	printf("A data1 corresponde a %u %u %u.", dia1, mes1, ano1); 
	printf("\nA data2 corresponde a %u %u %u.", dia2, mes2, ano2);
	if(ano1<ano2)
	{
	printf("\nA data2 é mais recente que a data1.\n");
	}
	else
		if(ano1>ano2)
		{
		printf("\nA data1 é mais recente que a data2.\n");
		}
		else
			if(mes1<mes2)
			{
			printf("\nA data2 é mais recente que a data1.\n");
			}
			else
				if(mes1>mes2)
				{
				printf("A data 1 é mais recente que a data2.\n");
				}
				else	
					if(dia1<dia2)
					{
					printf("\nA data2 é mais recente que a data1.\n");
					}
					else
						if(dia1>dia2)
						{
						printf("\nA data1 é mais recente que a data2.\n");
						}
						else
						printf("\nAs datas são iguais.\n");
 
}
