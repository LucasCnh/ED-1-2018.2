#include <stdio.h>
#include <stdlib.h>
#include "lista_dupla.h"

//QUESTÃO 2
int concatenandoListas (ListaDupla* l1, ListaDupla* l2){ //Função que concatena duas listas
	
	if (l1 == NULL || l2 == NULL || (l1 -> head == NULL)) return 0; //Caso pelo menos uma das listas ou o rabo da l1 não estejam alocados a função retorna 0

	l1 -> tail -> next = l2 -> head; //O próximo elemento ao rabo de l1 será a cabeça de l2

	if (l2 -> head != NULL){ //Se a cabeça de l2 existir
		l2 -> head -> prev = l1 -> tail; //O valor anterior á cabeça de l2 passa a ser o rabo de l1
		l1 -> tail = l2 -> tail; //O rabo de l1 passa a ser o rabo de l2
		l2 -> head = l1 -> head; //A cabeça de l2 passa a ser a cabeça de l1
	}

	return 1; //A função retorna 1, simbolizando que a concatenação foi um sucesso
}
//

//QUESTÃO 4
int invertendoLista (ListaDupla* l1){ //Função que inverte a lista

	if (l1 == NULL || l1 -> head == NULL) return 0; //Se a lista não estiver alocada ou estiver vazia, a função retorna 0

	Node* aux = l1 -> head; //Ponteiro que percorrerá a lista
	Node* p; //Ponteiro que guardará a referência que será trocada

	l1 -> head = l1 -> tail; //A cabeça passa a ser o rabo
	l1 -> tail = aux; //O rabo passa a ser a cabeça
	l1 -> tail -> prev = l1 -> tail -> next; //Invertendo o primeiro prev com o primeiro next
	l1 -> tail -> next = NULL;
	l1 -> head -> next = l1 -> head -> prev;
	l1 -> head -> prev = NULL;
	
	aux = l1 -> head -> next;  

	while (aux -> next != NULL){ //Aux percorrerá a lista até a última posição invertendo cada prev com cada next (com a ajuda de p)
		p = aux -> next; //p guarda a referência do next
		aux -> next = aux -> prev; //O next passa a ser o prev
		aux -> prev = p; //O prev passa a ser o antigo next
		aux = aux -> next; //Aux continua a percorrer a lista
	}

	return 1; //A função retorna 1, simbolizando que a inversão foi bem-sucedida
}
//

//QUESTÃO 5
int eliminaUltimoElemento (ListaDupla* l){ //Função de nome auto-explicativo

	if (l == NULL || l -> tail == NULL) return -333; //Se a lista não existir ou o rabo não estiver alocado, a função retorna -333

	int dado = l -> tail -> dado; //Variável que guarda o valor da última posição (valor a ser retornado)
	Node* aux = l -> tail; //Variável que guarda a referência para a última posição

	if (l -> tail -> prev != NULL){ //Se a última posição não for a única
		l -> tail = l -> tail -> prev; //A última posição passa a ser a antiga posição anterior
		l -> tail -> next = NULL; //O next da nova última posição passa a ser NULL
	}else{ //Caso seja, a lista passa a ser vazia
		l -> head = NULL; 
		l -> tail = NULL;
	}

	free(aux); //A antiga última posição é desalocada da memória
	return dado; //O dado da mesma é retornado pela função
}
//

//QUESTÃO 6
int removeNelemento (ListaDupla* l, int n){ //Função que remove o n-ésimo elemento, informado pelo usuário, da lista

	if (l == NULL || l -> head == NULL) return 0; //Se a lista não existir, ou a mesma estiver vazia, a função retorna 0

	Node* aux = l -> head; //Ponteiro auxiliar que percorrerá a lista

	for (int i = 0; i < n - 1; i++){ //Enquanto não chegar ao n-ésimo elemento da lista
		if (aux == NULL) return -333; //Se aux encontrar o fim, a função imediatamente retorna -333
		aux = aux -> next; //aux continua percorrendo
	}

	int dado = aux -> dado; //Variável auxiliar que guardará o valor do nó encontrado

	if (aux -> prev != NULL){ //Se aux não for o primeiro da lista
		aux -> prev -> next = aux -> next; //O valor posterior do anterior á aux passa a ser o valor posterior á aux
	}else{ //Caso aux seja o primeiro da lista
		l -> head = l -> head -> next; //A cabeça da lista passa a ser o próximo elemento
		if (l -> head != NULL){ //Se a nova cabeça existir
			l -> head -> prev = NULL; //O prev da nova cabeça passa a ser NULL
		}else{ //Caso a nova cabeça não exista
			l -> tail = NULL; //O rabo passa a não existir, representando assim, a lista vazia
		}
	}
	
	if (aux -> next != NULL){ //Se aux não for o último da lista
		aux -> next -> prev = aux -> prev; //O valor anterior do posterior á aux passa a ser o valor anterior á aux
	}else{
		l -> tail = aux -> prev;
		aux -> prev -> next = NULL; 
	}

	free(aux); //O nó encontrado é removido da memória
	return dado; //O valor encontrado é retornado
}
//

