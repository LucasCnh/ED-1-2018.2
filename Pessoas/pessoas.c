#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoas.h"
#include "tad_arvore.h"
#include "tad_lista.h"

void cadastro (Tree** nomes, Tree** matriculas, Tree** datasEntrada, Tree** datasSaida){

	char* nome = (char*) malloc(1000);
	char* matricula = (char*) malloc(1000);
	char* dataEntrada = (char*) malloc(1000);
	char* dataSaida = (char*) malloc(1000);


	printf("\n\nInforme o nome do colaborador: ");
	gets(nome);

	printf("\n\nInforme a matricula do colaborador: ");
	gets(matricula);

	printf("\n\nInfrome a data de entrada do colaborador (na forma DD/MM/AAAA): ");
	gets(dataEntrada);

	printf("\n\nInforme a data de saida do colaborador (na forma DD/MM/AAAA)(caso o mesmo ainda nao tenha saido fique livre para digitar algo a respeito --ex: 'Ainda colaborando'):");
	gets(dataSaida);
	
	if (*nomes == NULL){
		*nomes = criaArvore((void*) nome, comparaNomes, desalocaNomes, printaNomes);
	}else{
		insercao(&(*nomes), (void*) nome);
	}

	ListaDupla* caminho = criaListaDupla();
	descobreColaborador(caminho, *nomes, nome);

	if (caminho -> head == NULL){

		*datasEntrada = criaArvore((void*) dataEntrada, comparaNomes, desalocaNomes, printaDatas);
		*datasSaida = criaArvore((void*) dataSaida, comparaNomes, desalocaNomes, printaDatas);
		*matriculas = criaArvore((void*) matricula, comparaNomes, desalocaNomes, printaMatriculas);
	}
	else{
	
		Tree* m = *matriculas;
		Tree* dE = *datasEntrada;
		Tree* dS = *datasSaida;
		Node* p = caminho -> head;

		while ((p -> next) != NULL){

			if (p -> dado == 1){
				m = m -> dir;
				dE = dE -> dir;
				dS = dS -> dir;
			}else{
				m = m -> esq;
				dE = dE -> esq;
				dS = dS -> esq;
			}

			p = p -> next;
		}

		if (p -> dado == 1){
			m -> dir = criaArvore((void*) matricula, comparaNomes, desalocaNomes, printaMatriculas);
			dE -> dir = criaArvore((void*) dataEntrada, comparaNomes, desalocaNomes, printaDatas);
			dS -> dir = criaArvore((void*) dataSaida, comparaNomes, desalocaNomes, printaDatas);
			m -> dir -> pai = m;
			dE -> dir -> pai = dE;
			dS -> dir -> pai = dS;
		}
		else{
			m -> esq = criaArvore((void*) matricula, comparaNomes, desalocaNomes, printaMatriculas);
			dE -> esq = criaArvore((void*) dataEntrada, comparaNomes, desalocaNomes, printaDatas);
			dS -> esq = criaArvore((void*) dataSaida, comparaNomes, desalocaNomes, printaDatas);
			m -> esq -> pai = m;
			dE -> esq -> pai = dE;
			dS -> esq -> pai = dS;
		}
	}

	destroiListaDupla(&caminho);
	printf("\n\n\n");

	return;

}

