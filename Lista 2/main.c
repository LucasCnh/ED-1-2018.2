#include <stdio.h>
#include <stdlib.h>
#include "lista_dupla.h"
#include "resolvendoAlista.h"

int main(void) {

  ListaDupla* l = criaListaDupla();
  for (int i = 0; i < 14; i++){
    insercaoListaDupla(l, i);
  }
  //ListaDupla* l2 = criaListaDupla();
  
  //removeNelemento(l, 16);

  // printf("Soma dos elementos = %i\n", retornaSomadeInteirosLista(l));
  // printf("Num de elementos da lista: %i\n", retornaNumElementos(l));
  // for (int i = 15; i < 30; i++){
  //   insercaoListaDupla(l2, i);
  // }

  //inserirElementoDepoisDoN (l, 90, 1);
  //uniao(l, l2);
  //printaListaDupla(juntaEordena(l, l2));
  //invertendoLista(l);
  //deslocaNoPNposaFrente (l, 5, 4);
  printaListaDupla(l);

  // intersecao(l, l2);
  //printaListaDupla(l2);
  
  for (int i = 5; i < 40; i++){
    eliminaCadaSegundoElemento(l);
  }

  printaListaDupla(l);

  destroiListaDupla(&l);
  // destroiListaDupla(&l2);

  if (l == NULL){
    printf("Deu certo :)\n\n");
  }

  printaListaDupla(l);

  return 0;
}