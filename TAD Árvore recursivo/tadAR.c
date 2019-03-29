#include <stdio.h>
#include <stdlib.h>
#include "tadAR.h"

Tree* criaArvore(int valor){

    Tree* t = (Tree*) malloc(sizeof(Tree));

    if (t != NULL){
        t -> esq = t -> dir = NULL;
        t -> dado = valor;
        t -> pai = NULL;
    }

    return t;
}

int insercao(Tree** t, int valor){

    if (*t == NULL){
        *t = (Tree*) malloc(sizeof(Tree));
        if (*t == NULL) return 0;

        (*t) -> esq = (*t) -> dir = NULL;
        (*t) -> dado = valor;
        (*t) -> pai = NULL;

        return 1;
    }
    else if (valor > ((*t) -> dado)){
        if (insercao(&(*t) -> dir, valor)){
            (*t) -> dir -> pai = *t;
        }
    }
    else{
        if (insercao(&(*t) -> esq, valor)){
            (*t) -> esq -> pai = *t;
        }
    }

    return 1;
}

void preOrdem(Tree* t){

    if (t == NULL) return;

    printf("%i ", t -> dado);
    preOrdem(t -> esq);
    preOrdem(t -> dir);

    return;
}

void emOrdem (Tree* t){

    if (t == NULL) return;

    emOrdem(t -> esq);
    printf("%i ", t -> dado);
    emOrdem(t -> dir);

    return;
}

void posOrdem(Tree* t){

    if (t == NULL) return;

    posOrdem(t -> esq);
    posOrdem(t -> dir);
    printf("%i ", t -> dado);

    return;
}

// Tree* busca (Tree* t, int valor){

//     if (t == NULL){
//         return NULL;
//     }

//     if (t -> dado == valor){
//         return t;
//     }

//     Tree* t = NULL;

//     if ((t = (busca(t -> esq, valor))) != NULL){
//         return t;
//     }

//     if ((t = (busca(t -> dir, valor))) != NULL){
//         return t;
//     }

//     return NULL;
// }

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

int remocao (Tree** t, int valor){

    if (*t == NULL) return 0;

    if ((*t) -> dado == valor){

        if (((*t) -> dir == NULL) && ((*t) -> esq == NULL)){
            free(*t);
            *t = NULL;
            return 1;
        }
        
        Tree* aux = maiorDireita(&(*t) -> esq);

        if (aux == NULL){

            aux = (*t) -> dir;
            aux -> pai = (*t) -> pai;
            free(*t);
            (*t) = aux;
            
        }else{

            aux -> pai = (*t) -> pai;
            aux -> dir = (*t) -> dir;
            aux -> esq = (*t) -> esq;
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

    free(*t);
    *t = NULL;

    return 1;
}
