#include <stdio.h>

int main(void)
{
    int lado_do_azulejo, comprimento, largura, c_colunas, l_linhas, n_azulejos_final;
    
    scanf(" %d", &lado_do_azulejo);
    scanf(" %d %d", &comprimento, &largura);
    
    c_colunas = comprimento/lado_do_azulejo;
    l_linhas = largura/lado_do_azulejo;

    n_azulejos_final = c_colunas * l_linhas;

    printf("Azulejos inteiros: %d\n", n_azulejos_final);
}