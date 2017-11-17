#Makefile#

all: janela clean
janela: janela.o main.o Falcon.o Hiero.o Obstaculo.o Inimigo.o Escrita.o
	gcc -o janela main.o janela.o Falcon.o Hiero.o Obstaculo.o Inimigo.o Escrita.o -lSDL2_image -lSDL2_ttf -lSDL2
Hiero.o: Hiero.c
	gcc Hiero.c -o Hiero.o -c -I/usr/include/SDL2
Falcon.o: Falcon.c
	gcc Falcon.c -o Falcon.o -c -I/usr/include/SDL2
Escrita.o: Escrita.c
	gcc Escrita.c -o Escrita.o -c -I/usr/include/SDL2
Obstaculo.o: Obstaculo.c
	gcc Obstaculo.c -o Obstaculo.o -c -I/usr/include/SDL2
Inimigo.o: Inimigo.c
	gcc Inimigo.c -o Inimigo.o -c -I/usr/include/SDL2
janela.o: janela.c
	gcc janela.c -o janela.o -c -I/usr/include/SDL2
main.o: main.c janela.h
	gcc main.c -o main.o -c
clean:
	rm -rf *.o