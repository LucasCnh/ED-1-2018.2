#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	Sequencia* sequencia = NULL;
	int input;
	int dado;

  while (1){

    printf("\nInforme o que deseja fazer com a sequencia:\n\n");
    printf("(1) Inserir novo elemento na sequencia\n(2) Remover elemento da sequencia\n(3) Buscar elemento na sequencia\n(4) Destruir a sequencia \n(5) Criar a sequencia\n(0) Sair do programa\n");

    scanf("%i", &input);

		switch(input){
			case 1:
				printf("Informe o elemento que deseja incluir na sequencia: \n");
				scanf("%i", &dado);

				if ((insert(sequencia, dado)) == 0){
					printf("\n");
				}else{
					printf("Elemento inserido com sucesso!\n");
 				}

				break;

			case 2:
				printf("Informe o elemento que deseja remover da sequencia: \n");
				scanf("%i", &dado);

				if ((remover(sequencia, dado)) == 0){
					printf("Nao foi possivel remover tal elemento da sequencia\n");
				}else{
          			printf("Elemento removido com sucesso!\n");
        		}

				break;

			case 3:
				printf("Informe o elemento que deseja buscar na sequencia: \n");
				scanf("%i", &dado);

				if ((search(sequencia, dado)) == 0){
					printf("Nao foi possivel buscar tal elemento\n");
				}else{
          			printf("\n\nElemento buscado com sucesso!\n");
        		}

				break;

			case 4:
				if ((destroy(&sequencia)) == 1){
					printf("Sequencia destruida com sucesso!\n");
				}else{
					printf("A sequencia ja esta destruida, querido(a)\n");
				}

				break;

			case 5:
				if (sequencia == NULL){
					printf("Informe o tamanho da sequencia:\n\n");
					scanf("%i", &dado);

					sequencia = create(dado);
				}else{
					printf("Ja ha uma sequencia existente...\n");
				}

				break;
		}

		if (input == 0){
			dado = destroy(&sequencia);
			printf("\nVoce desejou sair do programa! Flw!!!\n\n");
			break;		
		}
	}

	return 0;
}