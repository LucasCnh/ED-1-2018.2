#include <stdio.h>
#include "tad.h"

#define TAMANHO_SIM 100
#define CONSTANTE TAMANHO_SIM/2

int main()
{
  // printf("Ate aqui ok");
	Poligono* polig = NULL;


	polig = criaPoligono(polig, 9);


	insercao(polig, 0, 0);//check
	insercao(polig, 3, 0);//check
	insercao(polig, 0, 3);//check
	insercao(polig, 3, 5);//check
	insercao(polig, -3, -5);//check
  insercao(polig, -3, 1);//check
  insercao(polig, 3, -1);//check
  insercao(polig, -3, 0);//check
  insercao(polig, 0, -1);//check

  printf("QtdMax = %i, QtdAtual = %i\n", polig -> qtdMaxPontos, polig -> qtdAtualPontos);
  
	for (int i = 0; i < (polig -> qtdAtualPontos); i++){
		printf("Ponto %i = (%i, %i)\n", i + 1, polig -> poligono[i].x, polig -> poligono[i].y);
	}

	printf("\n\n");

  impressao(polig);

  destroi(&polig);
	
	return 0;
}