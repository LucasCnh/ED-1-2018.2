
#ifndef TAD_FILA
#define TAD_FILA

/**
@TAD_FILA tad criado para realizar operacoes com a estrutura de dados fila
*/
typedef struct _Fila_ { //Estrutura do tipo Fila que fornece uma fila de matriculas
	int* matriculas; //Vetor que armazenará a fila de pessoas que irao se matricular
	int qtdMax; //Quantidade maxima de pessoas na fila
	int prim; //Posicao no vetor da primeira pessoa da fila
	int ult; //Posicao no vetor da ultima pessoa da fila
}Fila;

/**
@criaFila (int tamanho)
@brief função que cria a fila, alocando um vetor e uma estrutura do tipo Fila que a representará
@param tamanho representará a quantidade maxima de pessoas na fila
@return estrutura do tipo Fila com um vetor alocado que irá representar a fila
*/
Fila* criaFila (int tamanho);

/**
@enqueue (Fila* fila, int valor)
@brief função que insere uma nova pessoa na fila, tal pessoa ocupará a ultima posição da fila
@param fila estrutura de dados que representará a fila
@param valor variavel que representará a pessoa a ser inserida na fila
@return 1 caso a inserção tenha sido bem sucedida, 0 caso contrário
*/
int enqueue (Fila* fila, int valor);

/**
@dequeue (Fila* fila)
@brief "atende" uma pessoa da fila (a pessoa que se encontra na primeira posição da fila)
@param fila estrutura de dados que representará a fila
@return 1 caso a remoção tenha sido bem sucedida, 0 caso contrário
*/
int dequeue (Fila* fila);

/**
@empty (Fila* fila)
@brief função que checa se a fila está vazia
@param fila estrutura de dados que representará a fila
@return 1 caso a fila esteja vazia, 0 caso contrário
*/
int empty (Fila* fila);

/**
@printaFila (Fila** fila)
@brief função que imprime na tela o valor de cada pessoa presente na fila
@param fila é a fila a ser printada
*/
void printaFila (Fila* fila);

/**
@destroiFila (Fila** fila)
@brief função que destroi a fila desalocando todas os membros da estrutura do tipo Fila
@param fila estrutura do tipo fila a ser destruida
@return 1 caso a destruição tenha sido bem sucedida, 0 caso contrário
*/
int destroiFila (Fila** fila);

#endif