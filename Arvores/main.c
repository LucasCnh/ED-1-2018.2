#include <stdio.h>
#include "arvores.h"
#include "atividade.h"

int main(){

    Tree* t = criaArvore();

    printf("%i", insereFolha(t, 7));
    printf("%i", insereFolha(t, 5));
    printf("%i", insereFolha(t, 3));
    printf("%i", insereFolha(t, 6));
    printf("%i", insereFolha(t, 9));
    printf("%i", insereFolha(t, 8));
    printf("%i", insereFolha(t, 10));
    //printf("%i\n", insereFolha(t, 11));
    //printf("%i\n", insereFolha(t, 18));
    //printf("%i\n", insereFolha(t, 25));
    //printf("%i\n", insereFolha(t, 22));
    //printf("%i\n", insereFolha(t, 28));
    //printf("%i\n", insereFolha(t, 35));
    //printf("%i\n", insereFolha(t, 32));
    //printf("%i\n", insereFolha(t, 33));
    //printf("%i\n", insereFolha(t, 36));

    Tree* t2 = criaArvore();

    printf("%i", insereFolha(t2, 20));
    printf("%i", insereFolha(t2, 10));
    printf("%i", insereFolha(t2, 30));
    printf("%i", insereFolha(t2, 5));
    printf("%i", insereFolha(t2, 7));
    printf("%i", insereFolha(t2, 3));
    printf("%i", insereFolha(t2, 15));
    printf("%i\n", insereFolha(t2, 11));
    printf("%i\n", insereFolha(t2, 18));
    printf("%i\n", insereFolha(t2, 25));
    printf("%i\n", insereFolha(t2, 22));
    printf("%i\n", insereFolha(t2, 28));
    printf("%i\n", insereFolha(t2, 35));
    printf("%i\n", insereFolha(t2, 32));
    printf("%i\n", insereFolha(t2, 33));
    printf("%i\n", insereFolha(t2, 36));

    //espelhaArvore(t);
    //printf("\n\n\n%i\n\n\n", comparaArvores(t -> raiz, t2 -> raiz));
    //encontraNosDeNivel(t, 2);
    printf("\n\n");
    removeElemento(t, 7);
    removeElemento(t, 8);
    printaArvore(t -> raiz);
    printf("\n\n");
    encontraFolhas(t -> raiz);
    printf("\n\n%i\n\n", buscaRepeticoes(t, 20));

    destroiArvore(&t);
    destroiArvore(&t2);

    if (t == NULL){
        printf("\n\nOkay!\n");
    }

    return 0;
}
