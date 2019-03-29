#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad_arvore.h"

Tree* criaArvore (void* valor, Compara c, Desaloca d, Printar p){

    Tree* t = (Tree*) malloc(sizeof(Tree));

    if (t != NULL){
        t -> esq = t -> dir = NULL;
        t -> dado = valor;
        t -> pai = NULL;
        t -> comp = c;
        t -> des = d;
        t -> prin = p;
    }

    return t;
}

int insercao(Tree** t, void* valor){

    if (*t == NULL){
        *t = (Tree*) malloc(sizeof(Tree));
        if (*t == NULL) return 0;

        (*t) -> esq = (*t) -> dir = NULL;
        (*t) -> dado = valor;
        (*t) -> pai = NULL;

        return 1;
    }
    
    if (((*t) -> comp(valor, (*t) -> dado)) == 1){ //Comp retornará 1 caso o valor seja maior que o dado
        if (insercao(&(*t) -> dir, valor)){
            (*t) -> dir -> pai = *t;
            (*t) -> dir -> comp = (*t) -> comp;
            (*t) -> dir -> des = (*t) -> des;
            (*t) -> dir -> prin = (*t) -> prin;
        }
    }
    else{
        if (insercao(&(*t) -> esq, valor)){
            (*t) -> esq -> pai = *t;
            (*t) -> esq -> comp = (*t) -> comp;
            (*t) -> esq -> des = (*t) -> des;
            (*t) -> esq -> prin = (*t) -> prin;
        }
    }

    return 1;
}

void preOrdem(Tree* t){

    if (t == NULL) return;

    t -> prin(t -> dado);
    preOrdem(t -> esq);
    preOrdem(t -> dir);

    return;
}

void emOrdem (Tree* t){

    if (t == NULL) return;

    emOrdem(t -> esq);
    t -> prin(t -> dado);
    emOrdem(t -> dir);

    return;
}

void posOrdem(Tree* t){

    if (t == NULL) return;

    posOrdem(t -> esq);
    posOrdem(t -> dir);
    t -> prin(t -> dado);

    return;
}

Tree* busca (Tree* t, void* valor){

    if (t == NULL){
        return NULL;
    }

    if ((t -> comp(t -> dado, valor)) == 0){
        return t;
    }

    Tree* aux = NULL;

    if ((aux = (busca(t -> esq, valor))) != NULL){
        return aux;
    }

    if ((aux = (busca(t -> dir, valor))) != NULL){
        return aux;
    }

    return NULL;
}

Tree* maiorDireita (Tree** esq){

    if (*esq == NULL){
        return NULL;
    }

    if ((*esq) -> dir != NULL){
        return maiorDireita (&(*esq) -> dir);
    }
    else{

        Tree* aux = *esq;

        if ((*esq) -> esq != NULL){
            (*esq) -> esq -> pai = (*esq) -> pai;
            *esq = (*esq) -> esq;
        }else{
            *esq = NULL;
        }

        return aux;
    }
}

int remocao (Tree** t, void* valor){

    if (*t == NULL) return 0;

    if (((*t) -> comp((*t) -> dado, valor)) == 0){

        if (((*t) -> dir == NULL) && ((*t) -> esq == NULL)){
            (*t) -> des((*t) -> dado);
            free(*t);
            *t = NULL;
            return 1;
        }
        
        Tree* aux = maiorDireita(&(*t) -> esq);

        if (aux == NULL){

            aux = (*t) -> dir;
            aux -> pai = (*t) -> pai;
            (*t) -> des((*t) -> dado);
            free(*t);
            (*t) = aux;
            
        }else{

            aux -> pai = (*t) -> pai;
            aux -> dir = (*t) -> dir;
            aux -> esq = (*t) -> esq;
            (*t) -> des((*t) -> dado);
            free(*t);
            (*t) = aux;
        }

        return 1;
    }

    if (remocao(&(*t) -> esq, valor)){
        return 1;
    }

    if (remocao(&(*t) -> dir, valor)){
        return 1;
    }
    
    return 0;    
}


int destruirArvore (Tree** t){

    if (*t == NULL) return 0;

    Tree* esq = (*t) -> esq;
    Tree* dir = (*t) -> dir;

    if (esq != NULL){
        destruirArvore(&esq);
    }

    if (dir != NULL){
        destruirArvore(&dir);
    }

    (*t) -> des((*t) -> dado);
    free(*t);
    *t = NULL;

    return 1;
}

//FUNÇÕES VOID*
int comparaNomes (void* a, void* b){

    if (a == NULL || b == NULL) return -1;

    char* N1 = (char*) a;
    char* N2 = (char*) b;

    if ((strcmp(N1, N2)) > 0) return 1;
    if ((strcmp(N1, N2)) < 0) return -1;

    return 0;
}

void desalocaNomes (void* a){

    if (a == NULL) return;

    char* des = (char*) a;
    free(des);

    return;
}

void printaNomes (void* a){

    if (a == NULL) return;

    char* p = (char*) a;

    printf(" %s\n", p);

    return;
}

void printaMatriculas (void* a){

    if (a == NULL) return;

    char* p = (char*) a;
    printf("Matricula do colaborador: %s\n", p);
}

void printaDatas (void* a){

    if (a == NULL) return;

    char* p = (char*) a;
    printf(" %s\n", p);

    return;
}
//