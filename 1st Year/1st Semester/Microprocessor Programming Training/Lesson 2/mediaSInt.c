#include <stdio.h>

int main() 
{
	const int NUMERO=3;
	long long int val11=0, val12=0, val13=0;
	long long int total;
	long long int media;
	 
	printf("Introduza os três valores:");
	scanf(" %lld %lld %lld", &val11, &val12, &val13);

	total=val11+val12+val13;
	media=total/NUMERO;

	printf("\n");
	printf("A soma dos valores é %lld e a média é %lld\n", total, media);
}
