#include <stdio.h>
#include <stdlib.h>
#include "tad_imagem.h"

int comparar (void* a, void* b){
	int* N1 = (int*) a;
	int* N2 = (int*) b;

	if (N1 > N2){
		return 1;
	}

	if (N1 < N2){
		return -1;
	}

	return 0;
}

int main(){

	return 0;
}