#include <stdio.h>
#include <stdlib.h>
#include "generic_tad_2.h"

int comparar (void* a, void* b){

	int* V1 = (int*) a;
	int* V2 = (int*) b;

	if (*V1 == *V2) return 0;

	return 1;
}

void desaloca (void* a){

	int* V1 = (int*) a;

	//free(V1);
	V1 = NULL;

	return;
}

void printar (void* a){

	int* V1 = (int*) a;

	printf("%i ", *V1);

	return;
}

int main(){

	Sequencia* seq = NULL;
	int* valor;
	int chave;

	seq = criaSequencia(10, comparar, desaloca, printar);

	for (int i = 0; i < (seq -> qtdMax - 1); i++){
		valor = (int*) malloc(sizeof(int));
		if (i == 0){
			*valor = 0;
		}else{
			*valor = 2;
		}

		insercao(seq, (void*) valor);
	}

	valor = (int*) malloc(sizeof(int));
	*valor = 9;

	insercao(seq, (void*) valor);

	printa(seq);

	valor = (int*) malloc(sizeof(int));
	*valor = 2;

	removeTodos (seq, (void*) valor);

	printa(seq);

	valor = (int*) malloc(sizeof(int));
	*valor = 9;

	printf("Encontrado na posicao %i\n", busca(seq, (void*) valor));

	printa(seq);

	valor = (int*) malloc(sizeof(int));
	*valor = 17;

	insercao(seq, (void*) valor);

	printa(seq);

	destroi(&seq);

	if (seq == NULL){
		printf("\n\nOk");
	}

	return 0;
}