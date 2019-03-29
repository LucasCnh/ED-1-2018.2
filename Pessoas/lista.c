#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista* criaLista (void){ //Cria uma nova lista que representará a pilha

	Lista* nova = (Lista*) malloc(sizeof(Lista)); //Aloca uma nova lista
 
	if (nova == NULL) return NULL; //Checa se a nova lista foi alocada com sucesso, caso contrário a função retorna NULL

	nova -> head = NULL; //Atribui NULL á cabeça da lista 

	return nova; //Retorna a nova lista
}

void printaLista (Lista* lista){ //Função que printa os membros de uma lista

	if (lista == NULL){ //Checa se a lista existe
		printf("NULL\n"); //Caso não exista, a função printa NULL
		return;
	}

	Node* pointer = lista -> head; //Ponteiro auxiliar que percorrerá a lista

	while (pointer != NULL){ //Enquanto não chegar além do último nó da lista
		printf("%i ", pointer -> dado); //Printa o dado de cada nó da lista
		pointer = pointer -> next; //O ponteiro passa a referenciar o próximo nó da lista
	}

	printf("\n\n\n"); //Printando quebras de linhas para ficar bonitinho :3

	return;
}

int destroiLista (Lista** lista){ //função que destroi a lista

	Node* aux = (*lista) -> head; //Atribui á uma variável auxiliar a referência para a cabeça da lista
	Node* pointer = NULL; //Segundo nó auxiliar

	if (aux != NULL){ //Caso aux não seja NULL o next do mesmo será acessado
		pointer = (*lista) -> head -> next; //Atribui á uma segunda variável auxiliar a referência para o próximo nó da lista
	}


	if ((*lista) == NULL) return 0; //Caso a Lista não esteja alocada ou não exista nenhum nó na mesma ainda, a função retorna 0


	while (aux != NULL){ //Enquanto houver nós
		free(aux); //Desaloca o nó atual
		aux = NULL; //Atribui ao mesmo NULL
		aux = pointer; //Faz aux apontar para o próximo nó
		if (aux != NULL) pointer = aux -> next; //Faz a segunda variável auxiliar apontar para o nó seguinte ao nó aux (se aux existir)
	}

	free(*lista); //Desaloca a lista
	aux = NULL; //aux passa a ser NULL
	*lista = NULL; //O ponteiro passado como parâmetro passa a ser NULL

	return 1; //A função retorna 1, simbolizando que a destruição foi bem sucedida
}