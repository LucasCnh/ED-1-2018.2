
#ifndef TAD_SEQUENCIA
#define TAD_SEQUENCIA
	
	/**TAD responsavel por administrar um vetor de tipo de dados genérico*/

	typedef int (*Comparar) (void* a, void* b); //Funcao que o usuario do TAD criara para comparar dois valores genericos
	typedef void (*Printar) (void* a); //Funcao que o usuario do TAD criara para printar um valor generico
	typedef void (*Desalocar) (void* a); //Funcao que desalocara da memoria uma posicao do vetor void** dados

	typedef struct _Sequencia_{
		void** dados; //Vetor de void* que armazenara cada valor
		int qtdMax; //Quantidade maxima de valores que podem ser armazenados
		int qtdAtual; //Quantidade atual de valores existentes no vetor
		Comparar comp;
		Printar printa;
		Desalocar desaloca;
	}Sequencia;
	
	/**
	@criaSequencia (Sequencia* seq, int max)
	@brief cria uma nova sequencia caso a mesma ainda nao exista
	@param max quantidade maxima de elementos que a sequencia podera ter
	@return sequencia alocada
	*/
	Sequencia* criaSequencia (int max, Comparar c, Printar p, Desalocar d);

	/**
	@inserir (Sequencia* seq, void* valor)
	@brief insere um novo valor a sequencia caso a mesma nao esteja cheia
	@param seq sequencia a ser utilizada na insercao
	@param valor tipo de dado generico a ser inserido que o usuario do TAD informara
	@return 1 caso a funcao tenha inserido com sucesso, 0 caso contrario
	*/
	int inserir (Sequencia* seq, void* valor);

	/**
	@printar (Sequencia* seq)
	@brief imprime sequencia existente
	@param seq sequencia a ser imprimida
	*/
	void printar (Sequencia* seq);

	/**
	@busca (Sequencia* seq, void* chave)
	@brief busca determinado valor na sequencia caso a mesma exista
	@param seq sequencia a ser percorrida e analisada
	@param chave valor fornecido pelo usuario a ser buscado na sequencia seq
	@return posicao no vetor seq -> dados onde foi encontrado o primeiro valor da sequencia igual ao dado pelo usuario
	@return -1 caso o elemento nao tenha sido encontrado
	*/
	int busca (Sequencia* seq, void* chave);

	/**
	@remover (Sequencia* seq, void* chave)
	@brief remover da sequencia dado valor forncecido pelo usuario 
	@param seq sequencia a ser percorrida e analisada
	@param chave valor fornecido pelo usuario a ser buscado na sequencia seq, caso encontrado o mesmo e removido
	@return 1 caso o elemento tenha sido removido com sucesso, 0 caso contrario
	*/
	int remover (Sequencia* seq, void* chave);

	/**
	@removerTodos (Sequencia* seq, void* chave)
	@brief remove todos os valores da sequencia igual a chave informada pelo usuario
	@param seq sequencia a ser percorrida e analisada
	@param chave valor fornecido pelo usuario a ser buscado na sequencia seq, caso encontrado o mesmo e removido de todas as posicoes onde o mesmo foi encontrado
	@return 1 caso a remoção tenha sido bem sucedida, 0 caso contrario
	*/
	int removerTodos (Sequencia* seq, void* chave);
	
	/**
	@destroi (Sequencia** seq)
	@brief desaloca sequencia existente da memoria
	@param seq sequencia a ser desalocada
	@return 1 caso a funcao tenha destruido com sucesso, 0 caso contrario
	*/
	int destroi (Sequencia** seq);

#endif