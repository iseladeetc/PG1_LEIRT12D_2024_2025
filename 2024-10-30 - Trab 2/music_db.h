#pragma once

#include <stdbool.h>
#include "date.h"


#define MAX_ARTIST_NAME      64
#define MAX_ALBUM_NAME      128
#define MAX_TRACK_NAME      256
#define MAX_GENRE_NAME      128

#define MAX_ALBUMS         2048
#define MAX_ARTISTS         100
#define MAX_TRACKS        30000
#define MAX_GENRES           64

#define MAX_ARTIST_ALBUMS    50
#define MAX_ALBUM_TRACKS     50
 
#define INVALID_ID           -1

// tipos que representam id's de entidades

typedef int artist_id_t;
typedef int album_id_t;
typedef int track_id_t;
typedef int genre_id_t;

 
typedef struct {
    artist_id_t id;
    bool        in_use;
    char        name[MAX_ARTIST_NAME+1];
    int         n_albums;
    album_id_t  albums[MAX_ARTIST_ALBUMS];
    int         popularity;    // índice de popularidade de 0 a 100
    genre_id_t  genre_id ; // genero do artista
} artist_t;


typedef struct {
    album_id_t  id;
    bool        in_use;
    char        name[MAX_ALBUM_NAME+1];
    date_t      release_date;
    int         n_tracks;
    track_id_t  tracks[MAX_ALBUM_TRACKS];
    artist_id_t artist_id;
} album_t;

typedef struct {
    track_id_t  id;
    bool        in_use;
    char        name[MAX_TRACK_NAME+1];
    int         duration;   // duration in seconds
    album_id_t  album_id;      
} track_t;

typedef struct {
    genre_id_t  id;
    char        name[MAX_GENRE_NAME+1];
} genre_t;


// stats

typedef struct {
    int total_artists;
    int total_albums;
    int total_tracks;
    int total_genres;
} db_stats_t;


/**
 * FUNÇÕES
 */
 
 
 
/**
 * NÍVEL 1
 * 
 * Apresenta na consola o conteúdo dos arrays constituintes da base de dados:
 * db_genres, db_artists, db_albums e db_tracks
 * Ésta função é essencialmente útil para debug.
 */
void db_dump();



/**
 * NÍVEL 1
 * 
 * retorna a posição (id) do artista de nome "artist_name" no array de artistas
 * ou -1 caso o artista de nome "artist_name" não exista
 */
artist_id_t db_artist_getid(const char artist_name[]);


/**
 * NÍVEL 1
 * 
 * retorna o artista  (artist_t) de id "artist_id"
 * ou um artista inválido, com id = -1 ("null_artist"), caso o "artist_id" seja inválido
 */  
 artist_t db_artist_get_by_id(artist_id_t artist_id);


/**
 * NÍVEL 1
 * 
 * adiciona o artista de nome "artist_name", índice de popularidade
 * "popularity" e género de nome "genre" ao array de artistas.
 * O artista é criado sem álbuns.
 * retorna o id do novo artista ou -1 se a base dade estiver cheia
 * Caso o artista já exista, o array não é alterado, sendo retornado o id
 * do artista existente
 */
artist_id_t db_artist_add(const char artist_name[], int popularity, const char genre_name[]);
   

/**
 * NÍVEL 2
 * 
 * remove o artista de id "artist_name", removendo também 
 * todos os seus álbuns e as faixas deses álbuns
 * retorna "false" se o artista de id "id" não existir,
 * e "true" se a remoção foi realizada com sucesso
 */
bool db_artist_remove(artist_id_t artist_id);
    

/**
 * NÍVEL 1
 * 
 * procura artistas cujo nome inclua a string "match",
 * retornando o conjunto de artistas que satisfazem a pesquisa no array "result",
 * até ao máximo de "max_results" artistas. 
 * Os artistas no array "result" deverão ficar ordenados de forma crescente pelo 
 * nome do artista.
 * A função retorna o total de artistas presentes no array "result"
 */
int db_artist_search_by_name(const char match[], artist_t result[], int max_results);
    
 
/**
 * NÍVEL 1
 * 
 * preenche o array "albums" com os álbuns do artista de id "artist_id" até um máximo de "max_albums",
 * que tenham data de lançamento compreendida entre as datas "dt_start" e "dt_end".
 * 
 * A função retorna o total de álbuns encontrados ou -1 se o id do artista for inválido
 * 
 * Os álbuns presentes no array "albums" devem ficar ordenados por ordem crescente do "nome"
 */
int db_artist_albums(artist_id_t id, album_t albums[], int max_albums, date_t dt_start, date_t dt_end);
   

/**
 * NÍVEL 2
 * 
 * guarda no ficheiro de nome filename
 * a informação sobre os artistas, álbuns e faixas no formato csv seguinte:
 * 
 * para cada novo artista: add ; artist; <artist_name> ; <popularity> ; <genre_name>
 * 
 * para cada novo álbum:   add ; album;  <artist_name> ; <album_name> ; <release_date>
 * 
 * para cada nova faixa:   add ; track ; <album_name> ; <artist_name>  ; <duration>
 */
bool db_save_all(const char filename[]);


/**
 * 
 * NÍVEL 1
 * 
 * retorna a posição (id)  na tabela de álbuns do álbum de nome "album_name"
 * associado ao artista "artist_id" ou -1 caso o álbum não exista ou o 
 * album não pertença ao artista ed id "artist_id"
 */
album_id_t db_album_getid(const char album_name[], artist_id_t artist_id);

/**
 * NÍVEL 1
 * 
 * retorna o álbum  (album_t) de id "album_id"
 * ou um álbum inválido, com id = -1 ("null_album"), caso o "album_id" seja inválido
 */  
 album_t db_album_get_by_id(album_id_t album_id);   

/**
 * 
 * NÍVEL 1
 * 
 * insere um novo álbum na tabela de álbuns a partir
 * do seu nome "album_name", a data de lançamento "release_date" e o
 * id do artista associado ("artist_id")
 * retorna o id do novo álbum ou -1 se "artist_id" for inválido
 */
album_id_t db_album_add(const char album_name[], date_t release_date, int artist_id);


/**
 * NÍVEL 1
 * 
 * preenche o array "tracks" com as faixas  do álbum de id "id" até um máximo de "max_tracks",
 * 
 * A função retorna o total de faixas encontradas ou -1 se o id do álbum for inválido
 */ 
int db_album_tracks(album_id_t id, track_t tracks[], int max_tracks);

 
/**
 * 
 * NÍVEL 1
 * 
 * insere uma nova faixa no array "db_tracks", a partir
 * do seu nome "track_name", a duração em segundos "duration" e o
 * id do álbum a que pertence ("album_id")
 * retorna o id da nova faixa ou -1 se "album_id" for inválido
 */
track_id_t db_track_add(const char track_name[], int duration, album_id_t  album_id);
   

/**
 * NÍVEL 1
 * 
 * retorna o género musical  (genre_t) de id "genre_id"
 * ou um género inválido ("null_genre")  "genre_id" seja inválido
 */
genre_t db_genre_get_by_id(genre_id_t genre_id);



/**
 * NÍVEL 2
 * 
 * preenche o array "top" com os "capacity" artistas mais populares,
 * por ordem descrescente de popularidade.
 * retorna o total de artists colocados no array (capacity ou menos)
 */
int db_top_popularity(artist_t top[], int capacity);


/**
 * NÍVEL 1
 * 
 * retorna uma estrutura "db_stats_t" com o total
 * de géneros musicais, artistas, álbuns e faixas de música existentes
 */
db_stats_t db_stats();


