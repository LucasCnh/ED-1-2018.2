#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tad.h"

#define TAMANHO_SIM 100
#define CONSTANTE TAMANHO_SIM/2

/*
@criaPoligono(Poligono* polig, int maxPontos);
@prepara o poligono para receber os pontos
@caso o poligono polig em questão já exista a funcao retorna o mesmo e evita alocação em um espaço já alocado
@caso alguma alocação tenha dado errado ou maxPontos seja <= 0, a função retorna polig como NULL
@a função criaPoligono tambem seta a quantidade atual de pontos (polig -> qtdAtualPontos) como 0 e a quantidade máxima (polig -> qtdMaxPontos) como igual á maxPontos.
*/
Poligono* criaPoligono(Poligono* polig, int maxPontos){

	//Checando se o poligono já exista ou o usuário esteja de sacanagem e mandou alocar um vetor de tamanho menor ou igual a zero
	if ((polig != NULL) || (maxPontos <= 0)){
		return polig;
	}

	polig = (Poligono*) malloc(sizeof(Poligono));

	//Checando se a alocação deu certo
	if (polig == NULL){
		return polig;
	}

	polig -> poligono = (Pontos*) malloc((maxPontos)*sizeof(Pontos));

	polig -> quadrantes = (int**) malloc(TAMANHO_SIM*sizeof(int*));

	for (int i = 0; i < TAMANHO_SIM; i++){
		polig -> quadrantes[i] = (int*) malloc(TAMANHO_SIM*sizeof(int));
	}

	//Checando se as alocações deram certo
	if ((polig -> poligono != NULL) && (polig -> quadrantes != NULL)){
		polig -> qtdMaxPontos = maxPontos;
		polig -> qtdAtualPontos = 0;

		for (int i = 0; i < TAMANHO_SIM; i++){
			for (int j = 0; j < TAMANHO_SIM; j++){
				polig -> quadrantes[i][j] = 0;
			}
		}
	}else{
		if (polig -> poligono != NULL){
			free(polig -> poligono);
			polig -> poligono = NULL;
		}

		if (polig -> quadrantes != NULL){
			for (int i = 0; i < TAMANHO_SIM; i++){
				if (polig -> quadrantes[i] != NULL){
					free(polig -> quadrantes[i]);
					polig -> quadrantes[i] = NULL;
				}
			}

			free(polig -> quadrantes);
			polig -> quadrantes = NULL;
		}

		free(polig);
		polig = NULL;
	}

	return polig;
}

/*
@insercao(Poligono* polig, int x, int y);
@insere um novo ponto (inteiros x e y) aos dados do poligono e ordena os dados de forma a facilitar a impressão retornando 1
@caso a quantidade maxima de pontos (qtdMaxPontos) tenha sido atingida retorna 0
@caso algo esteja alocado indevidamente (ou não esteja alocado) retorna 0
@caso o ponto já exista no poligono retorna 0
*/
int insercao(Poligono* polig, int x, int y){

	//Checando alocações
	if ((polig == NULL) || (polig -> qtdAtualPontos >= polig -> qtdMaxPontos) || (polig -> poligono == NULL) || (polig -> quadrantes == NULL)){
		return 0;
	}

	//Checando se o ponto fornecido nos parametros da função já é existente
	for (int i = 0; i < (polig -> qtdAtualPontos); i++){
		if ((x == polig -> poligono[i].x) && (y == polig -> poligono[i].y)){
			return 0;
		}
	}

	polig -> poligono[polig -> qtdAtualPontos].x = x;
	polig -> poligono[polig -> qtdAtualPontos].y = y;

	polig -> qtdAtualPontos++;

	//Ordenando os pontos do mais perto da origem (0, 0) ao mais distante
	if (polig -> qtdAtualPontos > 1){

		Pontos* aux = (Pontos*) malloc(sizeof(Pontos));

		if (aux == NULL){
			return 0;
		}

		for (int i = 0; i < polig -> qtdAtualPontos; i++){
			for (int j = i+1; j < polig -> qtdAtualPontos; j++){
				if (((abs((polig -> poligono[j].x) + (polig -> poligono[j].y)))) < (abs((polig -> poligono[i].x) + (polig -> poligono[i].y)))){
					aux -> x = polig -> poligono[j].x;
          aux -> y = polig -> poligono[j].y;
					polig -> poligono[j] = polig -> poligono[i];
					polig -> poligono[i].x = aux -> x;
          polig -> poligono[i].y = aux -> y;
				}
			}
		}

		free(aux);

		//Colocando os valores na matriz que irá simular o polígono
		for (int k = 0; k < polig -> qtdAtualPontos; k++){
			for (int i = 0; i < TAMANHO_SIM; i++){
				for (int j = 0; j < TAMANHO_SIM; j++){
					if ((j == CONSTANTE) && (polig -> quadrantes[i][j] != 1)){
						polig -> quadrantes[i][j] = 3;
					}

					if ((i == CONSTANTE) && (polig -> quadrantes[i][j] != 1)){
						polig -> quadrantes[i][j] = 2;
					}

					if ((((polig -> poligono[k].x) >= 0) && ((polig -> poligono[k].y) >= 0)) || (((polig -> poligono[k].x) <= 0) && ((polig -> poligono[k].y) >= 0))){
						if (((CONSTANTE - i) == (polig -> poligono[k].y)) && ((j - CONSTANTE) == ((polig -> poligono[k].x)))){
							polig -> quadrantes[i][j] = 1;
						}
          }else if ((((polig -> poligono[k].x) < 0) && ((polig -> poligono[k].y) <= 0))){
						if (((CONSTANTE - i) == (polig -> poligono[k].y)) && ((CONSTANTE - j) == (abs(polig -> poligono[k].x)))){
							polig -> quadrantes[i][j] = 1;
						}
          }else{
            if (((CONSTANTE - i) == (polig -> poligono[k].y)) && ((j - CONSTANTE) == (polig -> poligono[k].x))){
              polig -> quadrantes[i][j] = 1;
            }
          }
				}
			}
		}

	}

	return 1;
}

int impressao(Poligono* polig){

  if ((polig == NULL) || (polig -> poligono == NULL) || (polig -> quadrantes == NULL)){
    return 0;
  }

  for (int i = 0; i < TAMANHO_SIM; i++){
		for (int j = 0; j < TAMANHO_SIM; j++){
			if (polig -> quadrantes[i][j] == 3){
				printf("|");
			}

			if (polig -> quadrantes[i][j] == 2){
				printf("=");
			}

			if (polig -> quadrantes[i][j] == 1){
				printf("*");
			}

			if (polig -> quadrantes[i][j] == 0){
				printf(" ");
			}
		}
		printf("\n");
	}

  return 1;
}

int destroiPoligono(Poligono** polig){

	aux = *polig;

	if ((aux == NULL) || (aux -> poligono == NULL) || (aux -> quadrantes == NULL)){
		return 0;
	}

	free(aux -> poligono);
	aux -> poligono = NULL;

	for (int i = 0; i < (aux -> qtdMaxPontos); i++){
		if (aux -> quadrantes[i] != NULL){
			free(aux -> quadrantes[i]);
			aux -> quadrantes[i] = NULL;
		}
	}

	free(aux -> quadrantes = NULL);

	free(aux);
	aux = NULL;
  	*polig = aux;

  	return 1;
}