//QUESTÃO 7 e 12
int ordenaLista (ListaDupla* l){ //Função que ordena uma lista

	if (l == NULL) return 0; //Se a lista não existir, a função retorna 0

	Node* p = l -> head; //Ponteiros que percorrerão a lista
	Node* p1;
	int aux; //Variável que auxiliará a troca

	while (p != NULL){ //Enquanto p não chegar ao fim da lista
		p1 = p -> next; //p1 iniciará do nó posterior á p
		while (p1 != NULL){ //Enquanto p1 não chegar ao fim da lista
			if (p1 -> dado < p -> dado){ //Se o valor de p1 for menor que o de p2, os valores dos mesmos são trocados
				aux = p1 -> dado;
				p1 -> dado = p -> dado;
				p -> dado = aux;
			}
			p1 = p1 -> next; //p1 continua a percorrer a lista
		}
		p = p -> next; //p continua a percorrer a lista
	}

	return 1; //A função retorna 1, simbolizando que a ordenação foi um sucesso
}

ListaDupla* juntaEordena (ListaDupla* l, ListaDupla* l1){ //Função que concatena duas listas ordenadas e ordena a lista resultante

	if (l == NULL || l1 == NULL) return NULL;

	ListaDupla* n = criaListaDupla();
	Node* aux = l -> head;

	while (aux != NULL){
		insercaoListaDupla(n, aux -> dado);
		aux = aux -> next;
	}

	aux = l1 -> head;

	while (aux != NULL){
		insercaoListaDupla(n, aux -> dado);
		aux = aux -> next;
	}

	Node* p = n -> head;
	Node* p1;
	int temp;

	while (p != NULL){
		p1 = p -> next;
		while (p1 != NULL){
			if (p1 -> dado < p -> dado){
				temp = p1 -> dado;
				p1 -> dado = p -> dado;
				p -> dado = temp;
			}

			p1 = p1 -> next;
		}
		p = p -> next;
	}

	return n;
}
//

//QUESTÃO 8 e 9
int busca (ListaDupla* l, int valor){ //Função que busca dado valor dentro de uma lista

	if (l == NULL) return 0; //Se a lista não existir, a função retorna 0

	Node* aux = l -> head; //Ponteiro auxiliar que percorrerá a lista

	while (aux != NULL){ //Enquanto o nó não encontrar a última posição
		if (aux -> dado == valor){ //Se o valor dado existir na lista
			return 1; //A função retorna 1, simbolizando que o valor foi encontrado
		}

		aux = aux -> next; //O ponteiro continua percorrendo, caso o valor não seja este
	}

	return 0; //A função retorna 0, simbolizando que aux chegou ao fim e o valor não foi encontrado
}

int uniao (ListaDupla* l, ListaDupla* l2){ //Função que realiza a operação de união entre duas listas

	if (l == NULL || l2 == NULL) return 0; //Caso uma das duas listas não existir, a função retorna 0

	Node* aux = l2 -> head; //Ponteiro auxiliar que percorrerá a lista 2

	while (aux != NULL){ //Enquanto não chegar ao fim da lista 2
		if (!(busca(l, aux -> dado))){ //Se o valor atual de l2 não existir em l
			insercaoListaDupla(l, aux -> dado); //O valor do nó de l2 é inserido em l
		} 

		aux = aux -> next; //Aux continua percorrendo l2
	}

	return 1; //A função retorna 1, simbolizando que a união foi realizada
}

