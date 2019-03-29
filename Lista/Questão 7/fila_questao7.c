#include <stdio.h>
#include <stdlib.h>
#include "tad_pilha.h"
#include "fila_questao7.h"

Fila* criaFila (int tamanho){

	if (tamanho <= 0){
		return NULL;
	}

	Fila* fila = (Fila*) malloc(sizeof(Fila));

	if (fila == NULL){
		return NULL;
	}

	fila -> P1 = criaPilha(tamanho);

	if (fila -> P1 == NULL){
		free(fila);
		fila = NULL;
	}

	fila -> P2 = criaPilha(tamanho);

	if (fila -> P2 == NULL){
		destroiPilha(&fila -> P1);
		free(fila);
		fila = NULL;
		return fila;
	}

	return fila;
}

int enqueue (Fila* fila, int valor){

	if ((fila == NULL) || (fila -> P1 == NULL) || (fila -> P2 == NULL)){
		return 0;
	}

	if ((fila -> P1 -> valores == NULL) || (fila -> P2 -> valores == NULL)){
		return 0;
	}
	
	P1 -> topo = -1;
	while (P2 -> topo > -1){
		push(P1, pop(P2));
	}

	if (push(P1, valor)){
		while (P2 -> topo > -1){
			push(P2, pop(P1));
		}
		return 1;
	}

	while (P2 -> topo > -1){
		push(P2, pop(P1));
	}

	return 0;
}

int dequeue (Fila* fila){

	if ((fila == NULL) || (fila -> P1 == NULL) || (fila -> P2 == NULL)){
		return 0;
	}

	if ((fila -> P1 -> valores == NULL) || (fila -> P2 -> valores == NULL)){
		return 0;
	}

	return pop(P2);
}

int empty (Fila* fila){

	if ((fila == NULL) || (fila -> P1 == NULL) || (fila -> P2 == NULL)){
		return 1;
	}

	if ((fila -> P2 -> valores == NULL)){
		return 1;
	}

	if (P2 -> topo == -1){
		return 1;
	}else{
		return 0;
	}
}

void printaFila (Fila* fila){

	if ((fila == NULL) || (fila -> P1 == NULL) || (fila -> P2 == NULL)){
		return;
	}

	if ((fila -> P2 -> valores == NULL)){
		return;
	}

	for (int i = pilha -> topo; i > -1; i--){
		printf("%i ", P2 -> valores[i]);
	}

	printf("\n\n\n");

	return;
}

int destroiFila (Fila** fila){

	Fila* aux = *fila;

	if ((aux -> P1 == NULL) || (aux -> P2 == NULL) || (aux -> P1 -> valores == NULL) || (aux -> P2 -> valores == NULL)){
		return 0;
	}

	destroiPilha(&aux -> P1);
	destroiPilha(&aux -> P2);
	free(aux);
	aux = NULL;
	*fila = NULL;

	return 1;
}