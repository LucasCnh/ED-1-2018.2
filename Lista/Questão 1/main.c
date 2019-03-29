#include <stdio.h>
#include <stdlib.h>
#include "tad_pilha.h"

/*
Questão 1

Use as operações push, pop, top e empty para construir operações que façam o
seguinte:

a. Definir i com o segundo elemento a partir do topo da pilha, deixando a pilha sem
seus dois elementos superiores.
b. Definir i com o segundo elemento a partir do topo da pilha, deixando a pilha
inalterada.
c. Dado um inteiro n, definir i como o enésimo elemento a partir do topo da pilha,
deixando a pilha sem seus n elementos superiores.
d. Dado um inteiro n, definir i como o enésimo elemento a partir do topo da pilha,
deixando a pilha inalterada.
e. Definir i como o último elemento da pilha, deixando a pilha vazia.
f. Definir i como o último elemento da pilha, deixando a pilha inalterada. (Dica: use
outra pilha auxiliar.)
g. Definir i como o terceiro elemento a partir do final da pilha.
*/

int letraA (Pilha* pilha, int i){

	if ((pilha == NULL) || (pilha -> valores == NULL) || (pilha -> topo <= 1)){
		return 0;
	}

	pop(pilha);
	pop(pilha);

	push(pilha, i);

	return 1;
}

int letraB (Pilha* pilha, int i){

	if ((pilha == NULL) || (pilha -> valores == NULL) || (pilha -> topo <= 1)){
		return 0;
	}

	if ((pilha -> topo) == (pilha -> qtdMax - 1)){ 
		return 0;
	}

	Pilha* aux = criaPilha(pilha -> qtdMax);

	if ((aux == NULL) || (aux -> valores == NULL)){
		return 0;
	}

	int auxiliar = pilha -> qtdAtual - 1;

	while ((auxiliar - pilha -> topo) != 2){
		push(aux, pop(pilha));
	}

	push(pilha, i);
	push(pilha, pop(aux));
	push(pilha, pop(aux));

	destroiPilha(&aux);

	return 1;
}

int letraC (Pilha* pilha, int i, int n){

	if ((pilha == NULL) || (pilha -> valores == NULL) || (pilha -> topo <= 1) || (n > pilha -> qtdAtual)){
		return 0;
	}

	if ((pilha -> topo) == (pilha -> qtdMax - 1)){ 
		return 0;
	}

	int auxiliar = pilha -> qtdAtual - 1;

	while ((auxiliar - pilha -> topo) != n){
		pop(pilha);
	}

	push(pilha, i);

	return 1;
}

int letraD (Pilha* pilha, int i, int n){

	if ((pilha == NULL) || (pilha -> valores == NULL) || (pilha -> topo <= 1) || (n > pilha -> qtdAtual)){
		return 0;
	}

	if ((pilha -> topo) == (pilha -> qtdMax - 1)){ 
		return 0;
	}

	Pilha* aux = criaPilha(pilha -> qtdMax);

	if ((aux == NULL) || (aux -> valores == NULL)){
		return 0;
	}

	int auxiliar = pilha -> qtdAtual - 1;

	while ((auxiliar - pilha -> topo) != n){
		push(aux, pop(pilha));
	}

	push(pilha, i);
	while (((auxiliar + 1) > pilha -> topo)){
		push(pilha, pop(aux));
	}

	destroiPilha(&aux);

	return 1;
}

int letraE (Pilha* pilha, int i){

	return letraC(pilha, i, pilha -> qtdAtual);
}

int letraF (Pilha* pilha, int i){

	return letraD(pilha, i, pilha -> qtdAtual);
}

int letraG (Pilha* pilha, int i){

	return letraD(pilha, i, pilha -> qtdAtual - 3);
}

int main(){

	Pilha* pilha = criaPilha(20);

	for (int i = 0; i < 19; i++){
		push(pilha, i);
	}

	printaPilha(pilha);

	letraA(pilha, 3);

	printaPilha(pilha);

	letraB(pilha, 5);

	printaPilha(pilha);

	letraC(pilha, 19, 5);

	printaPilha(pilha);

	letraD(pilha, 19, 17);

	printaPilha(pilha);

	letraA(pilha, 3);

	printaPilha(pilha);

	letraF(pilha, 80);

	printaPilha(pilha);

	letraG(pilha, 50);

	printaPilha(pilha);

	letraE(pilha, 70);

	printaPilha(pilha);

	destroiPilha(&pilha);

	return 0;
}
