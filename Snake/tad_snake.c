#include <stdio.h>
#include <stdlib.h>
#include "snake.h"
#include "tad_snake.h"

int pushSnake (Snake** snk, int posX, int posY){ //Insere um novo asterisco ao corpo da snake na direita (horizontal) ou em cima (vertical)

	if ((*snk) == NULL) return 0; //Se a snake não existir, a função retorna 0

	Corpo* novo = (Corpo*) malloc(sizeof(Corpo*)); //Alocando um novo asterisco para a snake

	if (novo == NULL) return 0; //Caso o corpo não pôde ser alocado, a função retorna 0

	novo -> posX = posX; //A posição x do novo asterisco é igual á posX
	novo -> posY = posY; //A posição y do novo asterisco é igual á posY
	novo -> next = (*snk) -> head; //O próximo asterisco relativo ao novo asterisco será a antiga cabeça
	(*snk) -> head = novo; //A nova cabeça passa a ser o novo asterisco alocado
	(*snk) -> tam++; //O tamanho da snake é atualizado

	return 1; //A função retorna 1, simbolizando que a inserção foi um sucesso
}

int popSnake (Snake** snk){ //Retira um asterisco do corpo da snake na direita (horizontal) ou em cima (vertical)

	if ((*snk) == NULL || (*snk) -> head == NULL) return 0; //Caso a snake não exista ou a mesma esteja vazia (morta), a função retorna 0

	Corpo* aux = (*snk) -> head; //Ponteiro auxiliar que guardará a cabeça atual

	(*snk) -> head = (*snk) -> head -> next; //A nova cabeça passa a ser o próximo asterisco do corpo

	free(aux); //Desalocando da memória a cabeça antiga
	aux = NULL; //Apontando o ponteiro aux á NULL

	return 1; //A função retorna 1, simbolizando que a remoção foi um sucesso
}

int dequeueSnake (Snake** snk){ //Retira um asterisco do corpo da snake na esquerda (horizontal) ou em baixo (vertical)

	if ((*snk) == NULL || (*snk) -> head == NULL) return 0; //Caso a snake não exista ou a mesma esteja vazia (morta), a função retorna 0

	if ((*snk) -> head -> next == NULL){ //Caso a snake só tenha uma posição
		
		Snake* aux = *snk; //Criando um ponteiro que apontará á snake atual
		popSnake(&aux); //Retirando o único asterisco do corpo
		*snk = aux; //A snake atual passa a ser a snake auxiliar
		return 1; //A função retorna 1, simbolizando que a remoção foi um sucesso
	}

	Corpo* pointer = (*snk) -> head; //Ponteiro que percorrerá a snake
	Corpo* aux = pointer; //Ponteiro auxiliar que guardará a posição anterior

	while (pointer -> next != NULL){ //Checando se a posição atual não é a última
		aux = pointer; //Guardando a posição anterior á última
		pointer = pointer -> next; //Prosseguindo para a próxima posição (nó) da cobra
	}

	free(pointer); //Desalocando o último asterisco da cobra
	pointer = NULL; //Apontando o ponteiro á NULL
	aux -> next = NULL; //A última posição passa a ser a anterior, guardada na variável aux

	return 1; //A função retorna 1, simbolizando que a remoção foi um sucesso
}