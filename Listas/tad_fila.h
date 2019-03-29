#ifndef TAD_FILA_LISTA
#define TAD_FILA_LISTA

#include "lista.h"

/**
@TAD_FILA_LISTA tad criado para utilizar uma lista encadeada como uma estrutura de dados do tipo fila
*/

/**
@FILA (int ultimo, int primeiro)
@brief fila será representada utilizando lista
@param ultimo o último da lista será a cabeça da lista
@param primeiro o primeiro da lista será o último nó da lista
*/

/**
@enqueue (Lista** f, int valor)
@brief função que adiciona um novo valor ao fim da fila
@param f é a fila a receber o valor
@param valor é o valor a ser inserido na fila
@return 1 caso a inserção tenha sido bem-sucedida, 0 caso contrário
*/
int enqueue (Lista** f, int valor);

/**
@dequeue (Lista** f)
@brief função que retira um valor do início da fila
@param f é a fila de onde o valor será retirado
@return 1 caso a remoção tenha sido bem-sucedida, 0 caso contrário
*/
int dequeue (Lista** f);

/**
@empty (Lista* f)
@brief função que checa se a fila está vazia ou não
@param f é a fila a ser analisada
@return 1 caso a fila esteja vazia, 0 caso contrário
*/
int empty (Lista* f);

#endif