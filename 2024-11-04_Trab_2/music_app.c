#include <stdio.h>
#include <string.h>
#include "strutils.h"
#include "music_db.h"


#define DB_FILENAME "music_db.csv"


// COMMANDS

#define ADD     "add"
#define REMOVE  "remove"
#define SEARCH  "search"
#define STATS   "stats"
#define EXEC    "exec"
#define DUMP    "dump"
#define QUIT    "quit"
#define HELP    "help"

// ENTITIES

#define ARTIST "artist"
#define ALBUM  "album"
#define TRACK  "track"
#define GENRE  "genre"

#define ARTISTS "artists"
#define ALBUMS  "albums"
#define TRACKS  "tracks"
#define GENRES  "genres"

// Stats sub-commands
#define TOP "top"

#define MAX_PARTS 10
#define DELIMITER ';'

// error or special codes

#define OK              0
#define INVALID_CMD     1
#define INVALID_ENTITY  2
#define INVALID_PARM    3
#define FULL_DB         4
#define TERMINATE       5
#define NOCMD_FILE      6
#define UNKNOWN_ENTITY  7


// generic constants
#define LINESIZE 256

int db_opers(const char opers_filename[], char status_msg[]);

 
/**
 * preenche a string "status_msg" com a mensagme de erro
 * no caso de status_code != OK ou coloca a string_vazie caso contrário
 */
void fill_status(int status_code, char status_msg[], int line) {
    char *error_names[] = {
        "no error",
        "invalid cmd",
        "invalid entity",
        "invalid parameter",
        "full database",
        "terminate",
        "inexistent file",
        "unknown entity"
    };
    if (status_code != OK) {
        if (line != 0) {
            sprintf(status_msg, "error at line %d: %s", line, error_names[status_code]);
        }
        else {
            sprintf(status_msg, "error: %s", error_names[status_code]);
        }
    }
    else {
        status_msg[0] = 0;
    }
}


/**
 * Função responsável pelo processamento com comando add
 *
 * add ; artist; <artist_name> ; <popularity>   ; <genre_name>
 * add ; album;  <artist_name> ; <album_name>   ; <release_date> 
 * add ; track;  <album_name>  ; <artist_name>  ; <track_name>   ; <duration> 
 */
int process_cmd_add(spart_t cmd_parts[], int n_parts)
{
    // todo
    return INVALID_ENTITY;
}

/**
 * processa e executa os comandos recebidos na string "cmd"
 * no formato CSV especificado no help da versão completa
 */
int process_cmd(char cmd[]) 
{
    spart_t cmd_parts[MAX_PARTS];

    int n_parts = str_split(cmd, cmd_parts, MAX_PARTS, DELIMITER);
    if (n_parts < 0) return INVALID_CMD;
    
    str_tolower(cmd_parts[0]);
    
    if ( strcmp(ADD, cmd_parts[0]) == 0 ) {
        return process_cmd_add(cmd_parts, n_parts);
    }
    return INVALID_CMD;
}


int db_load(char status_msg[]) {
    return db_opers(DB_FILENAME, status_msg);
}


bool db_save() {
    return db_save_all(DB_FILENAME);
}


/**
 * Executa comandos presentes no ficheiro de nome indicado em opers_filename
 * 
 * Considera-se erros:
 *      A especificação de comandos ou entidades inválidas
 *      A omissão de valores necessários à criação das entidades
 *      (ex: faltar o género musical na criação do artista)
 *      A existência de valores inválidos 
 *      (ex: data de lançamento de álbum inválida)
 * A ocorrência de um erro termina de imediato o processamento de comandos
 * 
 * A inserção de entidades já existentes e a remoção de entidades inexistentes
 * não produzem nenhum efeito, não sendo consideradas erro.
 * Tal permite que erros encontrados possam ser corrigidos e o ficheiro de comandos
 * ser rexecutado até que seja necessário
 * 
 * Retorna:
 *  - false em caso de ocorrência de erro no ficheiro, sendo nesse caso a 
 *  string "status_msg" preenchida com a descrição do erro
 *  - true em caso de sucesso, ficando nesse caso vazia a string "status_msg"
 */ 
int db_opers(const char opers_filename[], char status_msg[]) {
     FILE *of = fopen(opers_filename, "r");
     if (of == NULL) {
        fill_status(NOCMD_FILE, status_msg, 0);
        return NOCMD_FILE;
     }
     int line = 1;
     char cmd[LINESIZE];

     while(fgets(cmd, LINESIZE, of) != NULL) {
        str_trim(cmd); // remove initial and final spaces
    
        if (cmd[0] != '#' && cmd[0] != 0) {
            int status = process_cmd(cmd);
            if (status != OK) {
                fill_status(status, status_msg, line);
                fclose(of);
                return status;
            }
        }
        line++;
     }
     fclose(of);
     return OK;
}


/**
 * loop de comandos interativos
 * termina com a execução do comando "quit"
 */
void run() {
    char line[LINESIZE];
    char status_msg[64];
    while(true) {
        printf("cmd? ");
        fgets(line, LINESIZE, stdin);
        str_trim(line);
        if (line[0] != 0) {
            int res = process_cmd(line);
            if (res == TERMINATE) {
                break;
            }
            else if (res != OK) {
                fill_status(res, status_msg, 0);
                printf("%s\n", status_msg);
            }
        }
    } 
}

void test_process_cmd ()
{
// 1st Album
    process_cmd("Add ; Artist ; Queen ; 86 ; Classic Rock");
    
    process_cmd("add ; album ; Queen ; Innuendo (Deluxe Edition 2011 Remaster) ; 5-2-1991");

    process_cmd("add ; track ; Innuendo (Deluxe Edition 2011 Remaster) ; Queen ; Innuendo - Remastered 2011 ; 393");
    process_cmd("add ; track ; Innuendo (Deluxe Edition 2011 Remaster) ; Queen ; I'm Going Slightly Mad - Remastered 2011 ; 262");
    db_dump();
}

int main() 
{
    printf("Testing process_cmd wint cmd 'add'\n");
    test_process_cmd();
    return 0;

    char status_msg[64];
    int res;

    printf("load db...\n");
    res = db_load(status_msg);

    if (res != OK) {
        if (res == NOCMD_FILE) {
            printf("inexistent database\n");
        }
        else {
            printf("%s\n", status_msg);
        }   
    }
    
    // execute interative command loop
    run();
    
    printf("save_db...\n");
    db_save();
    printf("bye!\n");
}
