#include <stdio.h>
typedef DATA char*;

typedef struct _Seq_{
	DATA* dados;
	int max;
	int qtd;
}Sequencia;

/*
	Quando programa,mos temos dificuldade em mudar tipos de dados
	O que fazer quando temos um programa e desejamos mudar tipos de dados de muitas variaveis?!

	Solução gambiarrenta:
 
	typedef struct _Seq_{
		DATA* dados;
		int max;
		int qtd;
	}Sequencia;

	int inserir(Sequencia* seq, DATA valor);

	"Nenhum código jamais será mudado" -BRAZ, Geraldo
*/

int inserir(Sequencia* seq, DATA valor);

int main(int argc, char const *argv[])
{
	
	Sequencia* seq;

	seq = inserir(seq);

	printf("%s\n", seq -> dados[0]);
	
	return 0;
}


Sequencia* criar (Sequencia* seq, DATA valor){

	seq = (Sequencia*) malloc(sizeof(Sequencia));

	seq -> qtd = 0;

	seq -> max = 10;

	seq -> dados = (DATA*) malloc((seq -> max)*sizeof(DATA));

	strcpy(seq -> dados, valor);

	return seq;
}




















