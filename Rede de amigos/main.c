#include <stdio.h>
#include "amigos.h"

int main(){

	Galera* g = criaGalera();

	cadastraAmigo(g, "Lucas", 294);
	cadastraAmigo(g, "Rebeca", 47);
	cadastraAmigo(g, "Italo", 97);
	cadastraAmigo(g, "Emily", 379);
	cadastraAmigo(g, "Fernando", 374);
	cadastraAmigo(g, "Karla", 3875);
	cadastraAmigo(g, "Tercas", 7359);
	cadastraAmigo(g, "Hanna", 34768);
	cadastraAmigo(g, "Sidney", 3989);

	relaciona(294, 47, g);
	relaciona(294, 97, g);
	relaciona(294, 379, g);
	relaciona(294, 374, g);
	relaciona(294, 3989, g);
	relaciona(379, 7359, g);
	relaciona(97, 3875, g);
	relaciona(3989, 34768, g);

	amigosDeAmigosQueNaoSaoMeusAmigos (g, 294);

	destroiAmizades(&g);

	if (g == NULL) printf("YAY!!!\n");

	return 0;
}