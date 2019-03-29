#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "tad_fila.h"

int enqueue (Lista** f, int valor){ //Função que adiciona um novo valor ao fim da fila

	if ((*f) == NULL) return 0; //Caso a lista não esteja alocada, a função retorna 0

	Node* novo = (Node*) malloc(sizeof(Node)); //Alocando um novo nó

	if (novo == NULL) return 0; //Se o novo nó não pôde ser alocado a função retorna 0

	novo -> next = (*f) -> head; //O nó após o novo nó será a atual cabeça
	novo -> dado = valor; //Atribuindo o valor dado pelo usuário ao novo nó
	(*f) -> head = novo; //A cabeça passa a ser o novo nó

	return 1; //A função retorna 1, simbolizando que o valor pôde ser inserido com sucesso
}

int dequeue (Lista** f){ //Função que retira um valor do início da fila

	if ((*f) == NULL || (*f) -> head == NULL) return 0; //Caso a lista não esteja alocada, ou a mesma esteja vazia, a função retorna 0

	Node* pointer = ((*f) -> head); //Atribuindo á um ponteiro auxiliar o endereço da cabeça da lista
	Node* aux;

	while (pointer -> next != NULL){ //Percorre a lista até que se encontre a última posição da mesma (que é o primeiro da fila)
		aux = pointer; //Guardando a posição anterior para guardar em seu next o valor de NULL quando a última for encontrada
		pointer = pointer -> next; //O node pointer passa a ser o próximo 
	}

	free(pointer); //Desaloca a última posição
	pointer = NULL; //Atribui a mesma o valor de NULL
	aux -> next = NULL; //Atribuindo NULL ao próximo do novo último

	return 1;
}

int empty (Lista* f){ //Função que checa se a fila está vazia ou não

	if (f -> head == NULL) return 1; //Caso a cabeça esteja vazia a fila está vazia e a função retorna 1

	return 0; //Caso contrário, a função retorna 0
}