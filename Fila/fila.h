typedef struct _Fila_ {
	void** dados;
	int   inicio;
	int   fim;
	int   qtd;
	int   tam;
}Fila;

typedef struct _Pilha_ {
	void** dados;
	int    topo;
	int    tam;
}Pilha;
