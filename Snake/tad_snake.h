#ifndef TAD_SNAKE
#define TAD_SNAKE

/**
@TAD_SNAKE tad criado para simular as estruturas pilha e fila na relação com a snake
*/

#include "snake.h"

/**
@pushSnake (Snake* snk, int posX, int posY)
@brief insere um novo asterisco ao corpo da snake na direita (horizontal) ou em cima (vertical)
@param snk é a snake a ser modificada
@param posX é a posição x do novo asterisco
@param posY é a posição y do novo asterisco
@return 1 caso a inserção tenha sido bem-sucedida, 0 caso contrário
*/
int pushSnake (Snake** snk, int posX, int posY);

/**
@popSnake (Snake** snk)
@brief retira um asterisco do corpo da snake na direita (horizontal) ou em cima (vertical)
@param snk é a snake a ser modificada
@return 1 caso a remoção tenha sido bem-sucedida, 0 caso contrário
*/
int popSnake (Snake** snk);

/**
@dequeueSnake (Snake** snk)
@brief retira um asterisco do corpo da snake na esquerda (horizontal) ou em baixo (vertical)
@param snk é a snake a ser modificada
@return 1 caso a remoção tenha sido bem-sucedida, 0 caso contrário
*/
int dequeueSnake (Snake** snk);

#endif