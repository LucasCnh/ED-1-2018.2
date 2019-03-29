int dequeue (fila* fifo){

	fila* retorno = NULL;
	int dado;

	if (fifo -> inicio != NULL){
		
		retorno = fifo -> inicio;
		fifo -> inicio = fifo -> inicio -> prox;
		dado = retorno -> dado;
		free(retorno);
		retorno = NULL;
	}

	return dado;
}

int enqueue (fila* fifo, int dado){

	fila* novo = criar(dado);

	if (novo == NULL) return 0;

	if (fifo -> fim == NULL){
		fifo -> fim = novo;
		fifo -> inicio = novo;
	}
	else{
		fifo -> fim -> prox = novo;
		fifo -> fim = novo;
	}
	
	return 1;
}