#include <stdio.h>
#include <stdlib.h>
#include "fila_1.h"

Fila* criaFila (int tamanho, Desalocar d, Printar p){ //OK

	if (tamanho <= 0){
		return NULL;
	}

	Fila* fila = (Fila*) malloc(sizeof(Fila));

	if (fila == NULL){
		return fila;
	}

	fila -> matriculas = (void**) malloc(tamanho*sizeof(void*));

	if (fila -> matriculas == NULL){
		free(fila);
		fila = NULL;
		return fila;
	}

  for (int i = 0; i < tamanho; i++){
    fila -> matriculas[i] = NULL;
  }

	fila -> qtdAtual = 0;
	fila -> qtdMax = tamanho;
	fila -> prim = -1;
	fila -> ult = 0;
	filas -> chamada = 0;
	fila -> des = d;
  	fila -> prin = p;

	return fila;
}


int enfileirar (Fila* fila, void* valor){ 

	if ((fila == NULL) || (fila -> matriculas == NULL)){
		return 0;
	}

	if ((vazia(fila)) == 1){
		fila -> matriculas[fila -> ult] = valor;
		fila -> ult = (fila -> ult + 1)%(fila -> qtdMax);
		fila -> prim++;
		fila -> qtdAtual++;

		return 1;
	}

	if ((fila -> qtdAtual) < (fila -> qtdMax)){
		fila -> matriculas[fila -> ult] = valor;
		fila -> ult = (fila -> ult + 1)%(fila -> qtdMax);
    	fila -> qtdAtual++;

		return 1;
	}

	return 0;
}

int desenfilar (Fila* fila){

	if ((fila == NULL) || (fila -> matriculas == NULL) ){
		return 0;
	}

	if ((vazia(fila)) == 1){
		return 0;
	}

	fila -> matriculas[fila -> prim] = NULL;
	fila -> prim = (fila -> prim + 1)%(fila -> qtdMax);
  	fila -> qtdAtual--;

	return 1;
}

int vazia (Fila* fila){

	if (fila -> prim == -1){
		return 1;
	}

	int cont = 0;

	int i = fila -> prim;

	do{
		if (fila -> matriculas[i] == NULL){
			cont++;
	}

	i = ((i + 1)%(fila -> qtdMax));
	}while(i != fila -> ult);


	if (cont == fila -> qtdMax){
		fila -> prim = -1;
		fila -> ult = 0;

		return 1;
	}

	return 0;
}

void printaFila (Fila* fila){

  if ((fila == NULL) || (fila -> matriculas == NULL) || (((vazia(fila))) == 1) || (fila -> prim == -1)){

    printf("Nada");
    return;
  }

  int i = fila -> prim;

    do{

      fila -> prin(fila -> matriculas[i]);
      i = ((i + 1)%(fila -> qtdMax));
    }while(i != fila -> ult);

  printf("\n\n");

  return;
}

int destroiFila (Fila** fila){

	Fila* aux = *fila;

	if (aux == NULL) return 0;

	if (aux -> matriculas == NULL){
		
		free(aux);
		aux = NULL;
		*fila = NULL;
		return 1;
	}

	for (int i = 0; i < (aux -> qtdMax); i++){
		aux -> des(aux -> matriculas[i]);
	}

	free(aux -> matriculas);
	aux -> matriculas = NULL;

	free(aux);
	aux = NULL;
	*fila = NULL;

	return 1;
}

Fila_controle* criaFilaControle (int tamanhoN, int tamanhoP, int peso, Desalocar d, Printar p){

	if ((peso <= 0) || (tamanhoN <= 0) || (tamanhoP <= 0)) return NULL;
	
	Fila_controle* filas = (Fila_controle*) malloc(sizeof(Fila_controle));

	if (filas == NULL){
		return NULL;
	}

	filas -> normal = criaFila(tamanhoN, d, p);

	if (filas -> normal == NULL){
		free(filas);
		filas = NULL;
		return NULL;
	}


	filas -> prioritaria = criaFila(tamanhoP, d, p);

	if (filas -> prioritaria == NULL){
		for (int i = 0; i < tamanhoN; i++){
			filas -> normal -> des(filas -> normal -> matriculas[i]);
		}
		free(filas -> normal);
		filas -> normal = NULL;
		free(filas);
		filas = NULL;
	}

	return filas;
}

int insereFilaControle (Fila_controle* filas, void* valor, int prioridade){

	if (filas == NULL) return 0;

	if (prioridade == 0){
		return enfileirar(filas -> normal, valor);
	}else{
		return enfileirar(filas -> prioritaria, valor);
	}
}

int atendimento (Fila_controle* filas){

	if ((filas == NULL) || (filas -> normal == NULL) || (filas -> prioritaria == NULL)) return 0;

	if ((filas -> chamada)%filas -> peso == 0){
		if ((desenfilar(filas -> normal)) == 0){
			filas -> chamada++;
			return desenfilar(filas -> prioritaria);
		}else{
			filas -> chamada++;
			return 1;
		}
	}else{
		if ((desenfilar(filas -> prioritaria)) == 0){
			filas -> chamada++;
			return desenfilar(filas -> normal);
		}else{
			filas -> chamada++;
			return 1;
		}
	}
}

int destroiFilaControle (Fila_controle** filas){

	if (filas == NULL){
		return 0;
	}

	Fila_controle* aux = *filas;

	destroiFila(&aux -> normal);
	destroiFila(&aux -> prioritaria);

	free(aux);
	aux = NULL;

	*filas = NULL;

	return 1;
}