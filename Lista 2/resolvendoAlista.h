#ifndef Lista
#define Lista

#include "lista_dupla.h"

int concatenandoListas (ListaDupla* l1, ListaDupla* l2); //QUESTÃO 2
int invertendoLista (ListaDupla* l1); //QUESTÃO 4
int eliminaUltimoElemento (ListaDupla* l); //QUESTÃO 5
int removeNelemento (ListaDupla* l, int n); //QUESTÃO 6
//QUESTÃO 7
int ordenaLista (ListaDupla* l); //QUESTÃO 12
ListaDupla* juntaEordena (ListaDupla* l, ListaDupla* l1);
//

//
int busca (ListaDupla* l, int valor); 
int uniao (ListaDupla* l, ListaDupla* l2); //QUESTÃO 8
int intersecao (ListaDupla* l, ListaDupla* l2); //QUESTÃO 9
//

int inserirElementoDepoisDoN (ListaDupla* l, int valor, int nes); //QUESTÃO 10
int eliminaCadaSegundoElemento (ListaDupla* l); //QUESTÃO 11
int retornaSomadeInteirosLista (ListaDupla* l); //QUESTÃO 13
int retornaNumElementos (ListaDupla* l); //QUESTÃO 14
int deslocaNoPNposaFrente (ListaDupla* l, int pos, int des); //QUESTÃO 15
ListaDupla* copiaLista (ListaDupla* l); //QUESTÃO 16

#endif