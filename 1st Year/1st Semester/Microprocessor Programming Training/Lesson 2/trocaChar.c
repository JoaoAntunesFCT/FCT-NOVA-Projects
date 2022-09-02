#include <stdio.h>

int main() {
	char caracter1=' ', caracter2=' ', caracter3=' ';
	
	printf("Introduza três caracteres: ");
	scanf(" %c", &caracter1);
	scanf(" %c", &caracter2);
	scanf(" %c", &caracter3);
	
	printf("\nInvertendo a ordem dos caracteres obtemos: ");
	printf("'%c' '%c' '%c'\n", caracter3, caracter2, caracter1);
}
