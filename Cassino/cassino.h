#ifndef TAD_Cartas
#define TAD_Cartas

typedef struct _Carta_ { //Estrutura que guardará as informações de determinada carta -nó da lista-
	int valor; //Número correspondente da carta
	char* terno; //Nome da carta
	struct _Carta_* next; //Próxima carta do baralho
}Carta;

typedef struct _Lista_ { //Estrutura que guardará o baralho -Lista-
	Carta* head; //Primeira carta do baralho
}Lista;

/**
@criaLista()
@brief função que cria uma nova lista vazia
@return estrutura do tipo Lista com nenhum nó
*/
Lista* criaLista ();

/**
@push (Lista** lista)
@brief função que insere uma nova carta ao topo do baralho
@param lista é a estrutura do tipo Lista que receberá um novo nó
@param valor é o valor da nova carta a ser inserida
@param nome é o nome da nova carta a ser inserida
@return 1 caso a inserção tenha sido bem-sucedida, 0 caso contrário
*/
int push (Lista** lista, int valor, char* nome);

/**
@ordenaLista (Lista** lista)
@brief função que ordena o baralho (menor valor no topo, maior no fundo)
@param lista é a estrutura do tipo Lista á ser ordenada
@return 1 caso a ordenação tenha sido bem-sucedida, 0 caso contrário
*/
int ordenaLista (Lista** lista);

/**
@printaLista (Lista* lista)
@brief função que printa os nomes de carta do baralho
@param lista é a estrutura do tipo Lista á ser printada
*/
void printaLista (Lista* lista);

//int pop (Lista** lista);


/**
@destroiLista (Lista** lista)
@brief função que destroi uma lista
@param lista é a estrutura do tipo Lista á ser destruída
@return 1 caso  destruição tenha sido bem-sucedida, 0 caso contrário
*/
int destroiLista (Lista** lista);

#endif