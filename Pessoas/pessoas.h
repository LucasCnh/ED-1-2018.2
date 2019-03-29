#ifndef TRABALHO_Pessoas
#define TRABALHO_Pessoas

#include "tad_arvore.h"
#include "tad_lista.h"

void cadastro (Tree** nomes, Tree** matriculas, Tree** datasEntrada, Tree** datasSaida);
void edicao (Tree** nomes, Tree** matriculas, Tree** datasEntrada, Tree** datasSaida);
void consulta (Tree* nomes, Tree* matriculas, Tree* datasEntrada, Tree* datasSaida);
void buscaColaborador (Tree* nomes, Tree* matriculas, Tree* datasEntrada, Tree* datasSaida, char* nome, int input);
int descobreColaborador (ListaDupla* l, Tree* nomes, char* nome);
void exibeColaboradores (Tree* n, Tree* m, Tree* dE, Tree* dS);
void destroiArvores (Tree** n, Tree** m, Tree** dE, Tree** dS);
void clean_stdin(void);

#endif