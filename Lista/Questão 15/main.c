#include <stdio.h>
#include "tad_pilha.h"

/*
Questão 15

Escreva a função BUSCA_E_REMOVE(pilha p, valor v) que buscar o valor v numa
pilha p e remove esse elemento da pilha usando apenas as operações de pop e push.
*/

int BUSCA_E_REMOVE(Pilha* p, int v){

	if ((p == NULL) || (p -> valores == NULL)){
		return 0;
	}

	Pilha* aux = criaPilha(p -> qtdMax);

	while (p -> topo != -1){
		if (p -> valores[p -> topo] != v){
			push(aux, pop(p));
		}else{
			p -> topo--;
			p -> qtdAtual--;
			break;
		}
	}

	while (aux -> topo != -1){
		push(p, pop(aux));
	}

	destroiPilha(&aux);

	return 1;
}

int main(){

	Pilha* pilha = criaPilha(20);

	for (int i = 0; i < 20; i++){
		push(pilha, i);
	}

	printaPilha(pilha);

	BUSCA_E_REMOVE(pilha, 6);

	printaPilha(pilha);

	return 0;
}