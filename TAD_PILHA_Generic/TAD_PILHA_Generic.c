#include <stdio.h>
#include <stdlib.h>
#include "TAD_PILHA_Generic.h"

Pilha* criaPilha (int tamanho, Printar p, Desalocar d){ //Função responsável por criar (alocar) uma nova pilha

	Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));

	if (pilha == NULL){ //Checando se foi possível alocar a estrutura do tipo Pilha
		return pilha;
	}

	pilha -> valores = (void**) malloc(tamanho*sizeof(void*)); //Alocando o vetor valores que representará a pilha com o tamanho dado pelo usuário

	if (pilha -> valores == NULL){
		free(pilha);
		pilha = NULL;
		return pilha;
	}

	pilha -> topo = -1; //A pilha começará vazia
	pilha -> qtdMax = tamanho; //A quantidade máxima de valores na pilha será igual ao tamanho dado pelo usuário
	pilha -> prin = p;
	pilha -> des = d;

	return pilha;
}

int push(Pilha* pilha, void* valor){ //Função responsável por adicionar um novo valor ao topo da pilha

	if ((pilha == NULL) || (pilha -> valores == NULL)){ //Caso algo na pilha não esteja alocado devidamente a função retorna 0
		return 0;
	}

	if ((pilha -> topo) == (pilha -> qtdMax - 1)){ //Caso a pilha esteja cheia a função retorna 0
		return 0;
	}

	pilha -> topo++; //Novo topo da pilha: uma posição acima do topo anterior
	pilha -> valores[pilha -> topo] = valor; //Inserindo valor ao topo da pilha

	return 1;
}

void* pop(Pilha* pilha){ //Função responsável por remover um valor do topo da pilha

	int* aux = (int*) malloc(sizeof(int));

	*aux = -1;

	if ((pilha == NULL) || (pilha -> valores == NULL)){ //Caso algo na pilha não esteja alocado devidamente a função retorna -1
		return (void*) aux;
	}

	if (pilha -> topo == -1){ //Caso a pilha esteja vazia a função retorna -1
		return (void*) aux;
	}

	pilha -> topo--; //Decrementando o topo para eliminar a posição que contém o valor a ser removido
	return pilha -> valores[pilha -> topo + 1]; //A função retorna ao usuário o valor que foi removido
}

void printaPilha (Pilha* pilha){ //Função que printa a pilha

	if ((pilha == NULL) || (pilha -> valores == NULL)){ //Checando se a pilha está alocada devidamente
		return; //Caso contrário a função aborta
	}

	if (pilha -> topo == -1){
		return; //Caso a pilha esteja vazia a função também aborta
	}

	for (int i = 0; i <= (pilha -> topo); i++){ //Laço que percorrerá a pilha da base até o topo
		pilha -> prin(pilha -> valores[i]); //Printando cada posição da pilha utilizando a função genérica pilha -> prin
	}

	printf("\n\n");

	return;
}

int destroiPilha (Pilha** pilha){ //Função responsável por destruir a pilha (desalocar)

	Pilha* aux = *pilha; //Criando um ponteiro aux do tipo Pilha que apontará para *pilha

	if ((aux == NULL) || (aux -> valores == NULL)){ //Caso algum membro da estrutura do tipo Pilha já esteja desalocado a função retorna 0
		return 0;
	}

	for (int i = 0; i < (aux -> qtdMax); i++){ //Desalocando o vetor que representa a pilha
		aux -> des(aux -> valores[i]);
	}

	free(aux -> valores); 
	aux -> valores = NULL; //Apontando o ponteiro do mesmo á NULL
	free(aux); //Desalocando a estrutura do tipo Pilha em si
	aux = NULL; //Apontando o ponteiro local aux á NULL
	*pilha = NULL; //Apontando o ponteiro dado pelo parâmetro da função á NULL

	return 1;
}