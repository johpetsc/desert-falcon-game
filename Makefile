#Makefile#

all: desert_falcon clean
desert_falcon: desert_falcon.o main.o falcon.o hiero.o obstacle.o enemy.o score.o
	gcc -o desert_falcon obj/main.o obj/desert_falcon.o obj/falcon.o obj/hiero.o obj/obstacle.o obj/enemy.o obj/score.o -lSDL2_image -lSDL2_ttf -lSDL2
hiero.o: src/hiero.c
	gcc src/hiero.c -o obj/hiero.o -c -I/usr/include/SDL2
falcon.o: src/falcon.c
	gcc src/falcon.c -o obj/falcon.o -c -I/usr/include/SDL2
score.o: src/score.c
	gcc src/score.c -o obj/score.o -c -I/usr/include/SDL2
obstacle.o: src/obstacle.c
	gcc src/obstacle.c -o obj/obstacle.o -c -I/usr/include/SDL2
enemy.o: src/enemy.c
	gcc src/enemy.c -o obj/enemy.o -c -I/usr/include/SDL2
desert_falcon.o: src/desert_falcon.c
	gcc src/desert_falcon.c -o obj/desert_falcon.o -c -I/usr/include/SDL2
main.o: src/main.c lib/desert_falcon.h
	gcc src/main.c -o obj/main.o -c
clean:
	rm -rf *.o