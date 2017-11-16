#Makefile#

all: janela
janela: janela.o main.o Falcon.o Hiero.o Obstaculos.o 
	gcc -o janela main.o janela.o Falcon.o Hiero.o Obstaculos.o -lSDL2_image -lSDL2
Hiero.o: Hiero.c
	gcc Hiero.c -o Hiero.o -c
Falcon.o: Falcon.c
	gcc Falcon.c -o Falcon.o -c
Obstaculos.o: Obstaculos.c
	gcc Obstaculos.c -o Obstaculos.o -c
janela.o: janela.c
	gcc janela.c -o janela.o -c
main.o: main.c janela.h
	gcc main.c -o main.o -c
clean:
	rm -rf *.o
mrproper: clean
	rm -rf janela