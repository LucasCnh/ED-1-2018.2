#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dicionario.h"

void clean (){
	int c;
	while ((c = getchar()) != '\n' && c != EOF){}
}

int main(){
	
	Dicionario* d = criaDicionario();
	char* palavra1 = (char*) malloc(1000);
	char* palavra2 = (char*) malloc(1000);
	char* texto = (char*) malloc(20000);
	int sair = 0;
	int input;

	if (d == NULL) return 1;

	while (1){
		printf("Escolha o que deseja fazer: \n\n\n");
		printf("1-Inserir nova palavra no dicionario\n");
		printf("2-Relacionar duas palavras como sinonimas\n");
		printf("3-Printar dicionario\n");
		printf("4-Trocar palavras de um texto por seus sinonimos menos usados\n");
		printf("?-Qualquer outro caractere: Sair do programa\n");
		scanf("%i", &input);
		printf("\n\n\n");

		switch (input){
			case 1:
				printf("Aperte qualquer tecla para prosseguir:\n");
				clean();
				printf("Informe a palavra que deseja inserir:\n");
				gets(palavra1);
				inserePalavra(d, palavra1);
				break;
			case 2:
				printf("Aperte qualquer tecla para prosseguir:\n");
				clean();
				printf("Informe a palavra:\n");
				gets(palavra1);
				printf("Informe seu sinonimo:\n");
				gets(palavra2);
				relacionaSinonimo(palavra1, palavra2, d);
				break;
			case 3:
				printf("Aperte qualquer tecla para prosseguir:\n");
				clean();
				printaDicionario(d);
				break;
			case 4:
				printf("Aperte qualquer tecla para prosseguir:\n");
				clean();
				printf("Informe o texto:\n\n");
				gets(texto);
				trocaTexto(texto, d);
				break;
			default:
				sair = 1;
		}

		if (sair == 1) break;
	}

	free(palavra1);
	free(palavra2);
	destroiDicionario(&d);

	return 0;
}