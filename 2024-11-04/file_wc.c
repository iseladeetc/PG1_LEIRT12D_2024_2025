#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define FILENAME "file_test.txt"

#define MAX_LINE    256

int str_skip_spaces(const char str[], int pos)
{
    while ( str[pos] != '\0' && isspace(str[pos])) {
        pos++;
    }
    return pos;
}

int str_skip_word(const char str[], int pos)
{
    while ( str[pos] != '\0' && !isspace(str[pos])) {
        pos++;
    }
    return pos;
}

int str_count_words (const char str[])
{
    int cnt_words = 0;
    int pos = 0;
    while ( str[pos] != '\0' ) {
        // saltar espaços
        pos = str_skip_spaces(str, pos);
        if (str[pos] == '\0') break;
        
        cnt_words++;
        pos = str_skip_word(str, pos);
    }
    return cnt_words;
}

int main ()
{
    FILE *fp;

    fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        printf("Error openning file %s\n", FILENAME);
        return -1;
    }

    char text_line[MAX_LINE];
    int linhas = 0;
    int bytes = 0;
    int words = 0;

    while ( fgets(text_line, MAX_LINE, fp) != NULL ) {
        // processar a linha texto lida
        bytes = bytes + strlen(text_line);
        linhas++;
        words += str_count_words(text_line);
        //printf("%d - %s\n", linhas, text_line);
    }

    printf("linhas: %d | words: %d | bytes :%d\n", linhas, words, bytes);

    fclose(fp);

    return 0;
}