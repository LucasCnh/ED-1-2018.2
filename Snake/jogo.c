#include <stdio.h>
#include <stdlib.h>
#include "snake.h"
#include "jogo.h"

Jogo* criaJogo (int tamanho){ //Cria uma nova estrutura do tipo Jogo

	Jogo* jogo = (Jogo*) malloc(sizeof(Jogo)); //Alocando uma nova estrutura do tipo Jogo que armazenará informações

	if (jogo == NULL) return jogo; //Caso a estrutura não puder ser alocada, a função retorna NULL

	jogo -> plano = (int**) malloc(sizeof(int*)); //Alocando o plano de jogo com o tamanho especificado pelo usuário

	for (int i = 0; i < 1; i++){ //Alocando o plano de jogo
		jogo -> plano[i] = (int*) malloc(tamanho*sizeof(int));
	}

	if (jogo -> plano == NULL){ //Caso o plano de jogo não puder ser alocado 
		free(jogo); //Desaloca a estrutura do tipo Jogo
		jogo = NULL; //Estrutura passa a ser NULL
		return jogo; //Retorna NULL ao usuário
	}

	jogo -> tamPlano = tamanho; //O tamanho do plano será igual ao tamanho especificado pelo usuário
	jogo -> pontuacao = 0; //Inicializa a pontuação
	jogo -> state = 0; //Inicializa com o state igual ao menu principal
	jogo -> frutas = 0; //Inicializa o jogo com nenhuma fruta na tela
	jogo -> fx = -1; //Posição x da fruta
	jogo -> fy = -1; //Posição y da fruta

	return jogo; //Retorna a estrutura do tipo Jogo ao usuário
}

int destroiJogo (Jogo** jogo){ //Destroi a estrutura do tipo Jogo

	if ((*jogo) == NULL) return 0; //Caso o jogo não exista, a função retorna 0

	if ((*jogo) -> plano != NULL){ //Caso a matriz plano esteja alocada
		
		for (int i = 0; i < ((*jogo) -> tamPlano); i++){ //Desaloca cada coluna
			if ((*jogo) -> plano[i] != NULL){ //Se a coluna estiver alocada
				free((*jogo) -> plano[i]); //Desaloca
				(*jogo) -> plano[i] = NULL; //Apontando o ponteiro da coluna á NULL
			}
		}

		free((*jogo) -> plano); //Desaloca a matriz
	}

	free(*jogo); //Desalocando a estrutura do tipo Jogo em si
	*jogo = NULL; //O ponteiro passado como parâmetro passa a apontar á NULL

	return 1; //A função retorna 1, simbolizando que a destruição foi bem-sucedida
}