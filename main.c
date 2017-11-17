/** Trabalho Prático 2 
	Técnicas de Programação 2
*/

#include "janela.h"

#define SCREEN_W 640 /** Definindo a resolução da janela do jogo */
#define SCREEN_H 480


int main(int argc, char** argv){ 
	/**Funçao main do programa. Chama o construtor da janela*/

	construtor(SCREEN_W, SCREEN_H,1);

	return 0;
}