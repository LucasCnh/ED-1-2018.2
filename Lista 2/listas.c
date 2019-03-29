#include <stdio.h>
#include <stdlib.h>
#include "lista_dupla.h"

ListaDupla* criaListaDupla (){ //Função que criará uma lista duplamente encadeada

	ListaDupla* l = (ListaDupla*) malloc(sizeof(ListaDupla)); //Alocando uma nova lista

	if (l != NULL){ //Se a lista pôde ser alocada
		l -> head = NULL; //A cabeça da lista é startada como NULL
		l -> tail = NULL; //O rabo da lista é startado como NULL
		//A lista começa vazia
	}

	return l; //A lista é retornada
}

//QUESTÃO 1:
int insercaoListaDupla (ListaDupla* l, int dado){ //Função que inserirá um novo nó na lista

	if (l == NULL) return 0; //Se a lista não existir, a função retorna 0

	Node* n = (Node*) malloc(sizeof(Node)); //Alocando um novo nó á lista

	if (n == NULL) return 0; //Se o novo nó não pôde ser alocado, a função retorna 0

	if (l -> head == NULL){ //Caso a lista esteja vazia
		l -> head = n; //A cabeça passa a ser o novo nó
		l -> tail = n; //O rabo passa a ser o novo nó
		l -> head -> next = NULL; //O próximo nó passa a ser NULL
		l -> head -> prev = NULL; //O nó anterior passa a ser NULL
		n -> dado = dado; //O dado do novo nó será igual ao dado pelo usuário
		return 1; //A função retorna 1, simbolizando que a inserção foi bem-sucedida
	}

	l -> tail -> next = n; //O novo nó é inserido no final da lista
	n -> prev = l -> tail; //O nó anterior ao novo passa a ser o antigo rabo
	n -> next = NULL; //O nó posterior ao novo passa a ser o NULL
	l -> tail = n; //O novo rabo passa a ser o novo nó
	n -> dado = dado; //O dado do novo nó será igual ao dado pelo usuário
	return 1; //A função retorna 1, simbolizando que a inserção foi bem-sucedida
}
//

int removeListaDupla (ListaDupla* l, int dado){//Função que removerá dado nó da lista

	if (l == NULL) return 0; //Caso a lista não exista, a função retorna 0

	Node* aux = l -> head; //Ponteiro auxiliar que percorrerá a lista

	while (aux != NULL){ //Enquanto não chega ao último nó
		if (aux -> dado == dado){ //Se o dado do nó atual for igual ao dado informado pelo usuáro
			
			if (aux -> prev != NULL){ //Se o nó anterior existir
				aux -> prev -> next = aux -> next; //O nó posterior ao anterior passará a ser o nó posterior á aux
			}else{ //Se o prev não existir significa que é o primeiro elemento da lista
				l -> head = l -> head -> next; //A cabeça passa a ser o nó posterior
				free(aux); //O nó encontrado é desalocado da memória
				if (l -> head != NULL){ //Se a cabeça atual não for NULL (lista vazia)
					l -> head -> prev = NULL; //O nó anterior passa a ser NULL
				}

				return 1; //A função retorna 1, simbolizando que a remoção foi bem-sucedida
			}
			
			if (aux -> next != NULL){ //Se o nó posterior existir
				aux -> next -> prev = aux -> prev; //O nó anterior ao posterior passará a ser o nó anterior á aux
			}

			free(aux); //O nó encontrado é desalocado da memória
			return 1; //A função retorna 1, simbolizando que a remoção foi bem-sucedida
		}

		aux = aux -> next; //O ponteiro continuará percorrendo a lista
	}

	return 0; //A função retorna 0, simbolizando que nenhum valor foi removido
}

void printaListaDupla (ListaDupla* l){ //Função que printa os valores da lista dupla

	if (l == NULL) return; //Se a lista não existir, a função aborta

	Node* aux = l -> head; //Ponteiro auxiliar que percorrerá a lista

	while (aux != NULL){ //Enquanto não chegar á última posição
		printf("%i ", aux -> dado); //Printando o valor do nó atual
		aux = aux -> next; //Aux continua a percorrer a lista
	}

	printf("\n\n\n"); //Printando quebras de linha pra ficar bonitinho

	return;
}

//QUESTÃO 3
int destroiListaDupla (ListaDupla** l){ //Função que destruirá uma lista duplamente encadeada

	if (*l == NULL) return 0; //Se a lista não existir a função retorna 0

	Node* aux = (*l) -> head; //Ponteiro auxiliar que percorrerá a lista
	Node* p; //Segundo ponteiro auxiliar que guardará a referência para a posição posterior ao aux

	while (aux != NULL){ //Enquanto não chegar ao último elemento da lista 
		p = aux -> next; //p guardará a posição posterior á aux
		free(aux); //O nó atual é liberado da memória
		aux = p; //Aux passa a apontar para a próxima posição
	}

	free(*l); //A lista em si é desalocada
	*l = NULL; //O ponteiro passado como parâmetro passa a apontar para NULL
	return 1; //A função retorna 1, simbolizando que a destruição foi bem-sucedida
}
//