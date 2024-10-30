#include <stdio.h>
#include <stdbool.h>

typedef struct date {
    int day, month, year;
} date_t;

/**
 * lê uma data de uma string no formato d-m-a
 */
date_t date_from_str(char str_date[]);

 
/**
 * apresenta uma data no formato d-m-a
 */
void date_show(date_t d);

/**
 * retorna a data do dia atual
 */
date_t date_today();

/**
 * compara duas datas
 */
int date_cmp(date_t d1, date_t d2);

/**
 * Retorna true se o ano "y" for bissexto
 */
bool leap_year(int y);


/**
 * A função já recebe um mês e ano válidos
 * Retorna o número de dias do mês "m"
 */
int month_days(int m, int y);
     

/**
 * Assume que o ano é válido.
 * A função retorna o número de dias do ano "y".
 */
int year_days(int y);


/**
 * Assume que a data é válida.
 * Retorna o número de dias que faltam até ao fim do ano "y"
 * (sem contar com o dia/mès/ano passado por parâmetro).
 */
int year_remaining_days(date_t d);
     

/**
 * Assume que a data é válida.
 * Retorna o número de dias que passaram desde o início do ano "y"
 * (contando com o dia/mès/ano passado por parâmetro).
 */
int year_passed_days(date_t d);
     
/**
 * a função retorna "true" se a data (d/m/y) passada por paràmetro é válida,
 * ou "false" caso contrário
 */

bool date_valid(int d, int m, int y);
    

