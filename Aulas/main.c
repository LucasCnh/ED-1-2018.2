#include <stdio.h>
#include "codigo_8_10_18.h"

int main(){

	Pilha* pilha = criar(5);

	push(&pilha, 6);

	printf("\nFUNCIONOU!!!\n");
	//printaLista(pilha);

	return 0;
}