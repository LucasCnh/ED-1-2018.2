#ifndef TAD_Listas
#define TAD_Listas

/**
@TAD_Listas
@Tad formador de listas duplamente encadeadas como estruturas de dados
*/

typedef struct _Node_ { //Estrutura que define cada nó da lista
	struct _Node_* next; //Referência para o próximo nó da lista
	struct _Node_* prev; //Referência para o nó anterior da lista
	int dado; //Dado a ser guardado pelo nó
}Node; //Nó

typedef struct _Lista_Dupla_ { //Estrutura que define a lista
	Node* head; //Cabeça da lista (primeiro elemento da lista)
	Node* tail; //Rabo da lista (último elemento da lista)
}ListaDupla; //Lista

/**
@criaListaDupla ()
@brief função que criará uma lista duplamente encadeada
@return estrutura do tipo ListaDupla (duplamente encadeada)
*/
ListaDupla* criaListaDupla ();

/**
@insercaoListaDupla (ListaDupla* l, int dado)
@brief função que insere um valor (novo nó) no rabo da lista
@param l é a lista a receber o novo valor (nó)
@param dado é o valor a ser inserido na lista
@return 1 caso a inserção tenha sido bem-sucedida, 0 caso contrário
*/
int insercaoListaDupla (ListaDupla* l, int dado); //QUESTÃO 1

/**
@removeListaDupla (ListaDupla* l, int dado)
@brief função que remove dado valor (nó) da lista
@param l é a lista de onde a remoção será realizada
@param dado é o valor a ser removido da lista
@return 1, caso a remoção tenha sido bem-sucedida, 0 caso contrário
*/
int removeListaDupla (ListaDupla* l, int dado);

/**
@printaListaDupla (ListaDupla* l)
@brief função que printa os valores de uma lista dupla
@param l é a lista á ser printada
*/
void printaListaDupla (ListaDupla* l);

/**
@destroiListaDupla (ListaDupla** l)
@brief função que destruirá uma lista duplamente encadeada
@param l é a lista duplamente encadeada a ser destruída
@return 1 caso a destruição tenha sido bem-sucedida, 0 caso contrário
*/
int destroiListaDupla (ListaDupla** l); //QUESTÃO 3

#endif