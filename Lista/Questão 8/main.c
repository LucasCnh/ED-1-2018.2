#include <stdio.h>
#include "tad_pilha.h"

#define TAM 20

/*
Questão 8

Faça um procedimento recursivo para procurar por um valor x em uma pilha de
inteiros, ambos passados como parâmetros, sendo que, ao final, a pilha deverá
permanecer intacta.
*/

int busca (Pilha* pilha, int x){

	Pilha* aux = NULL;

	if (pilha -> topo == (pilha -> qtdAtual - 1)){
		if (pilha -> topo == -1){
			return -111;
		}
	
		aux = criaPilha(pilha -> qtdMax);

		
		if (aux == NULL){
			return -111;
		}

		for (int i = 0; i < (pilha -> topo); i++){
			aux -> valores[i] = pilha -> valores[i];
		}

		aux -> topo = pilha -> topo - 1;
		aux -> qtdMax = pilha -> qtdMax;
		aux -> qtdAtual = pilha -> qtdAtual;
	}

	if (pilha -> topo == -1){
		destroiPilha(&pilha);
		return -111;
	}

	if (pilha -> valores[pilha -> topo] != x){
		if (pilha -> topo == (pilha -> qtdAtual - 1)){
			return busca (aux, x);
		}else{
			pilha -> topo--;
			return busca (pilha, x);
		}
	}else{
		if (pilha -> topo == (pilha -> qtdAtual - 1)){
			return pilha -> topo;
		}else{
			int auxiliar = pilha -> topo;
			destroiPilha(&pilha);
			return auxiliar;
		}
	}
}

int main(){

	Pilha* pilha = criaPilha(TAM);

	int j = 6;

	for (int i = 0; i < TAM; i++){
		push(pilha, i);
		printaPilha(pilha);
	}

	printf("%i\n\n", pilha -> topo);
	printf("Valor %i encontrado em: %i\n\n", j, busca(pilha, j));
	printaPilha(pilha);
	printf("\n%i\n\n", pilha -> topo);

	destroiPilha(&pilha);

	return 0;
}