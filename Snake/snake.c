#include <stdio.h>
#include <stdlib.h>
#include "snake.h"
#include "tad_snake.c"

Snake* criaSnake (int tamanho){ //Função que cria uma nova snake

	Snake* snk = (Snake*) malloc(sizeof(Snake)); //Alocando uma nova snake

	if (snk == NULL) return NULL; //Se a estrutura do tipo Snake não puder ser alocada, a função retorna NULL

	snk -> tam = 0; //Inicializando a snake com tamanho 0
	snk -> orientacao = 0; //Inicializando a snake com orientação horizontal
	snk -> head = NULL; //Inicializa a snake com a cabeça nula

	while (snk -> tam < 3){ //Inicializando a snake com três asteriscos
		
		if (!(pushSnake(&snk, tamanho/2 - (snk -> tam - 1), tamanho/2))){ //Caso um dos "pushs" não for bem-sucedido 
			destroiSnake (&snk); //Todas as posições alocadas anteriormente serão removidas
			return snk; //Retorna NULL ao usuário
		}
	}

	return snk; //Retorna a snake inicializada para o programa
}

int destroiSnake (Snake** snk){ //Função que destroi a snake atual

	if ((*snk) == NULL) return 0; //Caso a estrutura do tipo Snake já esteja desalocada retorna 0

	Corpo* auxiliar = (*snk) -> head; //Ponteiro auxiliar que percorrerá a snake desalocando cada membro da mesma
	Corpo* pointer = (*snk) -> head -> next; //Ponteiro que guardará o next para o auxiliar

	while (auxiliar != NULL){ //Enquanto a última posição não for desalocada
		free(auxiliar); //A posição atual é desalocada
		auxiliar = NULL; //O ponteiro para a posição atual passa a ser NULL
		auxiliar = pointer; //O ponteiro auxiliar passa a apontar para a próxima posição
		if (pointer != NULL){ //Se o ponteiro que apontará para a posição após o outro ponteiro já não for nulo
			pointer = pointer -> next; //O ponteiro apontará para a posição seguinte
		}
	}

	free(*snk); //Libera da memória a estrutura do tipo Snake em si
	*snk = NULL; //Aponta o ponteiro da mesma á NULL
	
	return 1; //Retorna NULL ao usuário
}