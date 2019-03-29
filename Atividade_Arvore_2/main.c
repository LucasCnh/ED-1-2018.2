#include <stdio.h>
#include "tad_arvore.h"
#include "atividade.h"

int main(){

    Tree* t = criaArvore();

    insereFolha(t, 7);
    insereFolha(t, 5);
    insereFolha(t, 9);
    insereFolha(t, 3);
    insereFolha(t, 6);
    insereFolha(t, 8);
    insereFolha(t, 10);

    printf("\n\n%i\n\n", numNodesDaArvore(t -> raiz));

    removeElemento(t, 3);

    printf("\n\n%i\n\n", numNodesDaArvore(t -> raiz));
    printf("\n\n");
    printaArvore(t -> raiz);

    printf("\n\n%i\n", arvoreCheiaOrNot(t -> raiz));

    espelhaArvore(t -> raiz);
    printaArvore(t -> raiz);

    destroiArvore(&t);

    return 0;
}
