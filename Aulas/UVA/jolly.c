#include <stdio.h>
#include <stdlib.h>
#include "jolly.h"
#include "pilha.h"
// typedef struct _Node_ { //Nó que representará o valor atual da sequência
// 	struct _Node_* next; //Próximo número da sequência
// 	int num; //Número atual
// }Node;

// typedef struct _Lista_ { //Lista que representará a sequência
// 	Node* head;
// 	int jolly;
// 	int tam;
// }Lista;

void checaJolly (){

	Lista* input = (Lista*) malloc(sizeof(Lista));
	input -> head = (Node*) malloc(sizeof(Node));
	input -> head = NULL;
	input -> jolly = 0;
	input -> size = 0;

	Lista* lista = (Lista*) malloc(sizeof(Lista));
	lista -> head = (Node*) malloc(sizeof(Node));
	lista -> head = NULL;
	lista -> jolly = 0;
	lista -> size = 0;

	int n;
	int j;

	scanf("%i", &n);

	for (int i = 0; i < n; i++){
		scanf("%i", &j);
		push(&input, j);
	}

	//printf("n = %i\n", n);

	Node* atual = input -> head;
	Node* prox = atual -> next;
	int repetido = 0;
	Node* aux = lista -> head;

	while (prox != NULL){
		aux = lista -> head;
		while (aux != NULL){
			if (((abs(atual -> num - prox -> num)) == aux -> num) || ((abs(atual -> num - prox -> num)) > (n - 1))){
				repetido = 1;
				break;
			}

			aux = aux -> next;
		}

		//printf("subtracao = %i\n", (abs(atual -> num - prox -> num)));

		if (repetido == 0){
			push(&lista, (abs(atual -> num - prox -> num)));
		}

		repetido = 0;
		prox = prox -> next;
		atual = atual -> next;
	}

	//printaLista(input);
	//printaLista(lista);
	//printf("Tamanho input = %i\n", input -> size);
	//printf("Tamanho lista = %i\n", lista -> size);
	if (lista -> size == input -> size - 1){
		printf("Jolly\n");
	}else{
		printf("Not jolly\n");
	}

	destroiLista(&input);
	destroiLista(&lista);

	return;
}

void printaLista (Lista* lista){ //Função que printa os membros de uma lista

	if (lista == NULL){ //Checa se a lista existe
		printf("NULL\n"); //Caso não exista, a função printa NULL
		return;
	}

	Node* pointer = lista -> head; //Ponteiro auxiliar que percorrerá a lista

	while (pointer != NULL){ //Enquanto não chegar além do último nó da lista
		printf("%i ", pointer -> num); //Printa o dado de cada nó da lista
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