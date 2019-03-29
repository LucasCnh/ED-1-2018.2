#ifndef TAD_PILHA_LISTA
#define TAD_PILHA_LISTA

#include "lista.h"

/**
@TAD_PILHA_LISTA tad criado para utilizar uma lista encadeada como uma estrutura de dados do tipo pilha
*/

/**
@PILHA (int topo)
@brief pilha será representada utilizando lista
@param topo da pilha será a cabeça da lista
*/

/**
@push (Lista** p, int valor)
@brief adiciona um novo valor á pilha
@param p é a pilha a ser inserido o valor
@param valor é o novo valor do topo da cabeça
@return 1 caso o push tenha sido bem sucedido, 0 caso contrário
*/
int push (Lista** p, int valor);

/**
@pushOrdenado (Lista** p, int valor)
@brief adiciona um novo valor á pilha, mantendo a mesma ordenada (o menor valor no topo)
@param p é a pilha a ser inserido o valor
@param valor é o novo valor presente na pilha
@return 1 caso o push tenha sido bem sucedido, 0 caso contrário
*/
//int pushOrdenado (Lista** p, int valor);

/**
@pop (Lista** p)
@brief retira o valor do topo da pilha
@param p é a pilha aonde o topo será removido
@return 1 caso a remoção tenha sido bem sucedida, 0 caso contrário
*/
int pop (Lista** p);

#endif