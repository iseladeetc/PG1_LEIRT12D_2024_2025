#pragma once

#include <stdbool.h>

#define EOL -1
#define OVERFLOW -2

#define MAX_PART 256

typedef char spart_t[MAX_PART];

void str_tolower(char str[]);

/**
 * força a maiúscula a primeira letra de todas 
 * palavras presentes em "str" e a minúscula as letras restantes
 * de cada palavra. Os carateres que não sejam letras são mantidos
 * inalterados
 */  
void str_capitalize(char str[]);    


/**
 * retira os espaços iniciais e finais da string "str"
 */
void str_trim(char str[]);       


/**
 * Coloca em "part" a próxima sequência de caracteres de "line",
 * de dimensão máxima MAX_PART, a partir da posição indicada por "pos",
 * até ao próximo delimitador "delimiter", ou até ao fim da string "line".
 * 
 * Retorna:
 *   se >= 0      --> posição da próxima sequência, em caso de sucesso
 *   EOL (-1)     --> não foi lida nenhuma sequência porque se chegou ao fim da string
 *   OVERFLOW (-2)--> a sequência foi truncada por ser maior do que "max_size".
 * 
 */
int str_next(const char line[], int pos, spart_t part, char delimiter);


/**
 * Copia todas as sub-strings de "line" delimitadas pelo caracter "delimiter"
 * para posições consecutivas do array "parts" até um máximo de "max_parts"-
 * Retorna o total de 'partes' copiadas
 */
int str_split(const char line[],  spart_t parts[], int max_parts, char delimiter);	  


 
	 


 

    
