#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

Node* criaArvore (int dado){

	Node* t = (Node*) malloc(sizeof(Node));

	if (t != NULL){
		t -> esq = t -> dir = NULL;
		t -> dado = dado;
	}

	return t;
}

int insercao (Node** t, int dado){

	if (*t == NULL){
		*t = criaArvore(dado);
		return 1;
	}

	Node* p = *t;

	while (p != NULL){

		if (dado > p -> dado){
			p = p -> dir;
		}
		else{
			p = p -> esq;
		}
	}

	p = criaArvore(dado);

	return 1;
}

Node* busca (Node** t, int dado){

	if (*t == NULL) return NULL;

	Node* p = *t;

	while (p != NULL){

		if (p -> dado == dado) return p;

		if (dado > p -> dado){
			p = p -> dir;
		}
		else{
			p = p -> esq;
		}
	}

	return NULL;
}

int remocao (Node** t, int dado){

	if (*t == NULL) return 0;

	Node* rem = busca(&(*t), dado);

	if (rem == NULL) return 0;

	if (rem -> esq == NULL && rem -> dir == NULL){
		free(rem);
		rem = NULL;
	}
}	

void preOrdem (Node* t){

	if (t == NULL) return;

	preOrdem(t -> esq);
	printf("%i ", t -> dado);
	preOrdem(t -> dir);

	return;
}

void emOrdem (Node* t){

	if (t == NULL) return;

	emOrdem(t -> esq);
	printf("%i ", t -> dado);
	emOrdem(t -> dir);

	return;
}

void posOrdem (Node* t){

	if (t == NULL) return;

	posOrdem(t -> esq);
	printf("%i ", t -> dado);
	posOrdem(t -> dir);

	return;
}

int destroi (Node** t){

	if (*t == NULL) return 1;

	Node* p = (*t) -> 
}
