#ifndef TAD_JOLLY
#define TAD_JOLLY

typedef struct _Node_ { //Nó que representará o valor atual da sequência
	struct _Node_* next; //Próximo número da sequência
	int num; //Número atual
}Node;

typedef struct _Lista_ { //Lista que representará a sequência
	Node* head;
	int jolly;
	int size;
}Lista;

void checaJolly ();
void printaLista (Lista* lista);
int destroiLista (Lista** lista);

#endif