int intersecao (ListaDupla* l, ListaDupla* l2){ //Função que realiza a operação de interseção entre duas listas

	if (l == NULL || l2 == NULL) return 0; //Caso uma das duas listas não existir, a função retorna 0

	Node* aux = l -> head; //Ponteiro auxiliar que percorrerá a lista 2
	int dado; //Variável que guardará o valor atual do nó

	while (aux != NULL){
		if (!(busca(l2, aux -> dado))){ //Se o valor atual de l não existir em l2
			dado = aux -> dado; //A valor encontrado é guardado
			aux = aux -> next; //aux passa para o próximo nó
			removeListaDupla(l, dado); //O nó do valor encontrado é removido
			continue; //O laço pula para a próxima iteração
		}

		aux = aux -> next; //aux continua a percorrer l
	}

	return 1; //A função retorna 1, simbolizando que a intersecao foi realizada
}
//

//QUESTÃO 10
int inserirElementoDepoisDoN (ListaDupla* l, int valor, int nes){ //Função que insere um elemento após um dado n-ésimo nó da lista

	if (l == NULL || nes <= 0) return 0; //Caso a lista não exista, ou o usuário tenha informado uma n-ésima posição inválida, a função retorna 0

	Node* aux = l -> head; //Ponteiro auxiliar que percorrerá a lista

	if (aux == NULL){ //Se a lista estiver vazia
		return insercaoListaDupla(l, valor); //Insere o novo nó como o primeiro
	}

	for (int i = 0; i < nes - 1; i++){ //Enquanto não encontrar o n-ésimo nó ou chegar ao fim da lista
		if (aux -> next == NULL) break; //Caso aux chegue ao fim da lista, o laço é quebrado
		aux = aux -> next; //aux continua a percorrer a lista
	}

	Node* n = (Node*) malloc(sizeof(Node)); //Alocando o novo nó

	if (n == NULL) return 0; //Caso o novo nó não puder ser alocado, a função retorna 0

	if (aux -> next == NULL){ //Caso aux seja o último nó
		n -> prev = aux; //O antigo último passa a ser o penúltimo
		n -> next = NULL; //O próximo nó ao novo não existirá
		n -> prev -> next = n; //O próximo nó ao antigo último passa a ser o novo nó
		l -> tail = n; //O novo nó passará a ser o último
		n -> dado = valor; //O valor dado pelo usuário é atribuído ao novo nó
		return 1; //A função retorna 1, simbolizando que a inserção foi um sucesso
	}

	n -> next = aux -> next; //O próximo nó ao novo nó é o antigo próximo do n-ésimo nó
	n -> prev = aux; //O nó anterior ao novo nó é o antigo n-ésimo nó
	n -> next -> prev = n -> prev -> next = n; //Estabelecendo as referências dos nós adjacentes ao novo nó
	n -> dado = valor; //O valor dado pelo usuário é atribuído ao novo nó
	return 1; //A função retorna 1, simbolizando que a inserção foi um sucesso
}
//

//QUESTÃO 11
int eliminaCadaSegundoElemento (ListaDupla* l){ //Função que elimina o segundo elemento de uma lista

	if (l == NULL || l -> head == NULL) return 0; //Se a lista não existir ou estiver vazia, a função retorna 0

	Node* aux = l -> head; //No auxiliar que percorrerá a lista
	Node* p;//Nó auxiliar que guardará o nó a ser removido

	if (aux == NULL) return 0; //Se o segundo nó não existir, a função retorna 0

	while (aux != NULL && aux -> next != NULL){

		aux = aux -> next;

		aux -> prev -> next = aux -> next; //O novo segundo nó será o posterior ao antigo segundo
		if (aux -> next != NULL){
			aux -> next -> prev = aux -> prev;
		}

		if (aux -> next == NULL){
			l -> tail = aux -> prev;
		}

		if (l -> head -> next == NULL){ //Se a lista tiver apenas um elemento
			l -> tail = l -> head; //O rabo passa a ser a cabeça
		}

		p = aux;
		aux = aux -> next;
		free(p); //O segundo nó da lista é desalocado
	}
	
	return 1; //A função retorna 1, simbolizando que a mesma foi bem-sucedida
}
//

