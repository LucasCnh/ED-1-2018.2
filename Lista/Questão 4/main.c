#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Questão 4

Elabore um algoritmo que não use uma pilha para ler uma seqüência de operações
push e pop, e determine se está ocorrendo underflow ou não em alguma operação
pop.
*/

int main(){

	char* sequencia = (char*) malloc(1000);
	int contadorPush = 0;

	sequencia = "POPOPPPPPPOOOPPPOOOOOOOO";

	for (int i = 0; i < strlen(sequencia); i++){
		if (sequencia[i] == 'P'){
			contadorPush++;
		}else{
			contadorPush--;
		}

		if (contadorPush == -1){
			printf("Underflow na %i operacao\n", i);
			break;
		}
	}

	return 0;
}