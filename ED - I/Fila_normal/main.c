#include <stdio.h>
#include "fila_normal.h"
#include "fila_controlada.h"

int main(){

	Fila_controle* filas = criaFilaControle(20, 20, 4);

	int j;

	for (int i = 0; i < 20; i++){
		if (i%2 == 0){
			j = 0;
		}else{
			j = 1;
		}

		enqueueControle(filas, i, j);

		printf("Fila normal:  ");
		printaFila(filas -> normal);
		printf("Fila prioritaria:  ");
		printaFila(filas -> prioritaria);
	}


	for (int i = 0; i < 20; i++){
		if (i%2 == 0){
			j = 0;
		}else{
			j = 1;
		}

		if (i%3 == 0){
			enqueueControle(filas, i, j);
		}

		dequeueControle(filas);

		printf("Fila normal:  ");
		printaFila(filas -> normal);
		printf("Fila prioritaria:  ");
		printaFila(filas -> prioritaria);
	}

	destroiFilaControle(&filas);

	if (filas == NULL){
		printf("Deu certo\n");
	}

	return 0;
}