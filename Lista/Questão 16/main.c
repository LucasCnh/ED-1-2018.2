#include <stdio.h>
#include "tad_pilha.h"
#include "tad_fila.h"

#define TAM 20

/*
Dado uma pilha P qualquer, transcreva seus elementos para uma Fila f de tal maneira
que o último elemento da pilha, deve ser o primeiro da fila e assim em diante.
*/

int main(){

	Pilha* P = criaPilha(TAM);
	Fila*  f = criaFila(TAM);

	for (int i = 0; i < TAM; i++){
		push(P, i);
		printf("Pilha = ");
		printaPilha(P);
	}

	for (int i = 0; i <= (P -> topo); i++){
		enqueue(f, P -> valores[i]);
		printf("Fila = ");
		printaFila(f);
	}

	destroiPilha(&P);
	destroiFila(&f);

	return 0;
}