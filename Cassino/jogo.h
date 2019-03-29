#ifndef TAD_Jogo
#define TAD_Jogo

/**
A Big City tem muitos cassinos. Em um deles, o dealer engana. Ela aperfeiçoou vários embaralhamentos; 
Cada shuffle reorganiza os cartões exatamente da mesma maneira sempre que for usado. Um exemplo simples é o shuffle 
“bottom card”, que remove o cartão inferior e o coloca no topo. Usando várias combinações desses shuffles conhecidos, 
o dealer corrupto pode organizar o empilhamento dos cartões em praticamente qualquer ordem específica.

Você foi contratado pelo gerente de segurança para rastrear esse dealer. 
Você recebe uma lista de todos os embaralhamentos realizados pelo mesmo,
juntamente com dicas visuais que permitem que você determine qual shuffle ela usa em um determinado momento. 
Seu trabalho é prever a ordem das cartas depois de uma sequência de embaralhamentos.

Um baralho de cartas padrão contém 52 cartas, com 13 valores em cada um dos quatro naipes. 
Os valores são nomeados 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace. 
Os naipes são nomeados Clubes, Diamantes, Copas, Espadas. 
Uma carta em particular no baralho pode ser identificada exclusivamente por seu valor e naipe, 
normalmente denotado <valor> de <terno>. Por exemplo, "9 de Copas" ou "Rei de Espadas". 
Tradicionalmente, um novo baralho é ordenado primeiro em ordem alfabética por naipe, 
depois por valor na ordem dada acima.

 

Input

A entrada começa com um único inteiro positivo em uma linha, indicando o número de casos de teste, 
seguido por uma linha em branco. Há também uma linha em branco entre duas entradas consecutivas.

Cada caso consiste em um inteiro n ≤ 100, o número de embaralhamentos que o dealer conhece. 
Então siga n conjuntos de 52 inteiros, cada um compreendendo todos os inteiros de 1 a 52 em alguma ordem. 
Dentro de cada conjunto de 52 inteiros, i na posição j significa que o shuffle move a i-ésima carta do baralho para a posição j.

Output

Para cada caso de teste, assuma que o revendedor começa com um novo deck encomendado conforme descrito acima. 
Depois de todos os embaralhamentos terem sido realizados, forneça os nomes das cartas no baralho, na nova ordem. 
A saída de dois casos consecutivos será separada por uma linha em branco.

Sample Input

1
2
2 1 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 52 51

52 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26  27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 1
 

 

Sample Output

King of Spades

2 of Clubs
4 of Clubs
5 of Clubs

6 of Clubs
7 of Clubs
8 of Clubs
9 of Clubs
10 of Clubs

Jack of Clubs

Queen of Clubs

King of Clubs

Ace of Clubs

2 of Diamonds
3 of Diamonds
4 of Diamonds
5 of Diamonds
6 of Diamonds
7 of Diamonds
8 of Diamonds
9 of Diamonds
10 of Diamonds

Jack of Diamonds

Queen of Diamonds

King of Diamonds

Ace of Diamonds

2 of Hearts
3 of Hearts
4 of Hearts
5 of Hearts
6 of Hearts
7 of Hearts
8 of Hearts
9 of Hearts
10 of Hearts

Jack of Hearts

Queen of Hearts

King of Hearts

Ace of Hearts

2 of Spades
3 of Spades
4 of Spades
5 of Spades
6 of Spades
7 of Spades
8 of Spades
9 of Spades
10 of Spades

Jack of Spades

Queen of Spades

Ace of Spades

3 of Clubs
*/

#include "cassino.h"

typedef struct _Mov_ { //Estrutura que guardará cada movimento do embaralhamento solicitado
	struct _Mov_* next; //Próximo movimento
	int origem; //Posição original da carta
	int destino; //Com qual posição a carta será trocada
}Mov;

typedef struct _Shuffle_ { //Estrutura que lista os movimentos
	Mov* prim; //Primeiro movimento
	Mov* ult; //Último movimento
}Shuffle;

/**
@Shuffle será representado como uma estrutura de dados do tipo fila
*/

/**
@jogo ()
@brief função que simula o jogo
*/
void jogo (); 

/**
@shuffle (Lista** baralho)
@brief função que realiza o embaralhamento
@param baralho é o baralho a ser modificado
*/
void shuffles (Lista** baralho);

/**
@criaShuffle (void)
@brief função que criará estrutura do tipo Shuffle que guardará os movimentos
*/
Shuffle* criaShuffle (void);

/**
@enqueueShuffle (Shuffle* shuffle, int origem, int destino)
@brief função que insere um novo movimento ao fim da estrutura shuffle
@param shuffle é a estrutura do tipo Shuffle aonde será inserido o movimento
@param origem é a posição original da carta no baralho
@param destino é a nova posição da carta no baralho
@return 1 caso a inserção seja bem-sucedida, 0 caso contrário
*/
int enqueueShuffle (Shuffle* shuffle, int origem, int destino);

/**
@dequeueShuffle (Shuffle* shuffle, int* ret)
@brief função que retorna os valores origem e destino de um movimento
@param shuffle é a estrutura do tipo Shuffle de onde os valores origem e destino serão retirados
@param ret é a variável passada por referência que retornará o valor de destino
@return origem e destino caso a função tenha sido bem-sucedida, -1 caso contrário
*/
int dequeueShuffle (Shuffle* shuffle, int* ret);

/**
@destroiShuffle (Shuffle** shuffle)
@brief função que destroi estrutura do tipo Shuffle
@param shuffle é a estrutura do tipo Shuffle a ser destruída
@return 1 caso a destruição tenha sido bem-sucedida, 0 caso contrário
*/
int destroiShuffle (Shuffle** shuffle);

#endif