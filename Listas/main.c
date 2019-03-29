#include <stdio.h>
#include "lista.h"
#include "tad_pilha.h"
#include "tad_fila.h"

int main(){
	
	Lista* lista = criaLista();

	for (int i = 0; i < 10; i++){
		enqueue(&lista, i);
	}

	printaLista(lista);

	printf("%i\n", pop(&lista));
	
	for (int i = 0; i < 5; i++){
		dequeue(&lista);
	}

	printaLista(lista);

	destroiLista(&lista);

	printaLista(lista);

	return 0;
}