
#ifndef TAD_Pilha
#define TAD_Pilha

/**
@TAD_Pilha tad criado para criar e manipular uma estrutura de dados do tipo pilha
*/
typedef struct _Pilha_ { //Estrutura de dado pilha
	int* valores; //Valores da pilha
	int topo; //Topo da pilha
	int qtdMax; //Quantidade maxima da pilha (tamanho da pilha)
}Pilha;

/**
@criaPilha (int tamanho)
@brief função que cria uma nova pilha (aloca)
@param tamanho é o tamanho da pilha/quantidade maxima de valores possíveis na pilha
@return estrutura do tipo Pilha ou NULL caso alguma alocação venha a fracassar
*/
Pilha* criaPilha (int tamanho);

/**
@push(Pilha* pilha, int valor)
@brief insere um novo valor ao topo da pilha
@param pilha é a pilha a ser usada na inserção
@param valor é o valor a ser inserido na pilha
@return 1 caso a inserção tenha sido bem sucedida, 0 caso contrário
*/
int push (Pilha* pilha, int valor);

/**
@printaPilha (Pilha* pilha)
@brief printa a pilha atual do fim ao topo
@param pilha é a pilha a ser printada
*/
void printaPilha (Pilha* pilha);

/**
@pop(Pilha* pilha)
@brief remove um valor do topo da pilha
@param pilha é a pilha a ser usada na remoção
@return o valor do topo ou -1 caso a pilha esteja vazia
*/
int pop (Pilha* pilha);

/**
@destroiPilha (Pilha** pilha)
@brief destroi a pilha
@param pilha é a pilha a ser destruida
@return 1 caso a destruição tenha sido bem sucedida, 0 caso contrário
*/
int destroiPilha (Pilha** pilha);

#endif