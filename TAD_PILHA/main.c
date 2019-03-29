#include <stdio.h>
#include "tad_pilha.h"

int main(){

	Pilha* pilha = criaPilha(10);
	int j;

	for (int i = 0; i < 10; i++){
		push(pilha, i);
		printaPilha(pilha);
	}

	for (int i = 0; i < 20; i++){
		j = pop(pilha);
		printf("j = %i\n", j);
		printaPilha(pilha);
	}

	destroiPilha(&pilha);

	if (pilha == NULL){
		printf("Deu certo\n");
	}

	return 0;
}