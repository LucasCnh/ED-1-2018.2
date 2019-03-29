#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "amigos.h"

Galera* criaGalera (){

	Galera* g = (Galera*) malloc(sizeof(Galera));

	if (g != NULL){
		g -> head = NULL;
		g -> tail = NULL;
	}

	return g;
}

int cadastraAmigo (Galera* g, char* nome, int ID){

	if (g == NULL) return 0;

	Pessoa* n = (Pessoa*) malloc(sizeof(Pessoa));

	n -> nome = (char*) malloc(1000);

	if (n == NULL) return 0;
	if (n -> nome == NULL){
		free(n);
		return 0;
	}

	n -> next = n -> prev = NULL;
	strcpy(n -> nome, nome);
	n -> ID = ID;

	if (g -> head == NULL){
		g -> head = g -> tail = n;
		return 1;
	}

	g -> tail -> next = n;
	n -> prev = g -> tail;
	g -> tail = n;

	return 1;
}

void relaciona (int amg1, int amg2, Galera* g){

	if (g == NULL) return;

	Pessoa* amg = g -> head; //Ponteiro que encontrará a pessoa a se relacionar
	while (amg != NULL){
		if (amg -> ID == amg2) break;
		amg = amg -> next;
	}

	Pessoa* p = g -> head; //Ponteiro que encontrará a pessoa que ganhará o amigo
	while (p != NULL){
		if (p -> ID == amg1) break;
		p = p -> next;
	}

	if (amg == NULL || p == NULL) return;

	Amg* n = (Amg*) malloc(sizeof(Amg));

	if (n == NULL) return;

	n -> next = n -> prev = NULL;
	n -> p = amg;

	if (p -> head == NULL){
		p -> head = p -> tail = n;
		return;
	}

	p -> tail -> next = n;
	n -> prev = p -> tail;
	p -> tail = n;

	return;
}

void amigosDeAmigosQueNaoSaoMeusAmigos (Galera* g, int eu){

	if (g == NULL) return;

	Pessoa* p = g -> head;
	while (p != NULL){
		if (p -> ID == eu) break;
		p = p -> next;
	}

	Amg* amgMeu = p -> head; //Ponteiro que percorrerá a lista de meus amigos
	Amg* amgDele; //Ponteiro que percorrerá a lista de amigos de cada amigo meu
	Amg* meus = p -> head; //Ponteiro que percorrerá a lista de meus amigos comparando com cada amigo de meu amigo

	while (amgMeu != NULL){ //Enquanto nenhum amigo meu deixar de ser analisado
		amgDele  = amgMeu -> p -> head; //O ponteiro se iniciará do primeiro amigo de meu amigo
		while (amgDele != NULL){ //Enquanto a lista de amigos de meus amigos não se encerrar
			meus = p -> head; //O ponteiro se iniciará de meu primeiro amigo
			while (meus != NULL){ //Enquanto meus amigos não forem comparados em sua totalidade
				if (meus -> p -> ID == amgDele -> p -> ID) break; //Se um amigo meu tb for amigo de meu amigo, o laço se quebra (é meu amigo tb)
				meus = meus -> next;
			}

			if (meus == NULL){ //Se meus for NULL significa que o amigo do meu amigo não é meu amigo
				printf("Nome: %s, ID: %i, Amg de: %s, ID: %i\n\n\n", amgDele -> p -> nome, amgDele -> p -> ID, amgMeu -> p -> nome, amgMeu -> p -> ID); //Printa as informações do amigo do meu amigo que n é meu amg
			}

			amgDele = amgDele -> next;
		}

		amgMeu = amgMeu -> next;
	}

	return;
}

int destroiAmizades (Galera** g){

	if (*g == NULL) return 0;

	Pessoa* aux = (*g) -> head;
	Pessoa* pes = (*g) -> head;
	Amg* a = NULL;
	Amg* p = NULL;

	while (aux != NULL){
		a = aux -> head;

		while (a != NULL){
			p = a;
			a = a -> next;
			free(p -> p -> nome);
			free(p);
		}

		pes = aux;
		aux = aux -> next;
		free(pes);
	}

	free(*g);
	(*g) = NULL;
	return 1;
}