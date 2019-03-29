#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_PILHA_Generic.h"

/*
Questão 2

Escreva um algoritmo para determinar se uma string de caracteres de entrada é da
forma: xCy, onde x é uma string consistindo nas letras 'A' e 'B', e y é o inverso de x
(isto é, se x = "ABABBA", y deve equivaler a "ABBABA"). Em cada ponto, você só
poderá ler o próximo caractere da string.
*/

void printador (void* a){

	char* c = (char*) a;

	printf("%c", *c);

	return;
}

void desalocador (void* a){

	char* c = (char*) a;

	free(c);
	c = NULL;

	return;
}

int main(){

	char* x = (char*) malloc(1000);
	char* y = (char*) malloc(1000);
	char* z = (char*) malloc(1000);
	char* aux = (char*) malloc(sizeof(char));

	strcpy(x, "ABABBA");
	strcpy(y, "ABBABA");

  	PilhaG* pilha = criaPilhaG(strlen(y), printador, desalocador);

	if ((strlen(x)) == (strlen(y))){
		for (int i = 0; i < strlen(y); i++){
			*aux = y[i];
			pushG(pilha, (void*) aux);
			aux = (char*) malloc(sizeof(char));
		}


		int j = 0;
		while (pilha -> topo != -1){
			aux = (char*) popG(pilha);
			z[j] = *aux;
			j++;
			aux = (char*) malloc(sizeof(char));
		}

    	z[j] = '\0';

		if ((strcmp(x, z)) == 0){
			printf("Sao do tipo xCy!\n");
		}else{
      		printf("N sao do tipo xCy...\n");
    	}
	}else{
		printf("N sao do tipo xCy...\n");
	}

	destroiPilhaG(&pilha);
	free(x);
	free(y);
	free(z);

	return 0;
}