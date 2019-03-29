#include <stdio.h>
#include <stdlib.h>
#include "arvores.h"

Tree* criaArvore(){ //Função que cria uma árvore vazia
    Tree* t = (Tree*) malloc(sizeof(Tree));

    if (t != NULL){
        t -> raiz = NULL;
    }

    return t;
}

int insereFolha(Tree* t, int v){ //Função que criará e inserirá uma nova folha á árvore

    if (t == NULL) return 0;

    Node* n = (Node*) malloc(sizeof(Node));

    if (n != NULL){
        n -> esq = NULL;
        n -> dir = NULL;
        n -> head = NULL;
        n -> d = v;
    }else{
        return 0;
    }

    if (t -> raiz == NULL){ //Caso a árvore esteja vazia, o primeiro nó será n
        t -> raiz = n;
        return 1;
    }

    Node* p = t -> raiz; //Ponteiro que percorrerá a árvore até chegar ás folhas

    while (p != NULL){
        n -> head = p;

        if (p -> d > v){
            p = p -> esq;
        }else{
            p = p -> dir;
        }
    }

    if (n -> head -> d > v){
        n -> head -> esq = n;
    }else{
        n -> head -> dir = n;
    }

    return 1;
}

void printaArvore(Node* n){ //Função que printa de forma recursiva uma estrutura de dados do tipo árvore

    if (n == NULL){ //Caso o nó seja nulo, a função não faz nada
        return;
    }

    printaArvore(n -> esq); //A função é chamada novamente para o filho á esquerda
    printf("%i ", n -> d); //O valor do nó atual é printado
    printaArvore(n -> dir); //A função é chamada novamente para o filho á direita

    return;
}

int removeElemento(Tree* t, int v){ //Função que remove um elemento da árvore colocando em sua posição um elemento correspondente

    if (t == NULL || t -> raiz == NULL) return 0;

    Node* n = buscaNo(t -> raiz, v); //Buscando o nó na árvore

    if (n == NULL) return 0; //Se o nó não for encontrado, a função retorna 0

    Node* p;

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
                t -> raiz = n -> esq; //A raiz da árvore passa á ser o primeiro nó á esquerda
                n -> esq -> head = NULL; //A raiz não referencia nós anteriores
            }
        }else if (n -> dir != NULL){ //Caso o nó da direita exista (e o da esquerda não)
            t -> raiz = n -> dir; //A raiz passa a ser o primeiro nó á direita
            n -> dir -> head = NULL; //A raiz não referencia nós anteriores
        }else{ //Caso o nó encontrado seja o único da árvore
            t -> raiz = NULL; //A árvore passa a ficar vazia
        }
    }

    free(n); //O nó (finalmente) é desalocado da memória =3
    return 1; //A função retorna 1, simbolizando que a remoção foi um sucesso
}

Node* buscaNo (Node* n, int v){ //Função que busca recursivamente um elemento na árvore

    if (n == NULL) return NULL;

    if (n -> d == v) return n;

    if (v > n -> d){
        return buscaNo(n -> dir, v);
    }else{
        return buscaNo(n -> esq, v);
    }
}

void destroiNos(Node* n){ //Função que destroi recursivamente todos os nós a partir de um determinado elemento de uma árvore

    if (n == NULL){ //Se o nó atual for NULL a função não faz nada
        return;
    }

    destroiNos(n -> esq);
    destroiNos(n -> dir);

    free(n);

    return;
}


int destroiArvore(Tree** t){ //Função que destroi uma estrutura do tipo árvore desalocando da memória todos os seus membros assim como a própria

    if (*t == NULL) return 0; //Caso a árvore já esteja destruida

    destroiNos((*t) -> raiz); //Destroi todos os nós a partir da raiz
    free(*t); //Libera da memória a estrutura do tipo árvore
    *t = NULL;

    return 1;
}
