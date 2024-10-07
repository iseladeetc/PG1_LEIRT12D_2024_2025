#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

/**
 * Devolve true se letra minúscula ('a'..'z'), false caso contrário
 */
bool char_is_lower (char c)
{
    return (c >= 'a' && c <= 'z');
}

/**
 * converte o caracter recebido para maiusculas no caso de ser uma minúsula 
 * caso contrário devolve o caracter recebido
 */
char char_to_upper (char c)
{
    if ( char_is_lower(c) ) return c - ('a' - 'A');
    return c;
}


/**
 * Consome todos os caracteres até ao fim de linha '\n'
 * 
 */
 void skip_till_end_of_line ()
 {
     char ch = 0;
     do {
         scanf("%c", &ch);
     } while (ch != '\n');
 }
 

/**
  * Função para ler um inteiro no intervalo [lower..higher]. 
  * Continua a tentar ler um valor válido até conseguir.
  * 
  * Esta versão utiliza a instrução break para parar o ciclo de repetição
  */
 int read_int_in_range (int lower, int higher)
 {
    int value; 

    do {
        int retScan = scanf("%d", &value);
        if ( retScan != 1 ) {
            printf("Valor inteiro no formato errado\n");
            skip_till_end_of_line();
        }
        else if ( value < 0 || value > 20 ) {
            printf("Valor inteiro fora do intervalo [%d..%d]\n", lower, higher);
        }
        else break;

        printf("? ");
        
    } while (true);

    return value;
 }
/*
 *   Gera um númer aleatório no intervalo [min..max]
 */
int get_random_in_range (int min, int max) 
{
    return rand() % (max - min + 1) + min;
}


// ----------------------------------------------------------------------------
// Funções sobre arrays de ints

/**
 * Inicia os nElems do array values com um valor aleatório pertencente 
 * ao intervalo [low..high]
 */
int array_int_random_init (int values[], int nElems, int low, int high) 
{
    for (int i= 0; i < nElems; i++) {
        values[i] = get_random_in_range(low, high);
    }
    return nElems;
}

/**
 * Mostra no standard de output os valores dos nElems do array values
 */
void array_int_show (int values[], int nElems)
{
    printf("[");
    for (int i= 0; i < nElems; i++) {
        printf("%02d ", values[i]);
    }
    printf("]\n");
}




#define MAX_CAPACITY                16

#define OPTION_RANDOM_INIT_ARRAY    'I'
#define OPTION_READ_ARRAY           'L'
#define OPTION_PRINT_ARRAY          'P'
#define OPTION_EXIT                 'S'

void show_menu ()
{
    printf("Programa de teste de operações sobre arrays de int\n");

    printf("%c - Inicia array com um sequência de valores aleatórios\n", OPTION_RANDOM_INIT_ARRAY);
    printf("%c - Ler sequência de inteiros.\n",                          OPTION_READ_ARRAY);
    printf("%c - impime conteúdo de array.\n",                           OPTION_PRINT_ARRAY);
    printf("%c - Terminar programa.\n",                                  OPTION_EXIT);
}

char read_option ()
{
    char ch;

    scanf("%c", &ch);
    if (ch != '\n') skip_till_end_of_line();
    return char_to_upper(ch);
}


int main ()
{
    // Inicia gerador de números aleatórios
    srand(time(NULL));

    int values[MAX_CAPACITY];   // array com a capacidade MAX_CAPACITY
    int nValues = 0;            // número de elementos actuais. Inicialmente sem elementos

    bool run = true;
    do {
        show_menu();
        char option = read_option();
        switch ( option ) {
            case OPTION_RANDOM_INIT_ARRAY:
                nValues = array_int_random_init(values, MAX_CAPACITY/2, 1, 10);
                break;

            case OPTION_READ_ARRAY:
                break;

            case OPTION_PRINT_ARRAY: 
                array_int_show(values, nValues);
                break;

            case OPTION_EXIT:
                printf("Terminar.\n"); 
                run = false;
                break;

            default:
                printf("Opção desconhecida\n");
                break;
        }
    } while ( run );

    return 0;
}