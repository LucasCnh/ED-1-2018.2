typedef struct _Pilha_ {
	int dado;
	struct _Pilha_* next;
}Pilha;

Pilha* criar(int dado);
int push (Pilha** cab, int dado);
int pop(Pilha** cab);
// void printaLista (Pilha* lista);