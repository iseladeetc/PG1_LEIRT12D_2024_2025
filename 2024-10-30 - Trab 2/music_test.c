#include "music_db.h"

int main() {
    db_artist_add("Queen", 86, "rock");
    
    date_t d = { .day = 1, .month = 6, .year = 1888};
    db_album_add("Magic", d, 0);
    db_album_add("Magic2", d, 0);
    db_dump();
}
