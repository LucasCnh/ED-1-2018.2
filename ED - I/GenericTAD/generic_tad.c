#include <stdio.h>
#include <stdlib.h>
#include "generic_tad.h"

Sequencia* criaSequencia (int max, Comparar c, Printar p, Desalocar d){

  	Sequencia* seq = (Sequencia*) malloc(sizeof(Sequencia));
	if (seq  == NULL){ //Caso a estrutura nao pode ser alocada retorna NULL
		return NULL;
	}

	seq -> dados = (void**) malloc(max*sizeof(void*)); //Alocando vetor de void* com o tamanho igual a quantidade max de valores

	if (seq -> dados == NULL){ //Caso a sequencia nao pode ser alocada, desaloca a estrutura, aponta a mesma a NULL e retorna NULL
		free(seq);
		seq = NULL;
		return NULL;
	}

	seq -> qtdMax = max; //Quantidade maxima passa a ser igual ao tamanho max da sequencia
	seq -> qtdAtual = 0; //Quantidade atual passa a ser 0 pois a sequencia acabou de ser criada
	seq -> comp = c; //Atribuindo a comp a funcao do tipo Comparar que o usuario informou
	seq -> printa = p; //Atribuindo a printa a funcao do tipo Printar que o usuario informou
	seq -> desaloca = d; //Atribuindo a desaloca a funcao do tipo Desalocar que o usuario informou

	return seq; //Retorna a estrutura do tipo Sequencia com a propria e seq -> dados ja alocados
}

int inserir (Sequencia* seq, void* valor){

	if ((seq == NULL) || (seq -> dados == NULL) || (seq -> qtdAtual == seq -> qtdMax)){ 
		return 0; //Caso algo nao esteja alocado ou a sequencia estiver cheia retorna 0
	}

	seq -> dados[seq -> qtdAtual] = valor; //Insere o valor na sequencia
	seq -> qtdAtual++; 

	return 1;
}

void printar (Sequencia* seq){

	if ((seq == NULL) || (seq -> dados == NULL) || (seq -> qtdAtual == 0)){ 
		return; //Caso algo nao esteja alocado devidamente ou nao exista elemento na sequencia ainda, a funcao evita o resto de seu corpo e imediatamente retorna
	}

	for (int i = 0; i < (seq -> qtdAtual); i++){ //O for percorrera da posicao 0 ate a ultima posicao (seq -> qtdAtual - 1)
		seq -> printa(seq -> dados[i]); //Utilizando a funcao que printa valores genericos
	}

	return;
}

int busca (Sequencia* seq, void* chave){

	if ((seq == NULL) || (seq -> dados == NULL) || (seq -> qtdAtual <= 0)){ 
		return -1; //Caso algo nao esteja alocado devidamente ou nao exista elemento na sequencia ainda, a funcao evita o resto de seu corpo e imediatamente retorna -1
	}
	for (int i; i < (seq -> qtdAtual); i++){ //For que percorre todo o vetor seq -> dados buscando pela chave informada pelo usuario
		if ((seq -> comp(seq -> dados[i], chave)) == 0){ //Cada posicao do vetor é comparada a chave utilizando a função genérica seq -> comp que compara tipos de dados genéricos
			return i; //Se foi encontrado um valor no vetor sequencia igual ao dado pelo usuario, a função retorna a posicao do mesmo no vetor
		}
	}

	return -1; //Caso n tenha encontrado, a funcao retorna -1
}

int remover (Sequencia* seq, void* chave){

	if ((seq == NULL) || (seq -> dados == NULL) || (seq -> qtdAtual <= 0)){ 
		return 0; //Caso algo nao esteja alocado devidamente ou nao exista elemento na sequencia ainda, a funcao evita o resto de seu corpo e imediatamente retorna 0
	}

	for (int i = 0; i < (seq -> qtdAtual); i++){ //Laco que percorrera a sequencia
		if ((seq -> comp(seq -> dados[i], chave)) == 0){ //Comparando cada elemento da sequencia com o valor dado pelo o usuario utilizando a funcao generica seq -> comp
			seq -> desaloca(seq -> dados[i]); //Desalocando a posicao encontrada da memoria utilizando a funcao generica seq -> desaloca
			seq -> dados[i] = seq -> dados[seq -> qtdAtual - 1]; //Atribuindo o endereco da ultima posicao do vetor a posicao aonde o valor foi encontrado
      		seq -> qtdAtual--; //Decrementando a quantidade de valores presentes na sequencia
			return 1; //Valor encontrado, a funcao retorna 1
		}
	}

	return 0; //Valor nao encontrado, a funcao retorna 0
}

int removerTodos (Sequencia* seq, void* chave){

	if ((seq == NULL) || (seq -> dados == NULL) || (seq -> qtdAtual <= 0)){
		return 0; //Caso algo nao esteja alocado devidamente ou nao exista elemento na sequencia ainda, a funcao evita o resto de seu corpo e imediatamente retorna 0
	}

	int encontrado = 0; //Flag para indicar o retorno, caso algum elemento tenha sido removido com sucesso

	for (int i = 0; i < (seq -> qtdAtual); i++){ //Laco que percorrera a sequencia
		if ((seq -> comp(seq -> dados[i], chave)) == 0){ //Comparando cada elemento da sequencia com o valor dado pelo o usuario utilizando a funcao generica seq -> comp
			seq -> desaloca(seq -> dados[i]); //Desalocando a posicao encontrada da memoria utilizando a funcao generica seq -> desaloca
			seq -> dados[i] = seq -> dados[seq -> qtdAtual - 1]; //Atribuindo o endereco da ultima posicao do vetor a posicao aonde o valor foi encontrado
			seq -> qtdAtual--; //Decrementando a quantidade de valores presentes na sequencia
			encontrado = 1; //Flag agora igual a 1 pois um valor foi encontrado
			i--; //Decrementando o valor i do for para checar se a ultima posicao tambem nao era igual ao valor dado pelo usuario
		}
	}

	if (encontrado == 0){ //Se foi encontrado o valor na sequencia e o mesmo foi removido a funcao retorna 1, caso contrario retorna 0
		return 0;
	}else{
		return 1;
	}
}

int destroi (Sequencia** seq){

	if ((*seq == NULL)) return 0; //Caso a estrutura do tipo Sequencia nao exista retorna 0

	Sequencia* aux = *seq;

	if (aux -> dados == NULL){ //Se o vetor aux -> dados ja estiver desalocado apenas desaloca a estrutura
		free(aux);
		aux = NULL;
		*seq = NULL;
		return 1;
	}

	for (int i = 0; i < (aux -> qtdAtual); i++){
		aux -> desaloca(aux -> dados[i]); //Desalocando cada elemento void* do vetor de dados genericos aux -> dados utilizando a funcao generica desaloca
	}

	free(aux -> dados); //Desalocando o vetor em si
	aux -> dados = NULL;
	free(aux);
	aux = NULL;
	*seq = NULL;

	return 1;
}