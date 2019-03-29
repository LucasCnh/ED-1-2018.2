#include <stdio.h>
#include <stdlib.h>
#include "generic_tad.h"

int comparador (void* a, void* b){

	int* dado1 = (int*) a;
	int* dado2 = (int*) b;

	if (*dado1 == *dado2){
		return 0;
	}

	return 1;
}

void printador (void* a){

	int* dado = (int*) a;

	printf("%i ", *dado);

	return;
}

void desalocador (void* a){

  int* b = (int*) a;

	free(b);
	b = NULL;

	return;
}

int main()
{
	int i;
	Sequencia* seq = NULL;
	int *chave;

	seq = criaSequencia (10, comparador, printador, desalocador);

	for (int j = 0; j < (seq -> qtdMax); j++){
	  	chave = (int*) malloc(sizeof(int));
	  	if (j == 0){
    		*chave = j;
	  	}else{
	  		*chave = 2;
	  	}

		i = inserir(seq, (void*)chave);
    	//free(chave);
    	//chave = NULL;
	}

	chave = (int*) malloc(sizeof(int));
	*chave = 2;

	printf("%i\n", busca(seq, (void*)chave));

	chave = (int*) malloc(sizeof(int));
	*chave = 2;

	printf("%i\n", remover(seq, (void*)chave));

	chave = (int*) malloc(sizeof(int));
	*chave = 2;

	printf("%i\n", removerTodos(seq, (void*)chave));
	
	printar(seq);

	i = destroi(&seq);

	return 0;
}