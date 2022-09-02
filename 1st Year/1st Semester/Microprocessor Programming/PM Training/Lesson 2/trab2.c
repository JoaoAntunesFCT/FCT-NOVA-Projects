#include <stdio.h>
int main()
{
    char dia='d';
    char hora='h';
    char minuto='m';
    char segundo='s';
    long int dia1=0, hora1=0, minuto1=0, seg1=0;
    long int dia2=0, hora2=0, minuto2=0, seg2=0;
    long int totali, totalf, totalc;
    long int diaf, horaf, minutof, segf;

    printf("Introduz o tempo no.1 (dia)d (hora)h (minuto)m (segundo)s:\n");
    scanf(" %ld d %ld h %ld m %ld s", &dia1, &hora1, &minuto1, &seg1);
    printf("Introduz o tempo no.2 (dia)d (hora)h (minuto)m (segundo)s:\n");
    scanf(" %ld d %ld h %ld m %ld s", &dia2, &hora2, &minuto2, &seg2);

    totali=(dia1*86400)+(hora1*3600)+(minuto1*60)+seg1;
    totalf=(dia2*86400)+(hora2*3600)+(minuto2*60)+seg2;
    totalc=totalf-totali;

    diaf=totalc/86400;
    horaf=(totalc%86400)/3600;
    minutof=(totalc%86400%3600)/60;
    segf=(totalc%86400%3600)%60;

    printf("\n");
    printf("A diferença entre os dois tempos é de %ld segundos = %ldd %ldh %ldm %lds", totalc, diaf, horaf, minutof, segf);
}