void edicao (Tree** nomes, Tree** matriculas, Tree** datasEntrada, Tree** datasSaida){

	ListaDupla* caminho;
	char* nome = (char*) malloc(1000);
	char* nomeNovo;
	char* matricula;
	char* dataEntrada;
	char* dataSaida;
	Tree* n, *m, *dE, *dS;
	int input, input2, flag = 0;

	if (*nomes == NULL || *matriculas == NULL || *datasEntrada == NULL || *datasSaida == NULL){
		printf("\n\n\nNao ha colaboradores no sistema!\n\n");
		free(nome);
		destroiListaDupla(&caminho);
		return;
	}

	while (1){

		printf("\n\n\n\n");
		caminho = criaListaDupla();
		printf("\nInforme o que deseja editar: \n\n");

		printf("1. Matricula do colaborador\n");
		printf("2. Data de Entrada do colaborador\n");
		printf("3. Data de Saida do colaborador\n");
		printf("4. Remover colaborador\n");
		printf("(?) Sair --qualquer outra tecla--\n\n");

		scanf("%i", &input);
		clean_stdin();

		if (input == 1 || input == 2 || input == 3 || input == 4){
			printf("\n\n\nColaboradores no sistema:\n\n");
			exibeColaboradores(*nomes, *matriculas, *datasEntrada, *datasSaida);
			printf("\n\nInforme como deseja encontrar o colaborador que deseja editar: (caso pesquise por um meio onde existem repetidos o primeiro encontrado será editado)\n");
			printf("1. Por nome:\n");
			printf("2. Por matricula: \n");
			printf("3. Por data de entrada:\n");
			printf("4. Por data de saida:\n");
			scanf("%i", &input2);
			clean_stdin();

			if (input2 == 1){
				printf("\n\n\n\n\n\nInforme o nome do colaborador a ser editado: ");
			}
			else if (input2 == 2){
				printf("\n\n\n\n\n\nInforme a matricula do colaborador a ser editado: ");
			}
			else if (input2 == 3){
				printf("\n\n\n\n\n\nInforme a data de entrada do colaborador a ser editado: ");
			}
			else if (input2 == 4){
				printf("\n\n\n\n\n\nInforme a data de saida do colaborador a ser editado: ");
			}

			gets(nome);
		}
		else{
			printf("\n\nSaindo da edicao... (pressione qualquer tecla)\n\n");
			clean_stdin();
			printf("\n\n\n");
			break;
		}

		if (input2 == 1){
			flag = descobreColaborador(caminho, *nomes, nome);
		}
		else if (input2 == 2){
			flag = descobreColaborador(caminho, *matriculas, nome);
		}
		else if (input2 == 3){
			flag = descobreColaborador(caminho, *datasEntrada, nome);
		}
		else if (input2 == 4){
			flag = descobreColaborador(caminho, *datasSaida, nome);
		}

		if (flag){
			
			n = *nomes;
			m = *matriculas;
			dE = *datasEntrada;
			dS = *datasSaida;
			Node* p = caminho -> head;

			while (p != NULL){

				if (p -> dado == 1){
					n = n -> dir;
					m = m -> dir;
					dE = dE -> dir;
					dS = dS -> dir;
				}else{
					n = n -> esq;
					m = m -> esq;
					dE = dE -> esq;
					dS = dS -> esq;
				}

				p = p -> next;
			}
		}
		else{
			
			printf("\n\nColaborador nao encontrado...\n\n\n\n");
			continue;
		}

		switch(input){

			case 1:
				matricula = (char*) malloc(1000);
				printf("\n\nInforme a nova matricula: ");
				gets(matricula);
				m -> des(m -> dado);
				m -> dado = (void*) matricula;
				printf("\n\nMatricula alterada com sucesso!\n\n");
				break;
			case 2:
				dataEntrada = (char*) malloc(1000);
				printf("\n\nInforme a nova dada de entrada (na forma DD/MM/AAAA):\n");
				gets(dataEntrada);
				dE -> des(dE -> dado);
				dE -> dado = (void*) dataEntrada;
				printf("\n\nData de entrada alterada com sucesso!\n\n");
				break;
			case 3:
				dataSaida = (char*) malloc(1000);
				printf("\n\nInforme a nova dada de saida (na forma DD/MM/AAAA)(caso o mesmo ainda nao tenha saido fique livre para digitar algo a respeito --ex: 'Ainda colaborando'):\n");
				gets(dataSaida);
				dS -> des(dS -> dado);
				dS -> dado = (void*) dataSaida;
				printf("\n\nData de saida alterada com sucesso!\n\n");
				break;
			case 4:
				//Concatenei com essa flag para evitar a remoção de mais de um colaborador (caso o mesmo venha a ter nomes iguais por exemplo)
				strcat((char*) n -> dado, "A REMOVER");
				strcat((char*) m -> dado, "A REMOVER");
				strcat((char*) dE -> dado, "A REMOVER");
				strcat((char*) dS -> dado, "A REMOVER");
				remocao(&(*nomes), n -> dado);
				remocao(&(*matriculas), m -> dado);
				remocao(&(*datasEntrada), dE -> dado);
				remocao(&(*datasSaida), dS -> dado);
				printf("\n\nColaborador removido com sucesso do sistema!\n\n");
				break;
		}	
		
		destroiListaDupla(&caminho);
	}

	free(nome);
	if (caminho != NULL){
		destroiListaDupla(&caminho);
	}

	return;
}