//QUESTÃO 13
int retornaSomadeInteirosLista (ListaDupla* l){ //Função que retorna a soma dos inteiros de uma lista

	if (l == NULL) return 0; //Se a lista estiver vazia, a função retorna 0 

	Node* aux = l -> head; //Ponteiro auxiliar que percorrerá a lista
	int sum = 0; //Variável retorno que guardará a soma dos inteiros da lista

	while (aux != NULL){ //Enquanto aux não chegar á última posição
		sum += aux -> dado; //O valor do nó atual é somado á soma
		aux = aux -> next; //Aux continua a percorrer a lista
	}

	return sum; //A soma calculada é retornada ao usuário
}
//

//QUESTÃO 14
int retornaNumElementos (ListaDupla* l){ //Função que retorna o número de elementos de uma lista

	if (l == NULL) return -1; //Se a lista não existir, a função retorna -1

	Node* aux = l -> head; //Ponteiro que percorrerá a lista
	int n = 0; //Variável que representará a qtd de nós da lista

	while (aux != NULL){ //Enquanto aux não chegar á última posição
		n++; //A qtd de nós é incrementada
		aux = aux -> next; //aux continua a percorrer a lista
	}

	return n; //A quantidade de nós é retornada pela função
}
//

//QUESTÃO 15
int deslocaNoPNposaFrente (ListaDupla* l, int pos, int n){ //Função que desloca um nó p n posições á frente

	if (l == NULL || l -> head == NULL) return 0; //Caso a lista não exista ou esteja vazia, a função retorna 0

	Node* p = l -> head; //O ponteiro auxiliar que guardará o nó a ser deslocado
	Node* d = l -> head; //O ponteiro auxiliar que representa o destino do nó a ser deslocado

	for (int i = 0; i < pos - 1; i++){ //laço que auxiliará a encontrar o nó preterido pelo usuário
		p = p -> next; //p e d continuarão percorrendo a lista
		d = d -> next; 
		if (p == NULL) break; //Se p chegou ao fim (a posição dada é maior que o tamanho da lista), o laço quebra
	}

	if (p == NULL || p -> next == NULL) return 0; //Caso a posição dada seja maior que o tamanho da lista ou o nó encontrado seja o último, a função retorna 0

	for (int i = 0; i < n; i++){ //Enquanto não encontrar o nó que será o anterior ao nó a ser deslocado
		d = d -> next; //d segue percorrendo a lista
		if (d -> next == NULL) break; //Caso d venha a ser o último da lista, o laço quebra
	}

	//p será deslocado para depois de d se n for maior que 0

	if (n <= 0) return 0;

	if (p -> prev == NULL){ //Se p for o primeiro da lista
		l -> head = l -> head -> next; //A cabeça da lista passa a ser o próximo nó
		l -> head -> prev = NULL; //O prev da cabeça passa a apontar a NULL
	}else{
		p -> prev -> next = p -> next;
		p -> next -> prev = p -> prev;
	}

	if (d -> next == NULL){ //Se d for o último nó da lista
		d -> next = p; //O próximo á d passa a ser p
		p -> prev = d; //O anterior á p passa a ser d
		p -> next = NULL; //O next de p passa a apontar á NULL
		l -> tail = p; //O rabo da lista passa a ser p
	}else{
		p -> next = d -> next; //O próximo á p passa a ser o próximo á d
		p -> prev = d; //O anterior á p passa a ser d
		p -> next -> prev = d -> next = p; //O anterior ao nó posterior á p passa a ser p e o posterior á d passa a ser p
	}

	return 1; //A função retorna 1, simbolizando que o deslocamento foi um sucesso
}
//

//QUESTÃO 16
ListaDupla* copiaLista (ListaDupla* l){ //Função que cria uma cópia de uma lista

	if (l == NULL) return NULL; //Se a lista estiver vazia, a função retorna NULL

	ListaDupla* ret = criaListaDupla(); //Lista auxiliar que será o retorno
	Node* p = l -> head; //Ponteiro auxiliar que percorrerá cada nó da lista á ser copiada

	if (ret == NULL) return NULL;

	while (p != NULL){ //Enquanto p não percorrer até o fim da lista
		insercaoListaDupla(ret, p -> dado); //Insere um nó equivalente ao atual na lista retorno
		p = p -> next; //p segue percorrendo a lista
	}

	return ret; //Retornando a lista copiada
}
//