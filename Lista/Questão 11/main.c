#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad_pilha.h"

#define TAM 20

/*
Questao 11

Seja uma seqüência de E's e D's que significam ações de empilhar e desempilhar,
respectivamente, elementos em/de uma certa pilha S, faça um algoritmo que verifique
uma seqüência qualquer e retorne OK ou NOK para o caso de seqüência bem formada
ou mal formada.
Exemplo: EEEEEDD (bem formada); EDEDEEDDDEEE (mal formada).
*/

int main(){

	Pilha* S = criaPilha(TAM);
	char* sequencia = (char*) malloc(1000);
	int bemFormada = 1;

	sequencia = "EEEEEDD";

	for (int i = 0; i < strlen(sequencia); i++){
		if (sequencia[i] == 'E'){
			if ((push(S, i)) == 0){
				bemFormada = 0;
			}
		}else{
			if ((pop(S)) == -111){
				bemFormada = 0;
			}
		}
	}

	if (bemFormada){
		printf("OK\n");
	}else{
		printf("NOK\n");
	}

	destroiPilha(&S);

	return 0;
}