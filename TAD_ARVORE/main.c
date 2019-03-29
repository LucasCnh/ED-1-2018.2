#include <stdio.h>
#include "arvores.h"

int main(){

    Tree* t = NULL;

    printf("%i", criaArvore(t, 20));
    printf("%i", criaArvore(t, 10));
    printf("%i", criaArvore(t, 30));
    printf("%i", criaArvore(t, 5));
    printf("%i", criaArvore(t, 7));
    printf("%i", criaArvore(t, 3));
    printf("%i", criaArvore(t, 15));
    printf("%i\n", criaArvore(t, 11));
    printf("%i\n", criaArvore(t, 18));
    printf("%i\n", criaArvore(t, 25));
    printf("%i\n", criaArvore(t, 22));
    printf("%i\n", criaArvore(t, 28));
    printf("%i\n", criaArvore(t, 35));
    printf("%i\n", criaArvore(t, 32));
    printf("%i\n", criaArvore(t, 33));
    printf("%i\n", criaArvore(t, 36));

    Tree* t2 = NULL;

    printf("%i", criaArvore(t2, 20));
    printf("%i", criaArvore(t2, 10));
    printf("%i", criaArvore(t2, 30));
    printf("%i", criaArvore(t2, 5));
    printf("%i", criaArvore(t2, 7));
    printf("%i", criaArvore(t2, 3));
    printf("%i", criaArvore(t2, 15));
    printf("%i\n", criaArvore(t2, 11));
    printf("%i\n", criaArvore(t2, 18));
    printf("%i\n", criaArvore(t2, 25));
    printf("%i\n", criaArvore(t2, 22));
    printf("%i\n", criaArvore(t2, 28));
    printf("%i\n", criaArvore(t2, 35));
    printf("%i\n", criaArvore(t2, 32));
    printf("%i\n", criaArvore(t2, 33));
    printf("%i\n", criaArvore(t2, 36));

    //printf("\n\n\n%i\n\n\n", arvoresIguais(t, t2));
    //encontraNosDeNivel(t, 2);
    //removeElemento(t, 7);
    //printf("\n\n%i\n\n", buscaMaiorEsq(t -> raiz, t -> raiz -> d));
    //removeElemento(t, 4);
    printaArvore(t);
    //encontraFolhas(t -> raiz);


    destroiArvore(&t);
    destroiArvore(&t2);

    if (t == NULL){
        printf("\n\nOkay!\n");
    }

    return 0;
}
