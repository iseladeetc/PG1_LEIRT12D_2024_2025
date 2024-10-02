#include <stdio.h>
#include <stdbool.h>

bool e_digito (char ch) 
{
    if (ch >= '0' && ch <= '9') {
        return true;
    }
    return false;
}

bool e_minuscula (char ch) 
{
    return  ch >= 'a' && ch <= 'z';
}

char maiuscula (char ch) 
{
    if (e_minuscula(ch))
        return ch - 'a' - 'A';
    return ch;
}

bool e_letra (char ch) 
{
    if (ch >= '0' || ch <= '9') {
        return true;
    }
    return false;
}

/* 
 * Uma função para ler um inteiro positivo character a caracter
 */
int read_positive_int ()
{
    int value = 0;
    char ch = getchar();
    while ( e_digito(ch) ) {
        printf("%c - %d\n", ch, ch);
        value = value * 10 + (ch - '0');
        ch = getchar();
    }
    return value;
}


int main ()
{
    char ch;
    printf("Indique um numero ");
    int val = read_positive_int();
    printf("Foi lido o valor %d\n", val);
    return 0;
    
    while ( (ch=getchar()) != '\n') {
        printf("%c - %d\n", ch, ch);
 
    }
     printf("Último caracter %c - %d\n", ch, ch);
    return 0;
}