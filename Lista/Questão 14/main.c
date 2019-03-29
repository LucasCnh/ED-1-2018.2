#include <stdio.h>
#include "tad_fila.h"
#include "tad_pilha.h"
#include "fila_controlada.h"

#define TAM1 20
#define TAM2 20

/*
Questão 14

Escreva uma função que receba duas filas P1 e P2, de inteiros, e seja capaz de
remover suas repetições entre si, mantendo a mesma sequencia de atendimento da
fila.
*/

int removeRepetidos (Fila* P1, Fila* P2, int qtdAtendidos, int peso){ 

	if ((P1 == NULL) || (P2 == NULL)){
		return 0;
	}

	if ((P1 -> valores == NULL) || (P2 -> valores == NULL)){
		return 0;
	}

	if ((empty(P1)) || (empty(P2))){
		return 0;
	}

	Pilha* aux = criaPilha(P1 -> qtdMax);

	if (aux == NULL){
		return 0;
	}

	if (((qtdAtendidos)%(peso)) == 0){

		int encontrado = 0;
		int i = P2 -> prim;

		do{
			
			if (P1 -> valores[prim] == P2 -> valores[i]){
				dequeue(P1);
				return 1;
			}

			i = (i + 1)%P2 -> qtdMax;
		}while(i != P2 -> ult);

		P1 -> ult--;
		if (P1 -> ult == -1){
			P1 -> ult = P1 -> qtdMax - 1;
		}

		do{
			do{
				if (P1 -> valores[P1 -> ult] == P2 -> valores[i]){
					encontrado = 1;
					break;
				}

				push(aux, P1 -> valores[P1 -> ult]);
				P1 -> ult--;
				if (P1 -> ult == -1){
					P1 -> ult = P1 -> qtdMax - 1;
				}
	    
	    	}while (P1 -> ult != P1 -> prim);

			if(encontrado == 0){
				P1 -> ult = (P1 -> ult+1)%P1 -> qtdMax;
			}

			while (aux -> topo != -1){
				enqueue(P1, pop(aux));
			}

			if (encontrado == 1){
				break;
			}

			i = (i + 1)%P2 -> qtdMax;
		}while(i != P2 -> ult);

		
	}else{
		int encontrado = 0;
		int i = P1 -> prim;

		do{
			
			if (P2 -> valores[prim] == P1 -> valores[i]){
				dequeue(P2);
				return 1;
			}

			i = (i + 1)%P1 -> qtdMax;
		}while(i != P1 -> ult);

		P2 -> ult--;
		if (P2 -> ult == -1){
			P2 -> ult = P2 -> qtdMax - 1;
		}

		do{
			do{
				if (P2 -> valores[P2 -> ult] == P1 -> valores[i]){
					encontrado = 1;
					break;
				}

				push(aux, P2 -> valores[P2 -> ult]);
				P2 -> ult--;
				if (P2 -> ult == -1){
					P2 -> ult = P2 -> qtdMax - 1;
				}
	    
	    		}while (P2 -> ult != P2 -> prim);

			if(encontrado == 0){
				P2 -> ult = (P2 -> ult+1)%P2 -> qtdMax;
			}

			while (aux -> topo != -1){
				enqueue(P2, pop(aux));
			}

			if (encontrado == 1){
				break;
			}

			i = (i + 1)%P2 -> qtdMax;
		}while(i != P2 -> ult);

	}

	return 1;
}

int main()
{
	srand(time(NULL));
	Fila_controle* filas = criaFilaControle(TAM1, TAM2, 3);

	for (int i = 0; i < 40; i++){
		enqueueControle (filas, rand()%20, i%2);
		printf("Fila normal: ");
		printaFila(filas -> normal);
		printf("\n");
		printf("Fila prioritaria: ");
		printaFila(filas -> prioritaria);
		printf("\n");
		removeRepetidos(filas -> normal, filas -> prioritaria, filas -> qtdAtendidos, filas -> peso);
		printf("Fila normal: ");
		printaFila(filas -> normal);
		printf("\n");
		printf("Fila prioritaria: ");
		printaFila(filas -> prioritaria);
		printf("\n");
	}

	for (int i = 0; i < 40; i++){
		if (i%2 == 0){
			enqueueControle(filas, rand()%20, rand()%2);
		}
		printf("Fila normal: ");
		printaFila(filas -> normal);
		printf("\n");
		printf("Fila prioritaria: ");
		printaFila(filas -> prioritaria);
		printf("\n");
		removeRepetidos(filas -> normal, filas -> prioritaria, filas -> qtdAtendidos, filas -> peso);
		dequeueControle(filas);
		printf("Fila normal: ");
		printaFila(filas -> normal);
		printf("\n");
		printf("Fila prioritaria: ");
		printaFila(filas -> prioritaria);
		printf("\n");
	}

	destroiFilaControle(&filas);

	return 0;
}