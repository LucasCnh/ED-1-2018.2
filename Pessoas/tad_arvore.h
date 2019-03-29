#ifndef TAD_Arvore_Recursivo
#define TAD_Arvore_Recursivo

typedef int (*Compara) (void* a, void* b); //Funcao generica que compara dois valores genericos
typedef void (*Desaloca) (void* a); //Funcao generica que desaloca da memoria tipos void
typedef void (*Printar) (void* a); //Funcao generica que printa tipos de dados genericos

typedef struct _Tree_ {
    struct _Tree_* esq;
    struct _Tree_* dir;
    struct _Tree_* pai;
    void* dado;
    Compara comp;
    Desaloca des;
    Printar prin;
}Tree;

Tree* criaArvore (void* valor, Compara c, Desaloca d, Printar p);
int insercao(Tree** t, void* valor);

void preOrdem (Tree* t);
void emOrdem (Tree* t);
void posOrdem (Tree* t);

Tree* busca (Tree* t, void* valor);
Tree* maiorDireita (Tree** esq);
int remocao (Tree** t, void* valor);
int destruirArvore (Tree** t);

//FUNÇÕES VOID*
int comparaNomes (void* a, void* b);
void desalocaNomes (void* a);
void printaNomes (void* a);
void printaMatriculas (void* a);
void printaDatas (void* a);
//

#endif // TAD_Arvore_Recursivo

