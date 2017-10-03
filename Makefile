#Makefile#

all: janela
janela: janela.o main.o GameObject.o
	gcc -o janela main.o janela.o GameObject.o -lSDL
GameObject.o: GameObject.c
	gcc GameObject.c -o GameObject.o -c
janela.o: janela.c
	gcc janela.c -o janela.o -c
main.o: main.c janela.h
	gcc main.c -o main.o -c
clean:
	rm -rf *.o
mrproper: clean
	rm -rf janela