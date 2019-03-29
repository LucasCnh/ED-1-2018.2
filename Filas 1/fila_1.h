/*
1) Implemente as funções do TAD fila:

enfileirar
desenfilar
vazia (testa se a fila está vazia)
2) Simule com a Fila implementada em (1) uma fila de atendimento da coordenação. A fila da coordenação deve funcionar da seguinte maneira:

o tamanho máximo da fila é 20. Qualquer entrada a mais na fila deve ser descartada
para começar o atendimento, a fila deve possuir pelo menos 10 pessoas em espera
depois que começa o atendimento, novas pessoas entram na fila e sempre pessoas a mais tempo são atendidas
3) Adicione a lei na fila da coordenação:

inclua a ideia de prioridade da fila da coordenação. Assim idosos, deficientes, gestantes e mulheres com criança de colo, entram numa fila diferente de prioridade.
o atendimento deve priorizar a fila de prioridade na razão 3 para 1. Ou seja, devem ser chamada 3x mais pessoas da fila de prioridade do que da fila normal
*/

/**
@TAD_FILA tad que cria uma fila e administra suas  funcoes de controle
*/
#ifndef TAD_FILA
#define TAD_FILA

typedef void (*Desalocar) (void* a); //Funcao generica que desaloca valores void*
typedef void (*Printar) (void* a); //Funcao generica que printa valores void*

typedef struct _Fila_ { //Estrutura do tipo fila que representara uma fila
	void** matriculas; //Vetor de void* que armazenara cada valor de cada pessoa na fila
	int qtdAtual; //Quantidade atual de pessoas na fila
	int qtdMax; //Quantidade maxima de pessoas na fila
	int prim; //Posicao do primeiro da fila no vetor
	int ult; //Posicao do ultimo da fila no vetor
	Desalocar des;
  	Printar prin;
}Fila;

typedef struct _Fila_prioridade_ { //Estrutura do tipo fila que separa filas de acordo com a prioridade de atendimento
	Fila* normal; //Fila de menor prioridade
	Fila* prioritaria; //Fila de maior prioridade
	int peso; //Razao que calcula a frequencia de atendimento de acordo com a prioridade
	int chamada;
}Fila_controle;

/**
@criaFila (int max, Desalocar d, Printar prin)
@brief cria uma nova fila alocando uma estrutura do tipo Fila
@param tamanho e a quantidade maxima de pessoas possiveis na fila
@param d funcao generica que ira desalocar valores void*
@param p funcao generica que ira printar valores void*
@return estrutura do tipo Fila que representara a fila
*/
Fila* criaFila (int tamanho, Desalocar d, Printar p);

/**
@criaFilaControle (int tamanho1, int tamanho2, int peso, Desalocar d, Printar p)
@brief cria estrutura do tipo Fila_controle que irá possuir filas do tipo Fila (normal e prioritaria)
@param tamanhoN tamanho da fila normal
@param tamanhoP tamanho da fila prioritaria
@param peso razao de atendimento entre a fila normal e a prioritaria
@param d funcao generica que sera usada para desalocar valores void*
@param p funcao generica que sera usada para printar valores void*
@return estrutura do tipo Fila_controle
*/
Fila_controle* criaFilaControle (int tamanhoN, int tamanhoP, int peso, Desalocar d, Printar p);

/**
@insereFilaControle (Fila_controle* filas, void* valor, int prioridade)
@brief insere uma nova pessoa (valor) a fila normal ou prioritaria (dependendo do valor da flag prioridade)
@param filas utilizadas para inserir a nova pessoa
@param valor pessoa a ser inserida em uma das filas
@param prioridade flag utilizada para definir em qual fila a pessoa estara (prioridade == 0: fila normal, prioridade != 0: fila prioritaria)
@return 1 caso a insercao tenha sido bem sucedida, 0 caso contrario
*/
int insereFilaControle (Fila_controle* filas, void* valor, int prioridade);

/**
@atendimento (Fila_controle* filas)
@brief realiza o atendimento de pessoas na fila controle de acordo com a razao
@param filas a serem atendidas
@return 1 caso alguma pessoa tenha sido atendida, 0 caso contrario
*/
int atendimento (Fila_controle* filas);

/**
@destroiFilaControle (Fila_controle** filas)
@brief destroi as filas normais e prioritarias desalocando as mesmas assim como as suas estruturas do tipo Fila e a estrutura do tipo Fila_controle
@param filas Fila_controle a ser destruida
@return 1, caso a destruicao tenha sido bem sucedida, 0 caso contrario
*/
int destroiFilaControle (Fila_controle** filas);

/**
@enfileirar (void* valor)
@brief insere um novo valor na fila, atualizando as informacoes da mesma
@param fila aonde o valor sera inserido
@param valor pessoa a ser inserida na fila
@return 1 caso a insercao tenha sido um sucesso, 0 caso contrario
*/
int enfileirar (Fila* fila, void* valor);

/**
@desenfilar (Fila* fila)
@brief 'atende' a primeira pessoa da fila, removendo a mesma da fila e atualiza as informacoes da mesma
@param fila aonde o valor sera retirada
@return 1 caso o atendimento tenha sido um sucesso, 0 caso contrario
*/
int desenfilar (Fila* fila);

/**
@vazia (Fila* fila)
@brief analisa uma fila e testa se a mesma esta vazia ou nao
@param fila estrutura do tipo Fila a ser analisada
@return 1 caso a mesma esteja vazia, 0 caso contrario
*/
int vazia (Fila* fila);

/**
@printaFila (Fila* fila)
@brief lista a fila atual
@param fila fila a ser listada
*/
void printaFila (Fila* fila);

/**
@destroiFila (Fila** fila)
@brief 'destroi' a fila desalocando todos os membros da mesma (e mandando todo mundo pra casa porque o horario de atendimento acabou)
@param fila estrutura do tipo Fila a ser desalocada e atribuida NULL a mesma
@return 1 caso a destruicao tenha sido bem sucedida, 0 caso contrario
*/
int destroiFila (Fila** fila);

#endif