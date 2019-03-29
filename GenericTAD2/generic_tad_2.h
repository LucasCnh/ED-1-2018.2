/*

Escreva o seu TAD genérico com as funções de inserção, remoção, busca, criação e destruição
Sobre esse TAD, implemente as seguintes funções nessa ordem:

1) uma nova função de remoção que ao remover insira simplesmente NULL na posição e não mude mais nada.

2) uma nova função de busca que perceba que NULL não é um valor válido e busque conitnue buscando mesmo que o valor seja nulo.

3) uma nova função de inserção que ao verificar que o QTD é maior do que o tamanho do vetor, faça uma busca dentro do vetor por algum elemento que foi removido (conforme questão 1) e insira esse elemento nessa posição

4) uma nova função de inserção que realize a inserção em ordem crescente dos elementos.

Teste tudo.
*/

#ifndef TAD_GENERICO_2
#define TAD_GENERICO_2

typedef int (*Compara) (void* a, void* b); //Funcao generica que compara dois valores genericos
typedef void (*Desaloca) (void* a); //Funcao generica que desaloca da memoria tipos void
typedef void (*Printar) (void* a); //Funcao generica que printa tipos de dados genericos

//Estrutura do tipo Sequencia que ira receber a sequencia
typedef struct _Sequencia_ {
	void** dados; //Vetor de dados genericos que ira representar a sequencia
	int qtdMax; //Quantidade maxima de valores a serem armazenados (tamanho do vetor)
	int qtdAtual; //Quantidade atual de valores presentes na sequencia;
	Compara comp;
	Desaloca des;
	Printar prin;
}Sequencia;

/**
@criaSequencia (int tamanho, Compara c, Desaloca d, Printar p)
@brief cria uma nova sequencia alocando o vetor dados assim como a propia estrutura do tipo Sequenia
@param tamanho representa a quantidade maxima de elementos da sequencia
@param c funcao generica que compara valores do tipo void
@param d funcao generica que desaloca valores do tipo void
@param p funcao generica que printa valores do tipo void
@return estrutura do tipo Sequencia
*/
Sequencia* criaSequencia (int tamanho, Compara c, Desaloca d, Printar p);

/**
@insercao (Sequencia* seq, void* valor)
@brief insere um valor dado pelo usuario na sequencia
@param seq sequencia a ser utilizada na insercao de um novo valor
@param valor a ser inserido na sequencia
@return 1 caso a insercao tenha sido um sucesso, 0 caso contrario
*/
int insercao (Sequencia* seq, void* valor);

/**
@remocao (Sequencia* seq, void* valor)
@brief remove da sequencia um valor informado pelo usuario caso o mesmo exista na sequencia
@param seq sequencia a ser analisada
@param valor a ser buscado na sequencia
@return 1 caso a remocao tenha sido um sucesso, 0 caso contrario 
*/
int remocao (Sequencia* seq, void* valor);

/**
@removeTodos (Sequencia* seq, void* valor)
@brief remove da sequencia todos os valores iguais a um informado pelo o usuario caso o mesmo exista na sequencia
@param seq sequencia a ser analisada
@param valor a ser buscado na sequencia
@return 1 caso a remocao tenha sido um sucesso, 0 caso contrario 
*/
int removeTodos (Sequencia* seq, void* valor);

/**
@busca (Sequencia* seq, void* valor)
@brief busca um valor dado pelo o usuario na sequencia 
@param seq sequencia a ser analisada
@param valor a ser buscado na sequencia
@return posicao no vetor dados onde foi encontrado o valor, -1 caso a busca tenha fracassado
*/
int busca (Sequencia* seq, void* valor);

/**
@printa (Sequencia* seq)
@brief printa todos os valores da sequencia
@param seq sequencia a ser printada
*/
void printa (Sequencia* seq);

/**
@destroi (Sequencia** seq)
@brief destroi a sequencia desalocando todos os membros da estrutura do tipo Sequencia
@param seq sequencia a ser destruida
@return 1 caso a destruicao tenha sido bem-sucedida, 0 caso contrario
*/
int destroi (Sequencia** seq);

#endif