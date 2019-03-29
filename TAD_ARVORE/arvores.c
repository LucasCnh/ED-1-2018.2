#include <stdio.h>
#include <stdlib.h>
#include "arvores.h"

int criaArvore(Tree** t, int v){ //Função que cria uma árvore vazia

    if (t == NULL){ 
        t = (Tree*) malloc(sizeof(Tree));

        if (t == NULL) return 0;

        t -> esq = NULL;
        t -> dir = NULL;
        t -> head = NULL;
        t -> d = v;

        return 1;
    }else{
        if (v > t -> d){
            if (criaArvore(t -> dir, v)){
                t -> dir -> head = t;
            }
        }else{
            if (criaArvore(t -> esq, v)){
                t -> esq -> head = t;
            }
        }
    }

    return 1;
    
}

void printaArvore(Tree* t){ //Função que printa de forma recursiva uma estrutura de dados do tipo árvore

    if (t == NULL){ //Caso o nó seja nulo, a função não faz nada
        return;
    }

    printaArvore(t -> esq); //A função é chamada novamente para o filho á esquerda
    printf("%i ", t -> d); //O valor do nó atual é printado
    printaArvore(t -> dir); //A função é chamada novamente para o filho á direita

    return;
}

Tree* buscaNo (Tree* t, int v){ //Função que busca recursivamente um elemento na árvore

    if (t == NULL) return NULL;

    if (t -> d == v) return t;

    if (v > t -> d){
        return buscaNo(t -> dir, v);
    }else{
        return buscaNo(t -> esq, v);
    }
}

int removeElemento(Tree* t, int v){ //Função que remove um elemento da árvore colocando em sua posição um elemento correspondente

    if (t == NULL) return 0;

    Tree* n = buscaNo(t, v); //Buscando o nó na árvore

    if (n == NULL) return 0; //Se o nó não for encontrado, a função retorna 0

    Tree* p;

    if (n -> head != NULL){ //Se o nó encontrado não for a raíz
        if (n -> d > n -> head -> d){ //Se o nó encontrado estiver á direita do seu anterior
            n -> head -> dir = n -> esq; //O nó á direita de seu anterior passa a ser o nó á esquerda do que será removido
            if (n -> head -> dir != NULL){ //Caso o novo nó á direita exista
                n -> head -> dir -> head = n -> head; //A cabeça do novo nó á direita será igual á cabeça do nó encontrado
            }
        }else{ //Se o nó encontrado estiver á esquerda do seu anterior...
            n -> head -> esq = n -> esq; //O nó á esquerda de seu anterior passa a ser o nó á esquerda do que será removido
            if (n -> head -> esq != NULL){ //Caso o novo nó á esquerda exista
                n -> head -> esq -> head = n -> head; //A cabeça do novo nó á esquerda será igual á cabeça do nó encontrado
            }
        }

        if (n -> dir != NULL){ //Caso o nó encontrado tenha filhos á direita
            if (n -> esq != NULL){ //Se o nó á esquerda de n (que será o próximo posterior ao anterior) existir
                p = n -> esq;
                while (p -> dir != NULL){ //Enquanto p não encontrar o último nó á direita da sub-árvore do nó á esquerda de n
                    p = p -> dir; //p segue buscando
                }
                p -> dir = n -> dir; //A sub-árvore á direita de n será posicionada á direita de p
                p -> dir -> head = p; //O nó anterior ao novo colocado será o primeiro nó da sub-árvore á direita de n
            }else{ //Caso o nó á esquerda não existir
                if (n -> d > n -> head -> d){ //Caso o valor do nó a ser removido seja maior que o valor do seu nó anterior
                    n -> head -> dir = n -> dir; //O nó á direita do anterior passa a ser o nó á direita do nó a ser removido
                    n -> head -> dir -> head = n -> head; //A cabeça do novo nó á direita passa a ser o anterior ao nó a ser removido
                }else{
                    n -> head -> esq = n -> esq; //O nó á esquerda do anterior passa a ser o nó á direita do nó a ser removido
                    n -> head -> esq -> head = n -> head; //A cabeça do novo nó á esquerda passa a ser o anterior ao nó a ser removido
                }
            }
        }

    }else{
        if (n -> esq != NULL){ //Se o nó á esquerda existir
            if (n -> dir != NULL){ //Se o nó á direita também existir
                p = n -> esq; //O nó mais á direita do primeiro nó á esquerda é buscado
                while (p -> dir != NULL){
                    p = p -> dir;
                }

                //A sub-árvore á direita da raíz é inserida á direita da folha mais á direita do primeiro nó á esquerda da raiz
                p -> dir = n -> dir;
                p -> dir -> head = p;
                n -> esq -> head = NULL; //A raiz não referencia nós anteriores
            }
        }else if (n -> dir != NULL){ //Caso o nó da direita exista (e o da esquerda não)
            n -> dir -> head = NULL; //A raiz não referencia nós anteriores
        }else{ //Caso o nó encontrado seja o único da árvore
            t = NULL; //A árvore passa a ficar vazia
        }
    }

    free(n); //O nó (finalmente) é desalocado da memória =3
    return 1; //A função retorna 1, simbolizando que a remoção foi um sucesso
}

