#include "janela.h"
#include "GameObject.h"

#define SCREEN_W 640
#define SCREEN_H 480


int main(int argc, char** argv){

	iniciaJanela(SCREEN_W, SCREEN_H);
	atualizaJanela();
	fechaJanela();

	return 0;
}