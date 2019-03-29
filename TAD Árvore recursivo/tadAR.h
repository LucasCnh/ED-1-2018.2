#ifndef TAD_Arvore_Recursivo
#define TAD_Arvore_Recursivo

typedef struct _Tree_ {
    struct _Tree_* esq;
    struct _Tree_* dir;
    struct _Tree_* pai;
    int dado;
}Tree;

Tree* criaArvore (int valor);
int insercao(Tree** t, int valor);

void preOrdem (Tree* t);
void emOrdem (Tree* t);
void posOrdem (Tree* t);

//Tree* busca (Tree* t, int valor);
Tree* maiorDireita (Tree** esq);
int remocao (Tree** t, int valor);
int destruirArvore (Tree** t);

#endif // TAD_Arvore_Recursivo

