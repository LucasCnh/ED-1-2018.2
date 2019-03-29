#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cassino.h"

Lista* criaLista (){ //Função que cria uma nova lista

	Lista* lista = (Lista*) malloc (sizeof(Lista)); //Alocando uma nova lista

	if (lista == NULL) return lista; //Caso a lista não puder ser alocada retorna NULL

	lista -> head = NULL; //A cabeça começa sendo nula

	return lista; //Retornando a nova lista alocada
}

int push (Lista** lista, int valor, char* nome){ //Função que insere uma nova carta ao baralho

	if (*lista == NULL) return 0; //Caso a lista não exista, a função retorna 0

	Carta* novo = (Carta*) malloc(sizeof(Carta)); //Criando uma nova carta

	if (novo == NULL) return 0; //Caso a nova carta não puder ser alocada, a função retorna 0

	novo -> terno = (char*) malloc(100); //Alocando o nome da carta

	if (novo -> terno == NULL){ //Caso o vetor não puder ser alocado
		free(novo); //Desaloca o novo nó
		return 0; //A função retorna 0
	}

	novo -> next = (*lista) -> head; //A próxima carta será o atual topo do deck

	(*lista) -> head = novo; //O novo topo do deck será a nova carta

	novo -> valor = valor; //Inserindo o valor da nova carta
	strcpy(novo -> terno, nome); //Inserindo o nome da nova carta

	return 1; //A função retorna 1, simbolizando que a inserção foi um sucesso
}

int ordenaLista (Lista** lista){ //Função que ordena a lista do menor valor para o maior

	if ((*lista) == NULL || (*lista) -> head == NULL) return 0; //Caso a lista não exista, a função retorna 0

	Carta* i = (*lista) -> head; //Ponteiro que percorrerá a lista
	Carta* j = i -> next; //Ponteiro que percorrerá a lista a cada iteração do ponteiro i
	Carta* aux = (Carta*) malloc(sizeof(Carta)); //Nó auxiliar que guardará temporariamente valores
	aux -> terno = (char*) malloc(100); //Vetor terno do nó auxiliar sendo alocado

	if (aux == NULL || aux -> terno == NULL){ //Caso o nó auxiliar ou seu terno não puder ser alocado apropriadamente
		if (aux != NULL){ //Se o nó auxiliar já não for nulo
			free(aux); //Desaloca o nó auxiliar
		}
		return 0; //A função retorna 0
	}

	while (i != NULL){ //Ponteiro i que percorrerá a lista
		while (j != NULL){ //Ponteiro j que percorrerá a lista á cada iteração do ponteiro i
			if ((i -> valor) > (j -> valor)){ //Se o valor de i for menor que o valor de j
				aux -> valor = i -> valor; //O nó aux guarda o valor de i
				strcpy(aux -> terno, i -> terno); //O nó aux guarda o nome de i
				i -> valor = j -> valor; //O valor de i é trocado com o valor de j
				strcpy(i -> terno, j -> terno); //O nome de i é trocado com o nome de j
				j -> valor = aux -> valor; //O valor de j é trocado com o valor de i
				strcpy(j -> terno, aux -> terno); //O nome de j é trocado com o nome de i
			}

			j = j -> next; //j passa a ser o próximo nó
		}

		i = i -> next; //i passa a ser o próximo nó
		if (i != NULL){ //Caso i não seja o último
			j = i -> next; //j começará a próxima iteração do primeiro nó após i
		}
	}

	free(aux -> terno); //O vetor terno de aux é desalocado
	free(aux); //O nó aux em si é desalocado
	aux = NULL; //aux passa a apontar para NULL

	return 1; //A função retorna 1, simbolizando que a ordenação foi bem-sucedida
}

void printaLista (Lista* lista){ //Função que printa o baralho

	if (lista == NULL) return; //Caso a lista não exista, a função imediatamente retorna

	Carta* pointer = lista -> head; //Criando um ponteiro auxiliar que percorrerá a lista

	printf("\n\n"); //Printando quebras de linhas pra ficar legível

	while (pointer != NULL){ //Enquanto o ponteiro não encontrar o fim da lista
		printf("%s\n", pointer -> terno); //Cada nome de carta será printado
		pointer = pointer -> next; //O ponteiro passa a apontar para o próximo nó
	}

	printf("\n"); //Printando quebra de linha pra ficar bonitinho

	return; //Fim da função
}

int destroiLista (Lista** lista){ //Função que destroi a lista

	if ((*lista) == NULL) return 0; //Caso a lista já esteja desalocada, a função retorna 0

	Carta* aux = (*lista) -> head; //Ponteiro auxiliar que andará pela lista
	Carta* pointer = aux -> next; //Ponteiro que guardará o próximo nó da lista

	while (aux != NULL){ //Enquanto não chegar ao fim da lista
		free(aux -> terno); //Desaloca o nome da carta
		free(aux); //Desaloca o atual nó
		aux = pointer; //Guardando o próximo nó
		if (pointer != NULL){ //Se o próximo nó já não for NULL
			pointer = pointer -> next; //Pointer guardará o nó seguinte
		}
	}

	free(*lista); //A lista é desalocada
	*lista = NULL; //O ponteiro passado como parâmetro passa a ser NULL
	return 1; //A função retorna 1, simbolizando que a destruição foi um sucesso
}
