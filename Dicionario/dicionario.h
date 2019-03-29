#ifndef DICIONARIO
#define DICIONARIO

typedef struct _Palavra_ Palavra;

typedef struct _Sinonimo_ { //Estrutura que guardará um sinonimo de uma palavra dentro de uma lista de sinonimos
	Palavra* p; //Sinonimo da palavra
	struct _Sinonimo_* next; //Referência para o próximo sinônimo
	struct _Sinonimo_* prev; //Referência para o sinônimo anterior
}Sinonimo;

typedef struct _Palavra_ { //Estrutura que guardará uma palavra e uma lista de sinônimos da mesma
	char* palavra; //Palavra em si
	int vezesUsada; //Numero de vezes que tal palavra foi usada (raridade)
	Sinonimo* head; //Primeiro sinônimo da palavra (lista)
	Sinonimo* tail; //Último sinônimo da palavra (lista)
	Palavra* next; //Próxima palavra do dicionário
	Palavra* prev; //Palavra anterior do dicionário
}Palavra;

typedef struct _Dicionario_ { //Estrutura que guardará todas as palavras do programa
	Palavra* head; //Primeira palavra do dicionário (lista)
	Palavra* tail; //Última palavra do dicionário (lista)
}Dicionario;

/**
@criaDicionario (void)
@brief função que cria uma nova lista de palavras
@return estrutura do tipo Dicionário
*/
Dicionario* criaDicionario (void); 

/**
@inserePalavra (Dicionario* d, char* palavra)
@brief função que insere uma nova palavra no dicionário
@param d estrutura do tipo Dicionario aonde a palavra será inserida
@param palavra string que representa a palavra em si
@return 1, caso a inserção tenha sido bem-sucedida, 0 caso contrário
*/
int inserePalavra (Dicionario* d, char* palavra);

/**
@relacionaSinonimo (char* p1, char* p2, Dicionario* d)
@brief função que relaciona palavras sinônimas
@param p1 String que representa a palavra sinônima de p2 (será buscada no dicionário)
@param p2 String que representa a palavra sinônima de p1 (será buscada no dicionário)
@param d Estrutura do tipo Dicionário que guarda todas as palavras
@return 1 caso a relação tenha sido bem-sucedida, 0 caso contrário
*/
int relacionaSinonimo (char* p1, char* p2, Dicionario* d);

/**
@printaDicionário (Dicionario* d)
@brief função que printa cada palavra de um dicionário e seus sinônimos
@param d Estrutura do tipo Dicionário que representa o dicionário a ser printado
*/
void printaDicionario (Dicionario* d);

/**
@destroiDicionário (Dicionario** d)
@brief função que libera da memória todas as palavras do dicionário, assim como seus sinônimos
@param d Estrutura do tipo Dicionário que será destruída pela função
@return 1 caso a destruição tenha sido bem-sucedida, 0 caso contrário
*/
int destroiDicionario (Dicionario** d);

/**
@trocaTexto (char* texto, Dicionario* d)
@brief função que recebe um texto e substitui as palavras por seus sinônimos mais raros
@param texto String que representará o texto á ser utilizado
@param d Estrutura do tipo Dicionário aonde se encontram os sinônimos a serem utilizados
*/
void trocaTexto (char* texto, Dicionario* d);

/**
@procuraEtroca (char* palavra, Dicionario* d)
@brief função que troca uma palavra por seu sinônimo
@param palavra String que é a palavra original a ser trocada
@param d Estrutura do tipo Dicionário que representa o dicionário que contém os sinônimos
@return String que pode ser a palavra original caso nenhum sinônimo for encontrado ou a mesma for a mais rara ou seu sinonimo
*/
char* procuraEtroca (char* palavra, Dicionario* d);

#endif

/*
Trabalho ED

Um jovem politico deseja impressionar sua plateia quando estiver discussando para outros politicos. Sua intenção é memorizar palavras eloquentes, sinonimos dos termos originalmente usados.

Para isso, você precisa ajudá-lo a memorizar fazendo um programa que lhe auxilie nesse processo.

O programa tem duas partes:

1. O político gera para cada palavra que desejar ser substituída uma lista de sinônimos. O sinônimo por sua vez nada mais é que outra palavra que pode estar sendo usando de maneira compartilhada, pois no portguês, varíos termos podem ter o mesmo significado.

Um exemplo:

- A palavra importante poderia ser trocada por: significativo, grave, sério, considerável, respeitável, interessante, relevante, marcante, notável, superior, valoroso, solene, meritório, elogiável, momentoso, ponderoso, vultoso 

 Já o significativo poderia ser trocado por: significante, considerável, importante, relevante, expressivo, enorme, grande, profundo, intenso, grave, vultoso, apreciável, sério.

Veja que mesmo palavras diferentes, possuem sinônimos iguais. Seu dever, ao guardar as palavras e sinônimos, consiste em saber quais delas são mais raras.

 

2. Na segunda funcionalidade, o político informará um parágrafo de texto. E você deve varrer por suas listas de sinônimos e procurar por aquelas palavras que MENOS ocorrem. Escolha aleatoriamente entre as palavras que menos ocorrem, dentro dos sinônimos conhecidos e as substitua no texto informado pelo político.

*/