#ifndef SNAKE
#define SNAKE

/**
@snake.h arquivo onde se encontram funções que realizam as mecânicas necessárias para o andamento do jogo
*/

typedef struct _Corpo_ { //Estrutura que armazenará as características da snake
	int posX; //Posição x do asterisco da cobra
	int posY; //Posição y do cada asterisco da cobra
	struct _Corpo_* next; //Próximo asterisco do corpo da cobra
}Corpo;

typedef struct _Snake_ {
	Corpo* head; //Cabeça da cobra
	int  tam; //Tamanho da cobra
	int orientacao; //Orientacao da cobra (horizontal ou vertical)
}Snake;

/**
@criaSnake (int tamanho)
@brief função que cria uma nova snake
@param tamanho é o tamanho do plano á ser inserido á snake
@return estrutura do tipo Snake que representará a snake
*/
Snake* criaSnake (int tamanho);

/**
@movimentaSnake (Snake* snk, int** plano, int* pontuacao, char input)
@brief movimenta a snake na direção desejada pelo usuário (input)
@param snk é a snake a ser deslocada
@param plano é o plano utilizado para representar o jogo que irá ser atualizado
@return 1 caso a snake pôde se movimentar, 0 caso tenha batido na parede
*/
int movimentaSnake (Snake** snk, int** plano, int* pontuacao, char input);

/**
@aumentaSnake (Snake* snk, int** plano)
@brief insere um novo asterisco á snake
@param snk é a snake a ser modificada
@param plano é o plano utilizado para representar o jogo que irá ser atualizado
@return 1 caso a snake tenha aumentado com sucesso, 0 caso a mesma esteja cheia
*/
int aumentaSnake (Snake** snk, int** plano);

/**
@destroiSnake (Snake** snk)
@brief função que destroi a snake atual
@param snk é a snake a ser destruída
@return 1 caso a destruição tenha sido bem-sucedida, 0 caso contrário
*/
int destroiSnake (Snake** snk);

#endif