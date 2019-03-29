typedef struct _Pilha_Dupla_{
	int* valores;
	int  qtdMax;
	int topo1;
	int topo2;
}PilhaDupla;

PilhaDupla* criaPilhaDupla (int tamanho){

	PilhaDupla* pilha = (PilhaDupla*) malloc(sizeof(PilhaDupla));

	if (pilha == NULL){ //Checando se foi possível alocar a estrutura do tipo Pilha
		return pilha;
	}

	pilha -> valores = (int*) malloc(tamanho*sizeof(int)); //Alocando o vetor valores que representará a pilha com o tamanho dado pelo usuário

	if (pilha -> valores == NULL){
		free(pilha);
		pilha = NULL;
		return pilha;
	}

	pilha -> topo1 = -1; //A pilha começará vazia
	pilha -> topo2 = qtdMax - 1;
	pilha -> qtdMax = tamanho; //A quantidade máxima de valores na pilha será igual ao tamanho dado pelo usuário
	pilha -> qtdAtual = 0; //A quantidade atual de valores é igual a 0

	return pilha;
}

int push1 (PilhaDupla* pilha){

	if ((pilha == NULL) || (pilha -> valores == NULL)){ //Caso algo na pilha não esteja alocado devidamente a função retorna 0
		return 0;
	}

	if ((pilha -> topo1 + 1) == (pilha -> topo2)){ //Caso a pilha esteja cheia a função retorna 0
		return 0;
	}

	pilha -> topo++; //Novo topo da pilha: uma posição acima do topo anterior
	pilha -> qtdAtual++; //Incrementando também a quantidade atual de valores na pilha
	pilha -> valores[pilha -> topo1] = valor; //Inserindo valor ao topo da pilha

	return 1;
}

int push2 (PilhaDupla* pilha){

	if ((pilha == NULL) || (pilha -> valores == NULL)){ //Caso algo na pilha não esteja alocado devidamente a função retorna 0
		return 0;
	}

	if ((pilha -> topo2 - 1) == (pilha -> topo1)){ //Caso a pilha esteja cheia a função retorna 0
		return 0;
	}

	pilha -> topo2--; //Novo topo da pilha: uma posição acima do topo anterior
	pilha -> qtdAtual++; //Incrementando também a quantidade atual de valores na pilha
	pilha -> valores[pilha -> topo2] = valor; //Inserindo valor ao topo da pilha

	return 1;
}

int pop1 (PilhaDupla* pilha){

	if ((pilha == NULL) || (pilha -> valores == NULL)){ //Caso algo na pilha não esteja alocado devidamente a função retorna -1
		return -1;
	}

	if (pilha -> topo1 == -1){ //Caso a pilha esteja vazia a função retorna -1
		return -1;
	}

	pilha -> topo1--; //Decrementando o topo para eliminar a posição que contém o valor a ser removido
	pilha -> qtdAtual--; //Decrementando a quantidade atual de valores na pilha
	return pilha -> valores[pilha -> topo1 + 1]; //A função retorna ao usuário o valor que foi removido
}

int pop2 (PilhaDupla* pilha){

	if ((pilha == NULL) || (pilha -> valores == NULL)){ //Caso algo na pilha não esteja alocado devidamente a função retorna -1
		return -1;
	}

	if (pilha -> topo1 == -1){ //Caso a pilha esteja vazia a função retorna -1
		return -1;
	}

	pilha -> topo2++; //Decrementando o topo para eliminar a posição que contém o valor a ser removido
	pilha -> qtdAtual--; //Decrementando a quantidade atual de valores na pilha
	return pilha -> valores[pilha -> topo2 - 1]; //A função retorna ao usuário o valor que foi removido
}

void printaPilha (PilhaDupla* pilha){ //Função que printa a pilha

	if ((pilha == NULL) || (pilha -> valores == NULL)){ //Checando se a pilha está alocada devidamente
		return; //Caso contrário a função aborta
	}

	if (pilha -> topo == -1){
		return; //Caso a pilha esteja vazia a função também aborta
	}

	printf("Pilha 1 = ");
	for (int i = 0; i <= (pilha -> topo1); i++){ //Laço que percorrerá a pilha da base até o topo
		printf("%i ", pilha -> valores[i]); //Printando cada posição da pilha
	}

	printf("\n\n");

	printf("Pilha 2 = ");
	for (int i = qtdMax - 1; i >= (pilha -> topo2); i--){ //Laço que percorrerá a pilha da base até o topo
		printf("%i ", pilha -> valores[i]); //Printando cada posição da pilha
	}

	printf("\n\n");

	return;
}

int destroiPilha (PilhaDupla** pilha){ //Função responsável por destruir a pilha (desalocar)

	PilhaDupla* aux = *pilha; //Criando um ponteiro aux do tipo Pilha que apontará para *pilha

	if ((aux == NULL) || (aux -> valores == NULL)){ //Caso algum membro da estrutura do tipo Pilha já esteja desalocado a função retorna 0
		return 0;
	}

	free(aux -> valores); //Desalocando o vetor que representa a pilha
	aux -> valores = NULL; //Apontando o ponteiro do mesmo á NULL
	free(aux); //Desalocando a estrutura do tipo Pilha em si
	aux = NULL; //Apontando o ponteiro local aux á NULL
	*pilha = NULL; //Apontando o ponteiro dado pelo parâmetro da função á NULL

	return 1;
}