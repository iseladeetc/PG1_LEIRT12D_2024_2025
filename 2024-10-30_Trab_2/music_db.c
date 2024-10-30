#include <stdio.h>
#include <string.h>
#include "music_db.h"
#include "strutils.h"

// globals

// para retornar uma entidade inválida em caso de erros
artist_t null_artist = { .id = -1 };
album_t null_album =   { .id = -1 };
genre_t null_genre =   { .id = -1 };
track_t null_track =   { .id = -1 };

// genres
int db_ngenres = 0;
genre_t db_genres[MAX_GENRES];

// artists
int db_nartists = 0;
artist_t db_artists[MAX_ARTISTS];

// albums
int db_nalbums = 0;
album_t db_albums[MAX_ALBUMS];

// tracks
int db_ntracks = 0;
track_t db_tracks[MAX_TRACKS];


 
/**
 * NÍVEL 1
 * 
 * Apresenta na consola o conteúdo dos arrays constituintes da base de dados:
 * db_genres, db_artists, db_albums e db_tracks
 * Ésta função é essencialmente útil para debug.
 */
void db_dump() {
    printf("'db_dump' not implemented!\n");
}

/**
 * 
 * NÍVEL 1
 * 
 * retorna a posição (id) do artista de nome "artist_name" no array de artistas
 * ou -1 caso o artista de nome "artist_name" não exista
 */
artist_id_t db_artist_getid(const char artist_name[]) {
    printf("'db_artist_getid' not implemented!\n");
    return -1;
}

/**
 * NÍVEL 1
 * 
 * retorna o artista  (artist_t) de id "artist_id"
 * ou um artista inválido, com id = -1 ("null_artist"), caso o "artist_id" seja inválido
 */  
 artist_t db_artist_get_by_id(artist_id_t artist_id) {
    printf("'db_artist_get_by_id' not implemented!\n");
    return null_artist; 
}



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
artist_id_t db_artist_add(const char artist_name[], int popularity, const char genre[]) {
    printf("'db_artist_add' not implemented!\n");
    return -1;
}


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
bool db_save_all(const char filename[]) {
    printf("'db_save_all' not implemented!\n");  
    return false;
}

/**
 * NÍVEL 2
 * 
 * remove o artista de id "artist_name", removendo também 
 * todos os seus álbuns e as faixas deses álbuns
 * retorna "false" se o artista de id "id" não existir,
 * e "true" se a remoção foi realizada com sucesso
 */
bool db_artist_remove(const artist_id_t id) {
    printf("'db_artist_remove' not implemented!\n");  
    return -1;
}

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
int db_artist_search_by_name(const char match[], artist_t result[], int max_results) {
    printf("'db_artist_search_by_name' not implemented!\n");  
    return 0;
} 

 
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
int db_artist_albums(artist_id_t id, album_t albums[], int max_albums, date_t dt_start, date_t dt_end) {
    printf("'db_artist_albums' not implemented!\n");  
    return 0;
}

/**
 * 
 * NÍVEL 1
 * 
 * retorna a posição (id)  na tabela de álbuns do álbum de nome "album_name"
 * associado ao artista "artist_id" ou -1 caso o álbum não exista ou o 
 * album não pertença ao artista ed id "artist_id"
 */
album_id_t db_album_getid(const char album_name[], artist_id_t artist_id) {
    printf("'db_album_getid' not implemented!\n");  
    return INVALID_ID;
}

/**
 * NÍVEL 1
 * 
 * retorna o álbum  (album_t) de id "album_id"
 * ou um álbum inválido, com id = -1 ("null_album"), caso o "album_id" seja inválido
 */  
 album_t db_album_get_by_id(album_id_t album_id) {
    printf("'db_album_get_by_id' not implemented!\n");
    return null_album; 
 } 
 
/**
 * 
 * NÍVEL 1
 * 
 * insere um novo álbum na tabela de álbuns a partir
 * do seu nome "album_name", a data de lançamento "release_date" e o
 * id do artista associado ("artist_id")
 * retorna o id do novo álbum ou -1 se "artist_id" for inválido
 */
album_id_t db_album_add(const char album_name[], date_t release_date, artist_id_t artist_id) {
    printf("'album_add' not implemented!\n");  
    return INVALID_ID;
}  

 
/**
 * NÍVEL 1
 * 
 * preenche o array "tracks" com as faixas  do álbum de id "id" até um máximo de "max_tracks",
 * 
 * A função retorna o total de faixas encontradas ou -1 se o id do álbum for inválido
 */ 
int db_album_tracks(album_id_t id, track_t tracks[], int max_tracks) {
    printf("'db_album_tracks' not implemented!\n");  
    return INVALID_ID;
}

 
/**
 * 
 * NÍVEL 1
 * 
 * insere uma nova faixa no array "db_tracks", a partir
 * do seu nome "track_name", a duração em segundos "duration" e o
 * id do álbum a que pertence ("album_id")
 * retorna o id da nova faixa ou -1 se "album_id" for inválido
 */
track_id_t db_track_add(const char track_name[], int duration, album_id_t  album_id) {
    printf("'db_track_add' not implemented!\n");  
    return INVALID_ID; 
}




/**
 * NÍVEL 1
 * 
 * retorna uma estrutura "db_stats_t" com o total
 * de géneros musicais, artistas, álbuns e faixas de música existentes
 */
db_stats_t db_stats() {
    printf("'db_stats' not implemented!\n");  
    db_stats_t db = {0};
    return db;
}


/**
 * NÍVEL 2
 * 
 * preenche o array "top" com os "capacity" artistas mais populares,
 * por ordem descrescente de popularidade.
 * retorna o total de artists colocados no array (capacity ou menos)
 */
int db_top_popularity(artist_t top[], int capacity) {
    printf("'db_top_popularity' not implemented!\n");  
    return INVALID_ID; 
}

/**
 * 
 * NÍVEL 1
 * 
 * retorna o género musical  (genre_t) de id "genre_id"
 * ou um género inválido ("null_genre")  "genre_id" seja inválido
 */
genre_t db_genre_get_by_id(genre_id_t genre_id) {
    printf("'db_genre_get_by_id' not implemented!\n");  
    return null_genre; 
}






