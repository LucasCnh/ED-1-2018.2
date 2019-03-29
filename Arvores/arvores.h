#ifndef TAD_ARVORE
#define TAD_ARVORE


typedef struct _Node_ { //Nó que representará um dos filhos da árvore
    struct _Node_* esq; //Filho á esquerda do nó atual
    struct _Node_* dir; //Filho á direita do nó atual
    struct _Node_* head; //Pai do nó atual
    int d; //Dado do nó
}Node;

typedef struct _Tree_ { //Estrutura que guardará o início da árvore
    Node* raiz; //Início da árvore
}Tree;

/**
@criaArvore()
@brief Função que cria uma árvore vazia
@return Estrutura do tipo Tree (árvore) vazia
*/
Tree* criaArvore();

/**
@insereFolha(Tree* t, int v)
@brief Função que insere uma nova folha á árvore
@param t Estrutura do tipo Tree (árvore) a ser inserido o novo dado (folha)
@param v Dado á ser inserido em estrutura do tipo árvore como uma folha
@return 1 Caso a inserção tenha sido bem-sucedida, 0 caso contrário
*/
int insereFolha(Tree* t, int v);

void espelhaArvore (Tree* t);
void trocaEsqDir (Node* t);

/**
@printaArvore(Node* n)
@brief Função que printa uma estrutura de dados do tipo árvore
@param n Nó de onde se iniciará o print, serão printados recursivamente o próprio nó e a função será chamada novamente para seus filhos
*/
void printaArvore(Node* n);

/**
@removeElemento(Tree* t, int v)
@brief Função que remove um nó, com o valor dado por v, da árvore
@param t Estrutura de dados do tipo árvore de onde o nó será removido
@param v Valor dado pelo usuário que corresponde ao dado do nó requerido na remoção
@return 1 caso a remoção tenha sido bem-sucedida, 0 caso contrário
*/
int removeElemento(Tree* t, int v);

/**
@buscaNo (Node* n, int v)
@brief Função que busca recursivamente um elemento na árvore
@param n Nó de onde iniciará a busca
@param v Elemento a ser buscado na árvore
@return Node com o exato valor buscado, ou NULL caso o valor não tenha sido encontrado na árvore
*/
Node* buscaNo (Node* n, int v);


/**
@destroiNos(Node* n)
@brief Função que destroi recursivamente todos os nós a partir de um determinado elemento de uma árvore
@param n Node de onde se iniciará a destruição
*/
void destroiNos(Node* n);

/**
@destroiArvore(Tree** t)
@brief Função que destroi uma estrutura do tipo árvore desalocando da memória todos os seus membros assim como a própria
@param t Estrutura do tipo Tree a ser desalocada
@return 1 Caso a destruição tenha sido bem-sucedida, 0 caso contrário
*/
int destroiArvore(Tree** t);

#endif
