/**
 * Programa para determinar a nota final através do cálculo da média 
 * entre a nota teorica e a nota prática 
 * 
 * Nesta versão é validado se as notas lidas se encontram no intervalo [0..20]
 * e em caso de valor fora deste intervalo volta a ler novo valor.
 * Para suportar esta leitura foi escrita a função  read_int_in_range
 */
#include <stdio.h>
#include <stdbool.h>

int read_int_in_range (int lower, int higher)
{
    int value;
    do {
        printf("Indique um valor no intervalo [%d..%d] ", lower, higher);
        scanf("%d", &value);

        if (value < lower || value > higher) {
            printf("valor errado\n"); 
        }
        else 
            break;
//    } while (nota_teorica < 0 || nota_teorica > 20);
    } while (true);
    return value;
}

int main ()
{
    // 1. Ler Nota Teórica
    printf("Leitura nota teórica:\n");
    int nota_teorica = read_int_in_range(0, 20);

    // 2. Ler Nota prática
    printf("Leitura nota prática:\n");
    int nota_pratica = read_int_in_range(0, 20);
    
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