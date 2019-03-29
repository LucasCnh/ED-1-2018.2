#include <stdio.h>
#include <stdlib.h>
#include "TAD_PILHA_Generic.h"

void printador (void* a){

	int* c = (int*) a;

	printf("%i ", *c);

	return;
}

void desalocador (void* a){

	int* c = (int*) a;

	free(c);
	c = NULL;

	return;
}

void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int main(){

	Pilha* pilha = criaPilha(20, printador, desalocador);
	int* valor;
	char input;
	int* valor1;
	int* valor2;
	int* res;

	while (1){
		printf("Informe um numero para empilhar ou uma operacao para realizar\n");
		printf("'+' == somar\n'-' == subtrair\n'*' == multiplicar\n'/' == dividir\n\n\n'!' para sair\n\n");
		scanf("%c", &input);
		valor = (int*) malloc(sizeof(int));

		switch(input){
			case '+':
			case '-':
			case '/':
			case '*':
				if (pilha -> topo >= 1){
					switch(input){
						case '+':
							valor1 = (int*) malloc(sizeof(int));
							valor2 = (int*) malloc(sizeof(int));
							res = (int*) malloc(sizeof(int));
							valor1 = (int*) pop(pilha);
							valor2 = (int*) pop(pilha);
							*res = (*valor1) + (*valor2);
							push(pilha, (void*) res);
							break;
						case '-':
							valor1 = (int*) malloc(sizeof(int));
							valor2 = (int*) malloc(sizeof(int));
							res = (int*) malloc(sizeof(int));
							valor1 = (int*) pop(pilha);
							valor2 = (int*) pop(pilha);
							*res = (*valor1) - (*valor2);
							push(pilha, (void*) res);
							break;
						case '*':
							valor1 = (int*) malloc(sizeof(int));
							valor2 = (int*) malloc(sizeof(int));
							res = (int*) malloc(sizeof(int));
							valor1 = (int*) pop(pilha);
							valor2 = (int*) pop(pilha);
							*res = (*valor1) * (*valor2);
							push(pilha, (void*) res);
							break;
						case '/':
							valor1 = (int*) malloc(sizeof(int));
							valor2 = (int*) malloc(sizeof(int));
							res = (int*) malloc(sizeof(int));
							valor1 = (int*) pop(pilha);
							valor2 = (int*) pop(pilha);
							*res = (*valor1) / (*valor2);
							push(pilha, (void*) res);
							break;
					}
				}
				break;
			default:
				*valor = input - '0';
				push(pilha, (void*) valor);
		}

		printaPilha(pilha);
		clean_stdin();

		if (input == '!'){
			break;
		}
	}

	destroiPilha(&pilha);

	if (pilha == NULL){
		printf("Deu certo\n");
	}

	return 0;
}