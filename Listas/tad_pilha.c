#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "tad_pilha.h"

int push (Lista** p, int valor){ //Adiciona um novo valor á pilha

	if ((*p) == NULL) return 0; //Se a lista não existir retorna 0

	Node* novo = (Node*) malloc(sizeof(Node)); //Aloca um novo nó

	if (novo == NULL) return 0; //Se o novo nó não pôde ser alocado a função retorna 0

	novo -> dado = valor; //Atribui ao dado do novo nó o valor a ser adicionado á pilha
	novo -> next = (*p) -> head; //O próximo valor a ser referenciado pelo novo nó da lista será o antigo topo da pilha
	(*p) -> head = novo; //O novo topo da pilha será o novo nó (a cabeça da lista representa o topo da pilha)

	return 1; //A função retorna 1, simbolizando que o push foi bem-sucedido
}

int pop (Lista** p){ //Retira o topo da pilha da mesma

	if ((*p) == NULL || (*p) -> head == NULL) return 0; //Se a lista não existir a função retorna 0

	int dado; //Dado da cabeça a se retornado

	Node* aux = (*p) -> head; //Nó auxiliar que referenciará a cabeça atual da lista (o topo atual da pilha)

	(*p) -> head = aux -> next; //A cabeça passa a ser o próximo nó

	dado = aux -> dado; //Dado recebe o dado da cabeça

	free(aux); //A cabeça é desalocada da memória
	aux = NULL; //O nó auxiliar passa a ser NULL

	return dado; //A função retorna 1, simbolizando que o pop foi bem-sucedido
}