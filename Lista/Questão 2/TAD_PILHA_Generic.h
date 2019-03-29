
#ifndef TAD_Pilha_Generic
#define TAD_Pilha_Generic

/**
@TAD_Pilha tad criado para criar e manipular uma estrutura de dados (genéricos) do tipo pilha 
*/

typedef void (*Printar) (void* a); //Função genérica para printar valores void*
typedef void (*Desalocar) (void* a); //Função genérica para desalocar valores void*

typedef struct _Pilha_Generic_ { //Estrutura de dado pilha genérica
	void** valores; //Valores void* da pilha
	int topo; //Topo da pilha
	int qtdMax; //Quantidade maxima da pilha (tamanho da pilha)
	Printar prin;
	Desalocar des;
}PilhaG;

/**
@criaPilhaG (int tamanho, Printar p, Desalocar d)
@brief função que cria uma nova pilha (aloca)
@param tamanho é o tamanho da pilha/quantidade maxima de valores possíveis na pilha
@param p função genérica para printar valores void*
@param d função genérica para desalocar valores void*
@return estrutura do tipo Pilha ou NULL caso alguma alocação venha a fracassar
*/
PilhaG* criaPilhaG (int tamanho, Printar p, Desalocar d);

/**
@push(Pilha* pilha, int valor)
@brief insere um novo valor ao topo da pilha
@param pilha é a pilha a ser usada na inserção
@param valor é o valor a ser inserido na pilha
@return 1 caso a inserção tenha sido bem sucedida, 0 caso contrário
*/
int pushG (PilhaG* pilha, void* valor);

/**
@printaPilha (Pilha* pilha)
@brief printa a pilha atual do fim ao topo
@param pilha é a pilha a ser printada
*/
void printaPilhaG (PilhaG* pilha);

/**
@pop(Pilha* pilha)
@brief remove um valor do topo da pilha
@param pilha é a pilha a ser usada na remoção
@return o valor do topo ou -1 caso a pilha esteja vazia
*/
void* popG (PilhaG* pilha);

/**
@destroiPilha (Pilha** pilha)
@brief destroi a pilha
@param pilha é a pilha a ser destruida
@return 1 caso a destruição tenha sido bem sucedida, 0 caso contrário
*/
int destroiPilhaG (PilhaG** pilha);

#endif