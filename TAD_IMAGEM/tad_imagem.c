#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad_imagem.h"

#define LIMITE 100
#define CALCUL LIMITE/2

Imagem* construir (int max, Comparar c){

	Imagem* img = (Imagem*) malloc(sizeof(Imagem));

	if (img == NULL){
		return img;
	}

	img -> pixels = (Pixel*) malloc(max*sizeof(Pixel));

	if (img -> pixels == NULL){
		free(img);
		img = NULL;
		return img;
	} 

	for (int i = 0; i < max; i++){
		img -> pixels[i] -> RGC = (char*) malloc(3);
		if (img -> pixels[i] == NULL){
			for (int j = 0; j < i; j++){
				free(img -> pixels[j] -> RGC);
				img -> pixels[j] -> RGC = NULL;
			}
			free(img -> pixels);
			img -> pixels = NULL;
			free(img);
			img = NULL;
			return img;
		}
	}


	img -> plano = (int**) malloc(LIMITE*sizeof(int*));

	for (int i = 0; i < LIMITE; i++){
		img -> plano = (int*) malloc(LIMITE*sizeof(int));
	}

	if (img -> plano == NULL){
		for (int j = 0; j < max; j++){
			free(img -> pixels[j] -> RGC);
			img -> pixels[j] -> RGC = NULL;
		}
		free(img -> pixels);
		img -> pixels = NULL;
		free(img);
		img = NULL;
		return img;
	}

	img -> qtdMaxPixels = max;
	img -> qtdAtualPixels = 0;
	img -> comp = c;

	return img;
}

int get1Pixel (Imagem* img, void* x, void* y, char* RGC){

	if ((img == NULL) || (img -> pixels == NULL) || (img -> plano == NULL) || (img -> qtdAtualPixels > img -> qtdMaxPixels)  || (strlen(RGC) != 3)){
		return 0;
	}

	int* limite = (int*) malloc(sizeof(int));
	*limite = LIMITE;

	if (((img -> comp(x, (void*) limite)) == 1) || (img -> comp(y, (void*) limite) == 1)){
		return 0;
	}

	int* limite = (int*) malloc(sizeof(int));
	*limite = LIMITE;

	if (((img -> comp(x, (void*) limite)) == -1) || (img -> comp(y, (void*) limite) == -1)){
		return 0;
	}

	for (int i = 0; i < qtdMaxPixels; i++){
		if ((img -> pixels[i] -> RGC == NULL)){
			return 0;
		}
	}

	img -> pixels[img -> qtdAtualPixels] -> x = x;
	img -> pixels[img -> qtdAtualPixels] -> y = y;
	strcpy(img -> pixels[img -> qtdAtualPixels] -> RGC, RGC); 

	img -> qtdAtualPixels++;

	int* limite1;
	int* limite2;

	for (int i = 0; i < LIMITE; i++){
		for (int j = 0; j < LIMITE; j++){
			limite1 = (int*)
			if (((img -> comp(x, j)) == 0) && ((img -> comp(y, i)) == 0)){
				img -> plano[i][j] = 
			}
		}
	}

	return 1;
}

int set1Pixel (Imagem* img, void* xAtual, void* yAtual, void* x, void* y){

}