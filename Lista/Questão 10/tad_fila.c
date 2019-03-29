#include <stdio.h>
#include <stdlib.h>
#include "tad_fila.h"

Fila* criaFila (int tamanho){ //Cria uma nova fila alocando uma estrutura e um vetor que a representará

	if (tamanho <= 0){ //Se o usuário informou um valor negativo ou igual a zero para o tamanho do vetor a função retornará NULL
		return NULL;
	}

	Fila* fila = (Fila*) malloc(sizeof(Fila)); //Alocando a estrutura

	if (fila == NULL){
		return fila; //Caso a estrutura não pôde ser alocada a função retorna o valor atual de fila (NULL)
	}

	fila -> valores = (int*) malloc(tamanho*sizeof(int)); //Alocando o vetor que representará a fila com o tamanho dado pelo usuário do TAD

	if (fila -> valores == NULL){ //Checando se o vetor fila -> valores pôde ser alocado devidamente
		free(fila); //Caso não a função desaloca a estrutura do tipo Fila
		fila = NULL; //Atribui ao ponteiro o valor NULL
		return fila; //Retorna o ponteiro com o valor NULL
	}

	fila -> qtdMax = tamanho; //A quantidade máxima de pessoas na fila será correspondente ao tamanho do vetor
	//FILA VAZIA AINDA
	fila -> prim = -1; //A primeira posição será igual a -1
	fila -> ult = 0; //A última posição será igual a 0

	return fila;
}

int enqueue (Fila* fila, int valor){ //Função que insere nova pessoa na fila caso a mesma exista ou não esteja cheia

	if ((fila == NULL) || (fila -> valores == NULL)){
		return 0; //Checando se a fila está alocada corretamente caso nao esteja a função retorna 0
	}

	if (empty(fila)){ //Checando se a fila não é vazia pois caso contrário como prim será == -1, a inserção deverá ser feita de maneira diferente da normal
		fila -> valores[fila -> ult] = valor;
		fila -> ult++;
		fila -> prim++; //Como a fila estava vazia (fila -> prim == -1) o primeiro da fila passa a ser a posição 0 do vetor
		return 1;
	}

	if ((fila -> ult) != (fila -> prim)){ //Checando se a fila não está cheia usando o conceito de vetor circular
		fila -> valores[fila -> ult] = valor; //Inserindo o valor na ultima posição da fila
		fila -> ult = (fila -> ult + 1)%fila -> qtdMax; //Agora a ultima posição será igual á posição posterior no vetor circular
		return 1;
	}else{
		return 0;
	}
}

int dequeue (Fila* fila){ //Função que atende uma pessoa na fila

	if ((fila == NULL) || (fila -> valores == NULL)){
		return 0; //Checando se a fila está alocada corretamente caso nao esteja a função retorna 0
	}

	if (empty(fila)){ //Checando se a fila está vazia
		return 0; //Caso esteja nenhum valor poderá ser atendido
	}

	fila -> prim = (fila -> prim + 1)%fila -> qtdMax; //O primeiro valor é retirado da fila e o primeiro valor passa a ser a posição seguinte do vetor circular

	if (fila -> prim == fila -> ult){ //Caso o primeiro valor da fila seja igual ao último da fila significa que a fila voltou a ser vazia
		fila -> prim = -1;
		fila -> ult = 0;
	}

	return 1;

}

int empty (Fila* fila){ //Função que checa se a fila está vazia

	if ((fila == NULL) || (fila -> valores == NULL)){
		return 1; //Caso a fila não esteja alocada a mesma é considerada vazia
	}

	if ((fila -> prim == -1) && (fila -> ult == 0)){
		return 1; //Caso o primeiro da fila seja -1 e o último 0 significa que a fila está vazia
	}

	return 0;
}

void printaFila (Fila* fila){ //função que imprime na tela o valor de cada pessoa presente na fila

	if ((fila == NULL) || (fila -> valores == NULL)){ //Caso a fila não exista nada é printado
		return;
	}

	if (empty(fila)){ //Caso a fila esteja vazia a nada é printado
		return;
	}

	int i = fila -> prim;

	do{ //O do - while foi usado pois caso a fila já estivesse cheia o valor de i já seria igual ao valor de fila -> ult

		printf("%i ", fila -> valores[i]); //Printa o valor da posição atual de i na fila
		i = ((i + 1)%fila -> qtdMax); //Incrementa o i de acordo com o vetor circular
	}while (i != fila -> ult); //O loop continuará até o valor de i ser igual á fila -> ult

	printf("\n\n\n");

	return;
}

int destroiFila (Fila** fila){ //Função que destruirá a fila


	//Para evitar digitar o '*' toda vez, um ponteiro para uma estrutura do tipo Fila foi criado
	Fila* aux = *fila; //E a ele atribuído a fila á ser destruída (*fila)

	if ((aux == NULL) || (aux -> valores == NULL)){ //Caso a fila já esteja desalocada a função retorna 0
		return 0; //Simbolizando que não foi possível destruir uma fila inexistente
	}

	free(aux -> valores); //Desaloca o vetor aux -> valores
	aux -> valores = NULL; //Atribui ao ponteiro o valor de NULL

	free(aux); //Desaloca a estrutura em si
	aux = NULL; //E atribui ao ponteiro o valor de NULL
	*fila = NULL; //Atribui também ao ponteiro dado no parâmetro

	return 1;
}