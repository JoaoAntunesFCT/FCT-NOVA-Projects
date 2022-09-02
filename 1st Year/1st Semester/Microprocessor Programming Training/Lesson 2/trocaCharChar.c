#include <stdio.h>

int main() {
	char caracter1=getchar(), caracter2=getchar(), caracter3=getchar();
	
	printf("Introduza três caracteres: ");
	putchar(caracter1);
	putchar(caracter2);
	putchar(caracter3);
	printf("\nInvertendo a ordem dos caracteres obtemos: ");
	printf("'%c' '%c' '%c'\n", caracter3, caracter2, caracter1);
}
