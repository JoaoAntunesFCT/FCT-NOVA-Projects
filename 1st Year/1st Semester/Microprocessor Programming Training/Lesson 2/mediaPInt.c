#include <stdio.h>

int main() 
{
	const int  NUMERO=3;
	double val11=0, val12=0, val13=0;
	double total;
	long int  media;
	double resto;
	
	printf("Introduza os três valores:");
	scanf(" %lf %lf %lf", &val11, &val12, &val13);

	total=val11+val12+val13;
	media=total/NUMERO;
	resto=media/NUMERO;

	printf("\n");
	printf("A soma dos valores é %lf e a média é %ld\n, com resto de  %lf\n", total, media, resto);
}
