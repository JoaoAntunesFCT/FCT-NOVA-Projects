#include <stdio.h>

int main() 
{
	unsigned long long dia1=0, dia2=0, diaf=0;
	unsigned long long hora1=0, hora2=0, horaf=0;
	unsigned long long min1=0, min2=0, minf=0;
	unsigned long long seg1=0, seg2=0, segf=0;
	unsigned long long contai=0, contaf=0, contad=0;	

	/* Data inicial */
	printf("Introduza a data inicial, indicando o dia hora minuto e segundo iniciais (por esta ordem): ");
	scanf("%lld", "%lld", "%lld", "%lld", &dia1, &hora1, &min1, &seg1);
	/* Data final */
	printf("Introduza a data final, indicando o dia hora minuto e segundo finais (por esta ordem): "); 
	scanf("%lld", "%lld", "%lld", "%lld", &dia2, &hora2, &min2, &seg2);
	/* Redução a segundos */
	contai=(dia1*86400+hora1*3600+min1*60+seg1);
	contaf=(dia2*86400+hora2*3600+min2*60+seg2);
	printf("O valor inicial e final em segundos correspondem a %lld e %lld (aproximadamente)");
	/* Somatório */ 
	
}

