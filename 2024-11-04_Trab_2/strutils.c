#include "strutils.h"

#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>


/**
 * Converte todas as letras maiúsculas da string "str" para minúsculas.
 * Os carateres que não sejam letras maiúsculas permanecem inalterados.
 */ 
void str_tolower (char str[]) {
	printf("'str_tolower' not implemented!\n");
}


/**
 * Converte para maiúscula a primeira letra de uma sequência de letras 
 * e/ou dígitos e para minúscula as restantes letras na string "str". 
 * Considere como separadores todos os outros caracteres como 
 * separadores (todos os caracteres diferente de letra ou digito).
 *  
 * Exemplo:
 *      str =  " heLLO wORLD!" transformada em " Hello World!"
 *      str = "a.s.n" transformada em "A.S.N"
 */  
void str_capitalize(char str[]) {
	printf("'str_capitalize' not implemented!\n");
}   


/**
 * Retira (elimina) os separadores iniciais e finais da string "str".
 * Os separadores podem ser: espaço, tab(\t) e mudança de linha(\n).
 */
void str_trim(char str[]) {
	printf("'str_trim' not implemented!\n");
} 


/**
 * A string "line" possui um texto separado pelo caracter "delimiter", por 
 * exemplo, se considerarmos o "delimiter" igual a ',' "line" podia ter o seguinte
 * texto: "aaaaaa, bbbbb, cccccc, dddddd"
 * 
 * A função coloca em "part" a próxima sequência de caracteres de "line",
 * de dimensão máxima MAX_PART, a partir da posição indicada por "pos",
 * até ao próximo delimitador "delimiter", ou até ao fim da string "line".
 * 
 * Retorna:
 *      >= 0       - posição da próxima sequência, em caso de sucesso
 *   EOL (-1)      - não foi lida nenhuma sequência porque se chegou ao fim da string
 *                   (na posição "pos" passada por parâmetro está o caracter '\0'.
 *   OVERFLOW (-2) - a sequência foi truncada por ser maior do que "MAX_PART".
 */
int str_next(const char line[], int pos, spart_t part, char delimiter) {
	printf("'str_next' not implemented!\n");
    return -1;
}


/**
 * Copia todas as sub-strings de "line" delimitadas pelo caracter "delimiter"
 * para posições consecutivas do array "parts" até um máximo de "max_parts"
 
 * As substrings colocads em parts não devem possuir separadores brancos iníciais e finais.
 * Os separadores podem ser: espaço, tab(\t) e mudança de linha(\n).
 * Nota: Utilize para esta funcionalidade a função str_trim
 * 
 * Retorna 
 *   >0          - o total de 'partes' copiadas, i.e. número de elemento do 
 *                 array parts
 *   -max_parts  - indica que existiam mais 'partes' e o array parts tem as 
 *                 partes possíveis de guardar
 */
int str_split(const char line[],  spart_t parts[], int max_parts, char delimiter) {
	printf("'str_split' not implemented!\n");
    return -1;
}   


 