void consulta (Tree* nomes, Tree* matriculas, Tree* datasEntrada, Tree* datasSaida){

	int input;
	char* nome = (char*) malloc(1000);

	while (1){

		printf("\n\n\n\n\nInforme o criterio pelo qual deseja buscar o colaborador que deseja consultar:\n\n");

		printf("1. Por nome:\n");
		printf("2. Por matricula: \n");
		printf("3. Por data de entrada:\n");
		printf("4. Por data de saida:\n");
		printf("(?) Sair da consulta --qualquer outra tecla--\n");
		scanf("%i", &input);
		clean_stdin();

		if (input != 1 && input != 2 && input != 3 && input != 4){
			printf("\n\n\nSaindo da consulta... (pressione qualquer tecla)\n\n");
			clean_stdin();
			printf("\n\n\n");
			break;
		}
		if (input == 1){
			printf("\n\n\n\n\nInforme o nome do colaborador a ser consultado: ");
		}
		else if (input == 2){
			printf("\n\n\n\n\nInforme a matricula do colaborador a ser consultado: ");
		}
		else if (input == 3){
			printf("\n\n\n\n\nInforme a data de entrada do colaborador a ser consultado: ");
		}
		else if (input == 4){
			printf("\n\n\n\n\nInforme a data de saida do colaborador a ser consultado (ou comentario caso o mesmo nao tenha saido ainda): ");
		}

		gets(nome);

		if (input == 1){
			printf("\n\n\n\n\nColaboradores com o nome %s: \n\n", nome);
		}
		else if (input == 2){
			printf("\n\n\n\n\nColaboradores com a matricula %s: \n\n", nome);
		}
		else if (input == 3){
			printf("\n\n\n\n\nColaboradores com a data de entrada %s: \n\n", nome);
		}
		else if (input == 4){
			printf("\n\n\n\n\nColaboradores com a data de saida %s: \n\n", nome);
		}

		buscaColaborador(nomes, matriculas, datasEntrada, datasSaida, nome, input);

		printf("\n(Pressione qualquer tecla para prosseguir) \n\n");
		clean_stdin();
	}

	free(nome);
	return;
}

void buscaColaborador (Tree* nomes, Tree* matriculas, Tree* datasEntrada, Tree* datasSaida, char* nome, int input){

	if (nomes == NULL || matriculas == NULL || datasEntrada == NULL || datasSaida == NULL) return;

	buscaColaborador(nomes -> esq, matriculas -> esq, datasEntrada -> esq, datasSaida -> esq, nome, input);

	int flag = 1;

	if (input == 1){
		flag = nomes -> comp(nomes -> dado, (void*) nome);
	}
	else if (input == 2){
		flag = matriculas -> comp(matriculas -> dado, (void*) nome);
	}
	else if (input == 3){
		flag = datasEntrada -> comp(datasEntrada -> dado, (void*) nome);
	}
	else if (input == 4){
		flag = datasSaida -> comp(datasSaida -> dado, (void*) nome);
	}

	if (!flag){
		printf("\n\nNome do colaborador: ");
		nomes -> prin(nomes -> dado);
		matriculas -> prin(matriculas -> dado);
		printf("Data de entrada do colaborador: ");
		datasEntrada -> prin(datasEntrada -> dado);
		printf("Data de saida do colaborador: ");
		datasSaida -> prin(datasSaida -> dado);
	}

	buscaColaborador(nomes -> dir, matriculas -> dir, datasEntrada -> dir, datasSaida -> dir, nome, input);

	return;
}

int descobreColaborador (ListaDupla* l, Tree* nomes, char* nome){
	
	if (nomes == NULL){
		return 0;
	}

	if ((nomes -> comp(nomes -> dado, nome)) == 0){
		return 1;
	}

	if (descobreColaborador(l, nomes -> esq, nome)){
		insercaoListaDupla(l, 0);
		return 1;
	}

	if (descobreColaborador(l, nomes -> dir, nome)){
		insercaoListaDupla(l, 1);
		return 1;
	}

	return 0;
}

void exibeColaboradores (Tree* n, Tree* m, Tree* dE, Tree* dS){

	if (n == NULL || m == NULL || dE == NULL || dS == NULL) return;

	exibeColaboradores(n -> esq, m -> esq, dE -> esq, dS -> esq);
	printf("\nNome do colaborador: ");
	n -> prin(n -> dado);
	m -> prin(m -> dado);
	printf("Data de entrada do colaborador: ");
	dE -> prin(dE -> dado);
	printf("Data de saida do colaborador: ");
	dS -> prin(dS -> dado);
	exibeColaboradores(n -> dir, m -> dir, dE -> dir, dS -> dir);

	return;
}

void destroiArvores (Tree** n, Tree** m, Tree** dE, Tree** dS){

	destruirArvore(&(*n));
	destruirArvore(&(*m));
	destruirArvore(&(*dE));
	destruirArvore(&(*dS));

	*n = *m = *dE = *dS = NULL;

	return;
}

void clean_stdin(void){
    
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
