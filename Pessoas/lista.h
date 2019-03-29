#ifndef TAD_LISTA
#define TAD_LISTA

typedef struct _Node_ { //Estrutura que representará um nó de uma lista
	struct _Node_* next; //Referencia para o próximo nó da lista
	int dado; //Dado a ser guardado pela lista
}Node;

typedef struct _Lista_ { //Estrutura que guardará a lista (referência para o primeiro nó)
	Node* head; //Cabeça da lista
}Lista;

/**
@criaPilha (void)
@brief cria uma nova lista que representará a estrutura de dado
@return estrutura do tipo Lista
*/
Lista* criaLista (void);

/**
@printaLista (Lista* lista)
@brief função que printa cada nó de uma lista
*/
void printaLista (Lista* lista);

/**
@destroiPilha (Lista** cab)
@brief função que destroi a lista
@param lista é a lista a ser destruída
@return 1, caso a função tenha sido bem sucedida, 0 caso contrário
*/
int destroiLista (Lista** lista);

#endif