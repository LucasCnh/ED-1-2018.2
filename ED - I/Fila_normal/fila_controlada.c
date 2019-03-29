#include <stdio.h>
#include <stdlib.h>
#include "fila_normal.h"
#include "fila_controlada.h"

Fila_controle* criaFilaControle (int tamanhoN, int tamanhoP, int peso){ //Função que aloca estrutura do tipo Fila_controle assim como seus membros

	Fila_controle* filas = (Fila_controle*) malloc(sizeof(Fila_controle)); //Aloca estrutura do tipo Fila_Controle

	if (filas == NULL){ //Se a estrutura não pôde ser alocada, a função retorna 0
		return filas; 
	}

	filas -> normal = criaFila(tamanhoN); //Criando a fila normal utilizando a função criaFila do TAD com o tamanho dado pelo usuário

	if ((filas -> normal == NULL) || (filas -> normal -> matriculas == NULL)){ //Se a fila normal não pôde ser alocada
		if (filas -> normal != NULL){ //Desaloca a estrutura do tipo Fila normal caso a mesma seja != NULL
			free(filas -> normal);
			filas -> normal = NULL; //Aponta o ponteiro da mesma á NULL
		}

		free(filas); //Desaloca a estrutura Fila_controle em si
		filas = NULL; //Aponta o ponteiro da mesma á NULL
		return filas;
	}

	filas -> prioritaria = criaFila(tamanhoP); //Criando a fila prioritária utilizando a função criaFila do TAD com o tamanho dado pelo usuário

	if ((filas -> prioritaria == NULL) || (filas -> prioritaria -> matriculas == NULL)){ //Se a fila prioritária não pôde ser alocada
		if (filas -> prioritaria != NULL){ //Desaloca a estrutura do tipo Fila prioritaria caso a mesma seja != NULL
			free(filas -> prioritaria);
			filas -> prioritaria = NULL; //Aponta o ponteiro da mesma á NULL
		}

		free(filas -> normal -> matriculas); //Desaloca o vetor da fila normal
		filas -> normal -> matriculas; //Aponta o ponteiro da mesma á NULL
		free(filas -> normal); //Desaloca a estrutura do tipo Fila normal
		filas -> normal = NULL; //Aponta o ponteiro da mesma á NULL

		free(filas); //Desaloca a estrutura Fila_controle em si
		filas = NULL; //Aponta o ponteiro da mesma á NULL
		return filas;
	}

	filas -> peso = peso; 
	filas -> qtdAtendidos = 0;

	return filas;
}

int enqueueControle (Fila_controle* filas, int valor, int prioridade){ //Função que inserirá uma nova pessoa na fila normal ou prioritária de acordo com o valor de prioridade
	
	if ((filas == NULL) || (filas -> normal == NULL) || (filas -> normal -> matriculas == NULL)){ //Checando se a fila normal está alocada devidamente assim como sua estrutura e a estrutura filas
		return 0; //Caso não esteja, a função retorna 0, simbolizando que não se pôde inserir a nova pessoa  
	}	

	if ((filas -> prioritaria == NULL) || (filas -> prioritaria -> matriculas == NULL)){ //Checando se a fila prioritária está alocada devidamente assim como sua estrutura
		return 0; //Caso não esteja, a função retorna 0, simbolizando que não se pôde inserir a nova pessoa  
	}

	if (prioridade == 0){ //Caso a prioridade seja igual a 0 a pessoa será inserida na fila normal
		return enqueue(filas -> normal, valor);
	}else{ //Caso a prioridade seja diferente de 0 a pessoa será inserida na fila prioritária
		return enqueue(filas -> prioritaria, valor);
	}
}

int dequeueControle (Fila_controle* filas){ //Função que atenderá uma nova pessoa na fila normal ou prioritária de acordo com o peso (razão)

	if ((filas == NULL) || (filas -> normal == NULL) || (filas -> normal -> matriculas == NULL)){  //Checando se a fila normal está alocada devidamente assim como sua estrutura e a estrutura filas
		return 0; //Caso não esteja, a função retorna 0, simbolizando que não se pôde atender a nova pessoa  
	}

	if ((filas -> prioritaria == NULL) || (filas -> prioritaria -> matriculas == NULL)){ //Checando se a fila prioritária está alocada devidamente assim como sua estrutura
		return 0; //Caso não esteja, a função retorna 0, simbolizando que não se pôde atender a nova pessoa  
	}

	if (((filas -> qtdAtendidos)%(filas -> peso)) == 0){ //A cada *peso* prioritários atendidos, 1 normal é atendido
		if (dequeue(filas -> normal)){ 
			filas -> qtdAtendidos++;
			return 1;
		}else{ //Se nao foi possivel atender da normal então alguem da fila prioritária é atendido
			filas -> qtdAtendidos++;
			return dequeue(filas -> prioritaria);
		}
	}else{ //Atendimento prioritário
		if (dequeue(filas -> prioritaria)){ 
			filas -> qtdAtendidos++;
			return 1;
		}else{ //Se não foi possivel atender da prioritária então alguem da fila normal é atendido
			filas -> qtdAtendidos++;
			return dequeue(filas -> normal);
		}
	}
}

int destroiFilaControle (Fila_controle** filas){

	Fila_controle* aux = *filas; //Criando um ponteiro do tipo Fila_controle para evitar escrever desnecessariamente o '*'
	//O mesmo apontará para a estrutura dada pelo usuário no parâmetro da função

	if ((aux == NULL) || (aux -> normal == NULL) || (aux -> normal -> matriculas == NULL)){ //Checando se algum dos membros já está desalocado
		return 0;
	}

	if ((aux -> prioritaria == NULL) || (aux -> prioritaria -> matriculas == NULL)){
		return 0; //Caso sim, a função retorna 0 simbolizando que não foi possível destruir filas inexistentes
	}

	//Destruindo as filas utilizando a funcao destroiFila do TAD
	destroiFila(&aux -> normal);
	destroiFila(&aux -> prioritaria);

	free(aux); //Destruindo a estrutura do tipo Fila_controle em si
	aux = NULL; //Atribuindo o ponteiro auxiliar criado á NULL
	*filas = NULL; //Atribuindo o ponteiro passado como parâmetro da função á NULL 

	return 1;
}