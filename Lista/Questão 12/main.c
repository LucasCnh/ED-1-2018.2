#include <stdio.h>
#include "tad_fila.h"
#include "tad_pilha.h"

/*
Questão 12

Faça um procedimento interativo: PESQFILA( int fila Q, int x) que pesquisa em uma
fila Q por um argumento x, ambos passados como parâmetro.O procedimento deve
retornar V ou F caso encontre ou não o argumento. A fila, ao final do processo, não
deve estar alterada, por isso deve ser utilizada uma estrutura auxiliar (pilha ou fila)
para efetuar a pesquisa.
*/

int PESQFILA(Fila* Q, int x){

	if ((Q == NULL) || (Q -> valores == NULL) || (empty(Q))){
		return 0;
	}

	Pilha* aux = criaPilha(Q -> qtdMax);
	int encontrado = 0;

	if ((aux == NULL) || (aux -> valores == NULL)){
		return 0;
	}

	do{
		if (Q -> valores[Q -> ult] == x){
			encontrado = 1;
			break;
		}
		push(aux, Q -> valores[Q -> ult]);
		Q -> ult--;
		if (Q -> ult == -1){
			Q -> ult = Q -> qtdMax - 1;
		}
	}while (Q -> ult != Q -> prim);

	Q -> ult++;
	
	while (aux -> topo != -1){
		enqueue(Q, pop(aux));
	}

	destroiPilha(&aux);

	return encontrado;
}

int main(){

	Fila* fila = criaFila(20);

	for (int i = 0; i < 20; i++){
		enqueue(fila, i);
	}

	printaFila(fila);

	printf("\n\nEncontrado = %i\n\n", PESQFILA(fila, 7));

	printaFila(fila);

	return 0;
}