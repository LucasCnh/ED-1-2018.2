#include <stdio.h>
#include "tadAR.h"

int main(){

    Tree* t = criaArvore(10);
    insercao(&t, 5);
    insercao(&t, 15);
    insercao(&t, 8);
    // insercao(&t, 17);
    // insercao(&t, 12);
    // insercao(&t, 13);
    // insercao(&t, 16);
    // insercao(&t, 3);
    // insercao(&t, 4);
    // insercao(&t, 6);

    remocao(&t, 8);
    emOrdem(t);
    printf("\n\n");
    remocao(&t, 10);
    emOrdem(t);

    destruirArvore(&t);

    if (t == NULL){
        printf("\n\nOK!\n\n");
    }

    return 0;
}