// void encontraFolhas (Node* n){ //Função que encontra todas as folhas de uma árvore

//     if (n == NULL) return;

//     if (n -> esq == NULL && n -> dir == NULL){
//         printf("%i ", n -> d);
//     }

//     encontraFolhas(n -> esq);
//     encontraFolhas(n -> dir);
// }

// void encontraNosDeNivel (Tree* t, int nivel){

//     if (t == NULL) return;

//     if (nivel == 0){
//         printf("%i ", t -> raiz -> d);
//     }
//     else{
//         encontraNivel(t -> raiz -> esq, nivel, 1);
//         encontraNivel(t -> raiz -> dir, nivel, 1);
//     }
// }

// void encontraNivel (Node* n, int nivel, int contador){

//     if (n == NULL) return;

//     if (nivel == contador){
//         printf("%i ", n -> d);
//         return;
//     }

//     contador++;

//     encontraNivel(n -> esq, nivel, contador);
//     encontraNivel(n -> dir, nivel, contador);

//     return;
// }

// int buscaRepeticoes (Tree* t, int v){ //Função que busca a qtd de repetições de dado valor em uma árvore

//     if (t == NULL) return 0;

//     int repeticoes = 0;

//     if (t -> raiz -> d == v) repeticoes++;

//     repeticoes = achaQtdRepeticoes(t -> raiz -> esq, v, repeticoes);
//     repeticoes = achaQtdRepeticoes(t -> raiz -> dir, v, repeticoes);

//     return repeticoes;
// }

// int achaQtdRepeticoes (Node* n, int v, int repeticoes){

//     if (n == NULL) return repeticoes;

//     repeticoes = achaQtdRepeticoes(n -> esq, v, repeticoes);
//     repeticoes = achaQtdRepeticoes(n -> dir, v, repeticoes);

//     if (v == n -> d) repeticoes++;

//     return repeticoes;
// }

// int arvoresIguais (Tree* t1, Tree* t2){

//     if (t1 == NULL && t2 == NULL) return 1;

//     if (t1 == NULL || t2 == NULL) return 0;

//     if(!(comparaArvores(t1 -> raiz -> esq, t2 -> raiz -> esq))){
//         return 0;
//     }

//     if (!(comparaArvores(t1 -> raiz -> dir, t2 -> raiz -> dir))){
//         return 0;
//     }

//     if (t1 -> raiz -> d == t2 -> raiz -> d) return 1;

//     return 0;
// }

// int comparaArvores (Node* n, Node* n1){

//     if (n == NULL && n1 == NULL) {
//         return 1;
//     }else if (n == NULL || n1 == NULL) {
//         return 0;
//     }

//     if (!(comparaArvores(n -> esq, n1 -> esq))){
//         return 0;
//     }

//     if (!(comparaArvores(n -> dir, n1 -> dir))){
//         return 0;
//     }

//     if (n -> d == n1 -> d) return 1;

//     return 0;
// }


// int buscaMaiorEsq (Node* n, int v){ //Função que busca o maior valor á esquerda do nó inicial

//     if (n == NULL){
//         return v;
//     }

//     if (n -> d > v){
//         v = n -> d;
//     }

//     v = buscaMaiorEsq(n -> esq, v);

//     return v;
// }

int destroiArvore(Tree** t){ //Função que destroi uma estrutura do tipo árvore desalocando da memória todos os seus membros assim como a própria

    if (*t == NULL) return 0; //Caso a árvore já esteja destruida

    Tree* n = *t;

    destroiArvore(&(n -> esq));
    destroiArvore(&(n -> dir));

    if ((*t) -> head == NULL){
        free(*t); //Libera da memória a estrutura do tipo árvore
        *t = NULL;
        return 1;
    }

    free(n);

    return 1;
}
