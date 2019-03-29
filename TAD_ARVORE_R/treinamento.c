#include <stdio.h>
#include <stdlib.h>
#include "lista_dupla.h"
#include "tad.h"
#include "treinamento.h"

void encontraFolhas(Node* t){

	if (t == NULL) return;

	if (t -> esq == NULL && t -> dir == NULL){
		printf("%i ", t -> dado);
	}

	encontraFolhas(t -> esq);
	encontraFolhas(t -> dir);

	return;
}

void encontraNosEmNivel(Node* t, int nivel){

	if (t == NULL) return;

	if (nivel == 0){
		printf("%i ", t -> dado);
		return;
	}

	int aux = nivel - 1;
	encontraNosEmNivel(t -> esq, aux);
	encontraNosEmNivel(t -> dir, aux);

	return;
}

int arvoresIguais (Node* t1, Node* t2){

	if (t1 == NULL && t2 == NULL) return 1;

	if (t1 == NULL || t2 == NULL) return 0;

	if (!arvoresIguais(t1 -> esq, t2 -> esq)) return 0;
	if (!arvoresIguais(t1 -> dir, t2 -> dir)) return 0;

	if (t1 -> dado == t2 -> dado) return 1;

	return 0;
}

int repeticoes (Node* t, int valor){

	int rep = 0;

	if (t == NULL) return rep;

	if (t -> dado == valor) rep++;

	rep += repeticoes(t -> esq, valor);
	rep += repeticoes(t -> dir, valor);

	return rep;
}

int arvoreCheia (Node* t){

	if (t -> esq == NULL && t -> dir == NULL) return 1;

	if (t -> esq == NULL || t -> dir == NULL) return 0;

	if (arvoreCheia(t -> esq) && arvoreCheia(t -> dir)) return 1;

	return 0;
}

int numElementos (Node* t){

	int num = 0;

	if (t == NULL) return num;

	num += numElementos (t -> esq);
	num += numElementos (t -> dir);

	num++;

	return num;
}

int numElementosAPartirDeH (Node* t, int h){

	int num = 0;

	if (t == NULL) return num;

	int aux = h - 1;

	num += numElementosAPartirDeH (t -> esq, aux);
	num += numElementosAPartirDeH (t -> dir, aux);

	if (h <= 0) num++;

	return num;
}

int arvoreEspelhada (Node** t){

	if ((*t) -> esq == NULL && (*t) -> dir == NULL) return 1;

	if (arvoreEspelhada(&(*t) -> esq) && arvoreEspelhada(&(*t) -> dir)){
		Node* aux = (*t) -> esq;
		(*t) -> esq = (*t) -> dir;
		(*t) -> dir = aux;
	}

	return 1;
	
}

ListaDupla* retornaEmOrdem (Node* t, ListaDupla* l){

	if (l == NULL){
		l = criaListaDupla();
	}

	if (t == NULL) return l;

	retornaEmOrdem(t -> esq, l);
	insercaoListaDupla(l, t -> dado);
	retornaEmOrdem(t -> dir, l);

	return l;
}