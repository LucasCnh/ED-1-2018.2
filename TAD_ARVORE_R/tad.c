#include <stdio.h>
#include <stdlib.h>
#include "tad.h"

Node* criaArvore (int valor){

	Node* t = (Node*) malloc(sizeof(Node));

	if (t != NULL){
		t -> esq = t -> dir = NULL;
		t -> dado = valor;
	}

	return t;
}

int insercao (Node** t, int valor){

	if (*t == NULL){
		*t = criaArvore(valor);
		return 1;
	}

	if (valor > (*t) -> dado){
		return insercao(&(*t) -> dir, valor);
	}
	else{
		return insercao(&(*t) -> esq, valor);
	}
}

Node* maiorDireita (Node** esq){

	if (*esq == NULL) return NULL;

	if ((*esq) -> dir != NULL){
		return maiorDireita(&(*esq) -> dir);
	}
	else{

		Node* ret = *esq;

		if ((*esq) -> esq != NULL){
			*esq = (*esq) -> esq;
		}
		else{
			*esq = NULL;
		}

		return ret;
	}
}

int remocao (Node** t, int valor){

	if (*t == NULL) return 0;

	if ((*t) -> dado == valor){

		if ((*t) -> esq == NULL && (*t) -> dir == NULL){

			free(*t);
			*t = NULL;
			return 1;
		}

		Node* aux = maiorDireita(&(*t) -> esq);

		if (aux == NULL){

			aux = (*t) -> dir;
			free(*t);
			*t = aux;

			return 1;
		}
		else{

			aux -> dir = (*t) -> dir;
			aux -> esq = (*t) -> esq;
			free(*t);
			*t = aux;

			return 1;
		}
	}
	
	if (remocao(&(*t) -> esq, valor)) return 1;

	if (remocao(&(*t) -> dir, valor)) return 1;

	return 0;
}

void preOrdem (Node* t){

	if (t == NULL) return;

	printf("%i ", t -> dado);
	preOrdem(t -> esq);
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
	posOrdem(t -> dir);
	printf("%i ", t -> dado);

	return;
}

int destroi (Node** t){

	if (*t == NULL) return 0;

	destroi (&(*t) -> esq);
	destroi (&(*t) -> dir);
	
	free(*t);
	*t = NULL;

	return 1;
}

