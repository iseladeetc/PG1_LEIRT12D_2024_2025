all:  music_app_1 music_app music_test


# sugerido pelo enunciado com ligação com music_app_ok.o
music_app_1: music_app_ok.o music_db.c music_db.h strutils.c strutils.h date.c date.h
	gcc -o music_app_1 -Wall -g music_app_ok.o music_db.c date.c strutils.c

music_app: music_app.c music_db.c music_db.h strutils.c strutils.h date.c date.h
	gcc -o music_app -Wall -g music_app.c music_db.c date.c strutils.c

music_test: music_test.c music_db.c music_db.h strutils.c strutils.h date.c date.h
	gcc -o music_test -Wall -g music_test.c music_db.c date.c strutils.c
	
clean:
	rm -rf  music_app_1 music_app music_test 
