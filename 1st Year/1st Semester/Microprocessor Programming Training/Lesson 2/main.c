#include <stdio.h>
int main()
{
    char dia='d';
    char hora='h';
    char minuto='m';
    char segundo='s';
    unsigned int dia1=0, hora1=0, minuto1=0, seg1=0;
    unsigned int dia2=0, hora2=0, minuto2=0, seg2=0;
    unsigned int totali, totalf, totalc;
    unsigned int diaf, horaf, minutof, segf;

    printf("Introduz a primeira data com o seguinte formato: dia, hora, minuto e segundo.");
    scanf(" %lu %lu %lu %lu", &dia1, &dia, &hora1, &hora, &minuto1, &minuto, &seg1, &segundo);
    printf("Introduz a segunda data com o seguinte formato: dia, hora, minuto e segundo.");
    scanf(" %lu %lu %lu %lu", &dia2, &dia, &hora2, &hora, &minuto2, &minuto, &seg2, &segundo);

    totali=(dia1*86400)+(hora1*3600)+(minuto1*60)+seg1;
    totalf=(dia2*86400)+(hora2*3600)+(minuto2*60)+seg2;
    totalc=totalf-totali;

    diaf=totalc/86400;
    horaf=(totalc%86400)/3600;
    minutof=((totalc%86400)%3600)/60;
    segf=((totalc%86400)%3600)%60;

    printf("\n");
    if (totalc >= 0.0)
    {
        printf("Valor absoluto em segundos: %lu.\n", totalc, &segundo);
        printf("Esse valor corresponde a: %lu %lu %lu %lu", &diaf, &dia, &horaf, &hora, &minutof, &minuto, &segf, &segundo);
    }
        else
        {
            printf("Valor absoluto em segundos: %lu.\n", -totalc, &segundo);
            printf("Esse valor corresponde a: %lu %lu %lu %lu", &diaf, &dia, &horaf, &hora, &minutof, &minuto, &segf, &segundo);
        }
}
