/*
Você foi contratado para descobrir relacionamentos em comum. 
A sua primeira tarefa é implementar uma estrutura de dados para representar as relações de amizade. 
Ou seja, para cada pessoa cadastrada você tem que armazenar a sua lista de amigos. 
Considere que cada pessoa tem um identificador único que é um número inteiro.

a. Declare os tipos necessários para a implementação dessa estrutura.

b. Escreva uma função para cadastrar amigo

c. Escreva uma função para relacionar dois amigos cadastrados

void Relaciona(int Amigo1, int Amigo2, TipoED* pPonteiro)

Considere que o Amigo1 e Amigo2 já estão  previamente cadastrados

d. Escreva uma função para descobrir todos os amigos de amigos seus, que não são seus amigos diretos
*/

#ifndef TAD_Listas
#define TAD_Listas

#include "amigos.h"

/**
@TAD_Listas
@Tad formador de listas duplamente encadeadas como estruturas de dados
*/

typedef struct _Pessoa_ Pessoa;

typedef struct _Amg_ { //Estrutura que define cada nó da lista
	struct _Amg_* next; //Referência para o próximo nó da lista
	struct _Amg_* prev; //Referência para o nó anterior da lista
	Pessoa* p;
}Amg; //Nó

typedef struct _Pessoa_ {
	int ID; //Dado a ser guardado pelo nó
	char* nome; //Nome da pessoa á ser guardado
	Amg* head; //Primeiro amigo da lista
	Amg* tail; //Último (e não menos importante :3) amigo da lista
	struct _Pessoa_* next;
	struct _Pessoa_* prev;
}Pessoa;

typedef struct _Galera_ {
	Pessoa* head;
	Pessoa* tail;
}Galera;

Galera* criaGalera ();
int cadastraAmigo (Galera* g, char* nome, int ID);
void relaciona (int amg1, int amg2, Galera* g);
void amigosDeAmigosQueNaoSaoMeusAmigos (Galera* g, int eu);
int destroiAmizades (Galera** g);


#endif