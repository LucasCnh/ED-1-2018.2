#ifndef TAD_Arvore
#define TAD_Arvore

typedef struct _Node_ {
	struct _Node_* esq;
	struct _Node_* dir;
	int dado;
}Node;

Node* criaArvore (int dado);
int insercao (Node** t, int dado);

Node* maiorDireita (Node** esq);
int remocao (Node** t, int dado);

void preOrdem (Node* t);
void emOrdem (Node* t);
void posOrdem (Node* t);

int destroi (Node** t);

#endif