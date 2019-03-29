#include <stdio.h>
#include <stdlib.h>
#include "tad_arvore.h"
#include "atividade.h"

//QUESTÃO 1
int arvoreCheiaOrNot (Node* t){

    if (t == NULL) return 0;

    if (t -> esq == NULL && t -> dir == NULL) return 1;

    if (t -> esq == NULL || t -> dir == NULL) return 0;

    if ((arvoreCheiaOrNot(t -> esq)) && (arvoreCheiaOrNot(t -> dir))) return 1;

    return 0;
}
//

//QUESTÃO 2 ESTÁ EM FORMA DE FOTO

//QUESTÃO 3
int numNodesDaArvore (Node* t){

    if (t == NULL) return 0;

    int contador = 0;

    contador = contaNos(t -> esq, contador);
    contador = contaNos(t -> dir, contador);

    contador++;

    return contador;

}

int contaNos (Node* t, int contador){

    if (t == NULL) return contador;

    contador = contaNos(t -> esq, contador);
    contador = contaNos(t -> dir, contador);

    contador++;

    return contador;
}
//

//QUESTÃO 4
void espelhaArvore (Node* t){

    if (t == NULL) return;

    Node* aux = t -> esq;

    espelhaArvore(t -> esq);
    espelhaArvore(t -> dir);

    t -> esq = t -> dir;
    t -> dir = aux;

    return;
}
//
