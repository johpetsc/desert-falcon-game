#Makefile#

all: janela
janela: janela.o main.o Falcon.o Hiero.c
	gcc -o janela main.o janela.o Falcon.o Hiero.c GameObject.o -lSDL_image -lSDL2
GameObject.o: GameObject.c
	gcc GameObject.c -o - GameObject.c -c
Hiero.o: Hiero.c
	gcc Hiero.c -o Hiero.o -c
Falcon.o: Falcon.c
	gcc Falcon.c -o Falcon.o -c
janela.o: janela.c
	gcc janela.c -o janela.o -c
main.o: main.c janela.h
	gcc main.c -o main.o -c
clean:
	rm -rf *.o
mrproper: clean
	rm -rf janela