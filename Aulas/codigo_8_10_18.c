#include <stdio.h>
#include <stdlib.h>
#include "codigo_8_10_18.h"

Pilha* criar(int dado){

	Pilha *ret = NULL;

	ret = (Pilha*) malloc(sizeof(Pilha));

	if (ret != NULL){
		ret -> dado = dado;
		ret -> next = NULL;
	}

	return ret;
}

int push (Pilha** cab, int dado){
	
	Pilha* novo = criar(dado);

	if (novo == NULL) return 0;

	if (*cab == NULL) 
		*cab = novo;
	else{
		Pilha* copia = *cab;

		while (copia -> next != NULL)
			copia = copia -> next;
		copia -> next = novo;
	}	

	return 1;
}

int pop(Pilha** cab){

	Pilha* atual, *ant, *rem;

	if (*cab != NULL){
		if ((*cab) -> next == NULL){
			rem = *cab;
			*cab = NULL;
		}
		else{
			ant = *cab;
			atual = (*cab) -> next;

			while (atual -> next != NULL){
				ant = atual;
				atual = atual -> next;
			} 

			rem = atual;
			ant -> next = NULL;
		}
	
		int ret = rem -> dado;
		free(rem);
		rem = NULL;
		return ret;
	}
}

// void printaLista (Pilha* lista){ //Função que printa os membros de uma lista

// 	if (lista == NULL){ //Checa se a lista existe
// 		printf("NULL\n"); //Caso não exista, a função printa NULL
// 		return;
// 	}

// 	Node* pointer = lista -> head; //Ponteiro auxiliar que percorrerá a lista

// 	while (pointer != NULL){ //Enquanto não chegar além do último nó da lista
// 		printf("%i ", pointer -> dado); //Printa o dado de cada nó da lista
// 		pointer = pointer -> next; //O ponteiro passa a referenciar o próximo nó da lista
// 	}

// 	printf("\n\n\n"); //Printando quebras de linhas para ficar bonitinho :3

// 	return;
// }
