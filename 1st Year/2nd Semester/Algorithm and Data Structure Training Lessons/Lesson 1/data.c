#include <stdio.h>

int main(void){
    int ano, mes, dia;
    int jan=31,fev,mar=31,abr=30,mai=31,jun=30,jul=31,ago=31,set=30,out=31,nov=30,dez=31;
    int dia_final, total;
    printf("Introduza uma data (ano,mes,dia):\n");
    scanf(" %d %d %d", &ano, &mes, &dia);

    if((ano%400==0)||((ano%4==0)&&(ano%100!=0))){
        fev = 29;
    }
    else{
        fev = 28;
    }
    switch(mes){
        case 1: dia_final = dia; break;
        case 2: dia_final = jan + dia; break;
        case 3: dia_final = jan + fev + dia; break;
        case 4: dia_final = jan + fev + mar + dia; break;
        case 5: dia_final = jan + fev + mar + abr + dia; break;
        case 6: dia_final = jan + fev + mar + abr + mai + dia; break;
        case 7: dia_final = jan + fev + mar + abr + mai + jun + dia; break;
        case 8: dia_final = jan + fev + mar + abr + mai + jun + jul + dia; break;
        case 9: dia_final = jan + fev + mar + abr + mai + jun + jul + ago + dia; break;
        case 10: dia_final = jan + fev + mar + abr + mai + jun + jul + ago + set + dia; break;
        case 11: dia_final = jan + fev + mar + abr + mai + jun + jul + ago + set + out + dia; break;
        case 12: dia_final = jan + fev + mar + abr + mai + jun + jul + ago + set + out + nov + dia; break;
    }
    printf("%d\n", dia_final);
}