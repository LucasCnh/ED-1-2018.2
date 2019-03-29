#ifndef Treinamento
#define Treinamento

#include "tad.h"
#include "lista_dupla.h"

void encontraFolhas(Node* t);
void encontraNosEmNivel(Node* t, int nivel);
int arvoresIguais (Node* t1, Node* t2);
int repeticoes (Node* t, int valor);
int arvoreCheia (Node* t);
int numElementos (Node* t);
int numElementosAPartirDeH (Node* t, int h);
int arvoreEspelhada (Node** t);
ListaDupla* retornaEmOrdem (Node* t, ListaDupla* l);

#endif