#include <stdio.h>
#include <stdlib.h>
#include "tad_arvore.h"
#include "pessoas.h"

int main(){

	Tree* nomes = NULL;
	Tree* matriculas = NULL;
	Tree* datasEntrada = NULL;
	Tree* datasSaida = NULL;
	int input;


	while (1){
		
		printf("\n\n\nInforme o que deseja fazer: \n\n");
		printf("1. Cadastrar colaborador\n");
		printf("2. Editar colaborador\n");
		printf("3. Consultar colaborador\n\n");
		printf("(?) Sair --qualquer outra tecla--\n\n");

		scanf("%i", &input);
		clean_stdin();
		printf("\n\n\n");

		switch(input){
			case 1:
				cadastro(&nomes, &matriculas, &datasEntrada, &datasSaida);
				break;
			case 2:
				edicao(&nomes, &matriculas, &datasEntrada, &datasSaida);
				break;
			case 3:
				consulta(nomes, matriculas, datasEntrada, datasSaida);
				break;
		}

		if (input != 1 && input != 2 && input != 3){
			printf("\n\nVoce desejou sair do programa, volte sempre!\n");
			break;
		}
		
	}
	

	destroiArvores(&nomes, &matriculas, &datasEntrada, &datasSaida);

    return 0;
}