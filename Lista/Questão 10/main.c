#include <stdio.h>
#include "tad_fila.h"
#include "tad_pilha.h"

#define TAM 20

/*
Questao 10

Faça um procedimento RemoveElemento( int fila Q, int x) que elimina um certo x de
uma fila Q sem alterar a ordem dos demais elementos.
*/

int removeElemento (Fila* Q, int x){

	if ((Q == NULL) || (Q -> valores == NULL)){
		return 0;
	}

	Pilha* aux = criaPilha(Q -> qtdMax);
	int encontrado = 0;

	if ((aux == NULL) || (aux -> valores == NULL)){
		return 0;
	}

	if (x == Q -> valores[Q -> prim]){
    	return dequeue(Q);
  	}

	if (!(empty(Q))){
		do{
			Q -> ult--;
			if (Q -> ult == -1){
				Q -> ult = Q -> qtdMax - 1;
			}
			if (Q -> valores[Q -> ult] == x){
			
				encontrado = 1;
				break;
			}
			push(aux, Q -> valores[Q -> ult]);
		}while(Q -> prim != Q -> ult);
	}else{
		return 0;
	}

	while(aux -> topo != -1){
		enqueue(Q, pop(aux));
	}

	destroiPilha(&aux);

	if (encontrado == 1){
		return 1;
	}else{
		return 0;
	}
}

int main(){

	Fila* Q = criaFila(TAM);

	for (int i = 0; i < TAM; i++){
		enqueue(Q, i);
	}

	printaFila(Q);

	removeElemento(Q, 30);

	printaFila(Q);

	removeElemento(Q, 3);

	printaFila(Q);

	destroiFila(&Q);

	return 0;
}