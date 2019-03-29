#ifndef JOGO
#define JOGO

/**
@jogo arquivo onde se encontram funções que tornam o jogo visível (jogável) para o usuário
*/

#include "snake.h"

typedef struct _Jogo_ { //Estrutura que conterá as informações do jogo
	int** plano; //Matriz que será utilizada para printar o jogo
	int tamPlano; //Tamanho da matriz plano
	int pontuacao; //Pontuação atual do jogador
	int state; //State atual do jogo
	int frutas; //Quantidade de frutas no jogo
	int fx; //Posição x da fruta
	int fy; //Posição y da fruta
}Jogo;

/**
@criaJogo (int tamanho)
@brief cria uma nova estrutura do tipo Jogo
@param tamanho é o tamanho da matriz plano
@return estrutura do tipo Jogo que representará o jogo
*/
Jogo* criaJogo (int tamanho);

/**
@insereJogo (Jogo* jogo)
@brief insere frutas e printa o jogo para o usuário
@param jogo é a estrutura do tipo Jogo a ser atualizada e printada
@param snk é a snake a ser inserida no plano de jogo
*/
void insereJogo (Jogo* jogo, Snake* snk);

/**
@stateMenu ()
@brief printa na tela o menu principal para o usuário
*/
void stateMenu ();

/**
@stateGameOver ()
@brief printa a tela de game over para o usuário
*/
void stateGameOver ();

/**
@stateFimDeJogo ()
@brief printa a tela de fim de jogo para o usuário
*/
void stateFimDeJogo ();

/**
@destroiJogo (Jogo** jogo)
@brief destroi o jogo atual
@param jogo é a estrutura do tipo Jogo a ser destruída
@return 1 caso a destruição tenha sido bem sucedida, 0 caso contrário
*/
int destroiJogo (Jogo** jogo);

#endif
