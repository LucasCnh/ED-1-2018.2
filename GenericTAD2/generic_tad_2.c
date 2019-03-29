#include <stdio.h>
#include <stdlib.h>
#include "generic_tad_2.h"

Sequencia* criaSequencia (int tamanho, Compara c, Desaloca d, Printar p){

	Sequencia* seq = (Sequencia*) malloc(sizeof(Sequencia));

	if (seq == NULL){
		return seq;
	}

	seq -> dados = (void**) malloc(tamanho*sizeof(void*));

	if (seq -> dados == NULL){
		free(seq);
		seq = NULL;
		return seq;
	}

	seq -> qtdMax = tamanho;
	seq -> qtdAtual = 0;
	seq -> comp = c;
	seq -> des = d;
	seq -> prin = p;

	return seq;
}

int insercao (Sequencia* seq, void* valor){

	if ((seq == NULL) || (seq -> dados == NULL)){
		return 0;
	}

	if (seq -> qtdAtual < seq -> qtdMax){
		seq -> dados[seq -> qtdAtual] = valor;
		seq -> qtdAtual++;
	}else{
		for (int i = 0; i < (seq -> qtdAtual); i++){
			if (seq -> dados[i] == NULL){
				seq -> dados[i] = valor;
				break;
			}
		}
	}

	void* aux;

	for (int i = 0; i < (seq -> qtdAtual); i++){
		for (int j = i+1; j < (seq -> qtdAtual); j++){
			if (((seq -> dados[i] != NULL) && (seq -> dados[j] != NULL)) && ((seq -> dados[j]) < (seq -> dados[i]))){
				aux = seq -> dados[j];
				seq -> dados[j] = seq -> dados[i];
				seq -> dados[i] = aux;
			}
		}
	}

	return 1;
}

int remocao (Sequencia* seq, void* valor){

	if ((seq == NULL) || (seq -> dados == NULL) || (seq -> qtdAtual == 0)){
		return 0;
	}

	for (int i = 0; i < (seq -> qtdAtual); i++){
    	if ((seq -> dados[i] != NULL) && (valor != NULL)){
      		if ((seq -> comp(seq -> dados[i], valor)) == 0){

        		seq -> dados[i] = NULL;

        		return 1;
      		}
    	}
	}

	return 0;
}

int removeTodos (Sequencia* seq, void* valor){

	if ((seq == NULL) || (seq -> dados == NULL) || (seq -> qtdAtual == 0)){
		return 0;
	}

	while ((remocao(seq, valor)) == 1);

	return 1;
}

int busca (Sequencia* seq, void* valor){

	if ((seq == NULL) || (seq -> dados == NULL) || (seq -> qtdAtual == 0)){
		return -1;
	}

	for (int i = 0; i < (seq -> qtdAtual); i++){
		if (seq -> dados[i] != NULL && valor != NULL){
			if ((seq -> comp(seq -> dados[i], valor)) == 0){
				return i;
			}
		}else if(valor == NULL){
			return i;
		}
	}

	return -1;
}

void printa (Sequencia* seq){

	if ((seq == NULL) || (seq -> dados == NULL) || (seq -> qtdAtual == 0)){
		return;
	}

	for (int i = 0; i < (seq -> qtdAtual); i++){
		if (seq -> dados[i] != NULL){
			seq -> prin(seq -> dados[i]);
		}
	}

	printf("\n\n");
	
	return;
}

int destroi (Sequencia** seq){


	Sequencia* aux = *seq;
	
	if ((aux == NULL) || (aux -> dados == NULL)){
		return 0;
	}

	for (int i = 0; i < (aux -> qtdAtual); i++){
		if (aux -> dados[i] != NULL){
			aux -> des(aux -> dados[i]);
		}
	}

	free(aux -> dados);
	aux -> dados = NULL;

	free(aux);
	aux = NULL;
	*seq = NULL;

	return 1;
}