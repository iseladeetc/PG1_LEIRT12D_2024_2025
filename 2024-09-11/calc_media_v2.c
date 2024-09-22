
/**
 * Programa para determinar a nota final através do cálculo da média 
 * entre a nota teorica e a nota prática 
 * 
 * Nesta versão é validado se as notas lidas se encontram no 
 * intervalo [0..20]  mas o código foi rescrito em relação à 
 * versão calc_media_v1.c para ser mais simples.
 */
#include <stdio.h>

int main ()
{
    // 1. Ler Nota Teórica
    int nota_teorica;
    printf("Indique a nota teórica ");
    scanf("%d", &nota_teorica);

    if (nota_teorica < 0 || nota_teorica > 20) {
        printf("Nota teórica errada\n"); 
        return -1;
    }

    // 2. Ler Nota prática
    int nota_pratica;
    printf("Indique a nota prática ");
    scanf("%d", &nota_pratica);

    if (nota_pratica < 0 || nota_pratica > 20) {
        printf("Nota pática errada\n"); 
        return -1;
    }

    // 3. Calcular a média
    float media;
    //media = (nota_pratica + nota_teorica)/2;        // divisão inteira pq ambos operando inteiros
    //media = (nota_pratica + nota_teorica) / 2.0;    // divisão real pq 2º operado real(2.0)
    media = (float)(nota_pratica + nota_teorica)/2;   // divisão real pq 1º operado real

    // 4. Apresentar a média obtida
    printf("Nota teórica lida = %d\n", nota_teorica);
    printf("Nota prática lida = %d\n", nota_pratica);
    printf("A média é %09.2f.\n", media);
    
    return 0;
}