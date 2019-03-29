#include <stdio.h>
#include <stdlib.h>
#include "arvores.h"
#include "atividade.h"

//QUESTÃO 1
void encontraFolhas (Node* n){ //Função que encontra todas as folhas de uma árvore

    if (n == NULL) return;

    if (n -> esq == NULL && n -> dir == NULL){
        printf("%i ", n -> d);
    }

    encontraFolhas(n -> esq);
    encontraFolhas(n -> dir);
}
//

//QUESTÃO 2
void encontraNosDeNivel (Tree* t, int nivel){

    if (t == NULL) return;

    if (nivel == 0){
        printf("%i ", t -> raiz -> d);
    }
    else{
        encontraNivel(t -> raiz -> esq, nivel, 1);
        encontraNivel(t -> raiz -> dir, nivel, 1);
    }
}

void encontraNivel (Node* n, int nivel, int contador){

    if (n == NULL) return;

    if (nivel == contador){
        printf("%i ", n -> d);
        return;
    }

    contador++;

    encontraNivel(n -> esq, nivel, contador);
    encontraNivel(n -> dir, nivel, contador);

    return;
}
//

//QUESTÃO 3
int comparaArvores (Node* n, Node* n1){ //1 significa que as árvores são iguais, 0 siginifica diferentes

    if (n == NULL && n1 == NULL) {
        return 1;
    }else if (n == NULL || n1 == NULL) {
        return 0;
    }

    if (!(comparaArvores(n -> esq, n1 -> esq))){
        return 0;
    }

    if (!(comparaArvores(n -> dir, n1 -> dir))){
        return 0;
    }

    if (n -> d == n1 -> d) return 1;

    return 0;
}
//

//QUESTÃO 4
int buscaRepeticoes (Tree* t, int v){ //Função que busca a qtd de repetições de dado valor em uma árvore

    if (t == NULL) return 0;

    int repeticoes = 0;

    if (t -> raiz -> d == v) repeticoes++;

    repeticoes = achaQtdRepeticoes(t -> raiz -> esq, v, repeticoes);
    repeticoes = achaQtdRepeticoes(t -> raiz -> dir, v, repeticoes);

    return repeticoes;
}

int achaQtdRepeticoes (Node* n, int v, int repeticoes){

    if (n == NULL) return repeticoes;

    repeticoes = achaQtdRepeticoes(n -> esq, v, repeticoes);
    repeticoes = achaQtdRepeticoes(n -> dir, v, repeticoes);

    if (v == n -> d) repeticoes++;

    return repeticoes;
}
//