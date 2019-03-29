typedef struct _Seq_{
	int* dados;
	int max;
	int qtd;
};

/*
	typedef DATA char*;

	Quando programa,mos temos dificuldade em mudar tipos de dados
	O que fazer quando temos um programa e desejamos mudar tipos de dados de muitas variaveis?!

	Solução gambiarrenta:

	typedef DADA char*;

	typedef struct _Seq_{
		DATA* dados;
		int max;
		int qtd;
	}Sequencia;

	int inserir(Sequencia* seq, DATA valor);

	"Nenhum código jamais será mudado" -BRAZ, Geraldo

	-O unico jeito de fazer um tipo de dado genérico (tem mais coisas que eu esqueci de copiar):
	
	utilizando funções que permitem alterar o tipo:

	int comp(DATA a, DATA b){
		char* a1 = a;
		char* a2 = b;

		return strcmp(a1, a2);
	}

	int buscar(Sequencia* seq, DATA valor, int (*comp)(DATA a, DATA b));
	
	Utilizando o tipo de dados void** poderemos guardar todos os tiposs de dados
	
		typedef int (*Compara) (void* a, void* b);
		typedef void (*Print) (void* a);

		typedef struct _sequencia_ {
			void** dados;
			int max;
			int qtd;
			Print print;
			Compara comp;
		}sequencia;

	Quando se cria funções genéricas, podemos também criar tipos genéricos que recebem qualquer dado: void
	Este tipo de dado só serve para guardar referência.
*/
typedef int (*Compara) (void* a, void* b);
typedef void (*Print) (void* a);

typedef struct _sequencia_ {
	void** dados;
	int max;
	int qtd;
	Compara comp;
	Print print;
}sequencia;	


























