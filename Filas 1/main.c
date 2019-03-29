#include <stdio.h>
#include <stdlib.h>
#include "fila_1.h"

void desalocador (void* a){

	int* V1 = (int*) a;

	free(V1);

	V1 = NULL;

	return;
}

void printador (void* a){
  
	int* V1 = (int*) a;

	printf("%i ", *V1);

	return;
}

int main(){

	Fila* filas = criaFilaControle(20, 20, desalocador, printador);
	int* valor = (int*) malloc(sizeof(int));

	int j;

	for (int i = 0; i < 25; i++){
		*valor = i;
		if (i%2 == 0){
			j = 0;
		}else{
			j = 1;
		}

		insereFilaControle (filas, (void*) valor, j);
		printf("\n\nNormal: ");
		printaFila(filas -> normal);
		printf("\n\nPrioridade: ");
		printaFila(filas -> prioritaria);
		valor = (int*) malloc(sizeof(int));
	}

	valor = (int*) malloc(sizeof(int));
	for (int i = 0; i < 26; i++){
		atendimento (filas);
		printf("\n\nNormal: ");
		printaFila(filas -> normal);
		printf("\n\nPrioridade: ");
		printaFila(filas -> prioritaria);
	}

	printaFila(fila);

	destroiFilaControle (&filas);

	if (filas == NULL){
		printf("\nDeu certo\n");
	}
	
	return 0;
}