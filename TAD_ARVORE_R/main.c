#include <stdio.h>
#include "lista_dupla.h"
#include "treinamento.h"
#include "tad.h"

int main(){

    Node* t = NULL;
//    Node* t2 = NULL;
    insercao(&t, 10);
    insercao(&t, 5);
    insercao(&t, 15);
    insercao(&t, 8);
    insercao(&t, 17);
    insercao(&t, 12);
    //insercao(&t, 13);
    //insercao(&t, 16);
    insercao(&t, 3);
    //insercao(&t, 4);
    //insercao(&t, 10);

    // insercao(&t2, 10);
    // insercao(&t2, 5);
    // insercao(&t2, 15);
    // insercao(&t2, 8);
    // insercao(&t2, 17);
    // insercao(&t2, 12);
    // insercao(&t2, 13);
    // insercao(&t2, 16);
    // insercao(&t2, 3);
    // insercao(&t2, 4);
    // insercao(&t2, 6);

    //remocao(&t, 8);
    emOrdem(t);
    printf("\n\n");
    ListaDupla* l = NULL;
    printaListaDupla(retornaEmOrdem(t, l));
    //arvoreEspelhada(&t);
    //printf("\n\n%i\n\n", numElementosAPartirDeH(t, 2));
    //encontraNosEmNivel(t, 0);
    printf("\n\n");
    //remocao(&t, 10);
    //remocao(&t, 3);
    emOrdem(t);

    destroi(&t);
  //  destroi(&t2);

    if (t == NULL){
        printf("\n\nOK!\n\n");
    }

    return 0;
}
