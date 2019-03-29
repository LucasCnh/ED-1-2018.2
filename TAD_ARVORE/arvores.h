#ifndef TAD_ARVORE
#define TAD_ARVORE


typedef struct _Tree_ { //Estrutura que guardará o início da árvore
    struct _Tree_* esq; //Filho á esquerda do nó atual
    struct _Tree_* dir; //Filho á direita do nó atual
    struct _Tree_* head; //Pai do nó atual
    int d; //Dado do nó
}Tree;

/**
@criaArvore(Tree* t, int v)
@brief Função que cria uma árvore 
@param t Estrutura do tipo Tree (árvore) a ser inserido o novo dado (folha)
@param v Dado á ser inserido em estrutura do tipo árvore como uma folha
@return 1 Caso a inserção tenha sido bem-sucedida, 0 caso contrário
*/
int criaArvore(Tree* t, int v);

/**
@printaArvore(Tree* t)
@brief Função que printa uma estrutura de dados do tipo árvore
@param t Árvore de onde se iniciará o print, serão printados recursivamente o próprio nó e a função será chamada novamente para seus filhos
*/
void printaArvore(Tree* t);

/**
@removeElemento(Tree* t, int v)
@brief Função que remove um nó, com o valor dado por v, da árvore
@param t Estrutura de dados do tipo árvore de onde o nó será removido
@param v Valor dado pelo usuário que corresponde ao dado do nó requerido na remoção
@return 1 caso a remoção tenha sido bem-sucedida, 0 caso contrário
*/
int removeElemento(Tree* t, int v);

/**
@buscaNo (Tree* t, int v)
@brief Função que busca recursivamente um elemento na árvore
@param t Nó de onde iniciará a busca
@param v Elemento a ser buscado na árvore
@return Sub-árvore com raiz com o exato valor buscado, ou NULL caso o valor não tenha sido encontrado na árvore
*/
Tree* buscaNo (Tree* t, int v);

/**
@buscaMaiorEsq (Node* n, int v)
@brief Função que busca de forma recursiva o maior valor á esquerda do nó inicial
@param n Nó de onde iniciará a busca
@param v Maior valor (no início)
@return maior valor á esquerda de v ou o próprio v caso não fora encontrado nenhum menor que ele
*/
//int buscaMaiorEsq (Node* n, int v);

// void encontraFolhas (Node* n);

// void encontraNosDeNivel (Tree* t, int nivel);

// void encontraNivel (Node* n, int nivel, int contador);

// int buscaRepeticoes (Tree* t, int v);

// int achaQtdRepeticoes (Node* n, int v, int repeticoes);

// int arvoresIguais (Tree* t1, Tree* t2);

// int comparaArvores (Node* n, Node* n1);

/**
@destroiArvore(Tree** t)
@brief Função que destroi uma estrutura do tipo árvore desalocando da memória todos os seus membros assim como a própria
@param t Estrutura do tipo Tree a ser desalocada
@return 1 Caso a destruição tenha sido bem-sucedida, 0 caso contrário
*/
int destroiArvore(Tree** t);

#endif
