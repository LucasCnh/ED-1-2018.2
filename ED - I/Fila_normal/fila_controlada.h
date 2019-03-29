typedef struct _Fila_controle_{ //Estrutura que simulará um processo de controle de duas filas
	Fila* normal; //Fila de atendimento normal
	Fila* prioritaria; //Fila de atendimento prioritária
	int peso; //Razão de atendimento entre a fila normal e a prioritária
	int qtdAtendidos; //Quantidade de pessoas que foram atendidas até aqui
}Fila_controle;

/**
@criaFilaControle (int tamanhoN, int tamanhoP, int peso)
@brief função que cria um controle de duas filas 
@param tamanhoN é tamanho da fila que representará a fila normal
@param tamanhoP é tamanho da fila que representará a fila prioritária
@param peso será a razão de atendimento entre prioritários e normais
@return estrutura do tipo Fila_controle
*/
Fila_controle* criaFilaControle (int tamanhoN, int tamanhoP, int peso);

/**
@enqueueControle (Fila_controle* filas, int valor, int prioridade)
@brief função que inserirá um novo valor á uma das filas de acordo com a prioridade informada
@param filas são aonde será inserido um novo valor (em uma das duas)
@param valor é a representação da pessoa a ser inserida em uma das filas
@param prioridade é o valor (flag) que indica em qual das duas filas a pessoa será inserida (0 == normal)(dif de 0 == prioritaria)
@return 1 caso foi possivel realizar a inserção, 0 caso contrário
*/
int enqueueControle (Fila_controle* filas, int valor, int prioridade);

/**
@dequeueControle (Fila_controle* filas)
@brief função que realiza o atendimento das filas de acordo com a razao informada (peso)
@param filas são as duas filas de onde será realizado o próximo atendimento (em uma delas)
@return 1 caso o atendimento tenha sido bem sucedido, 0 caso contrário
*/
int dequeueControle (Fila_controle* filas);

/**
@destroiFilaControle (Fila_controle** filas)
@brief função que destroi as duas filas assim como suas estruturas e a estrutura do tipo Fila_controle
@param filas são as filas a serem destruídas (desalocadas)
*/
int destroiFilaControle (Fila_controle** filas);