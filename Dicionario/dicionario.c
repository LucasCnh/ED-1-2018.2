#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dicionario.h"

Dicionario* criaDicionario (void){ //Função que cria uma nova lista de palavras (vazia)

	Dicionario* d = (Dicionario*) malloc(sizeof(Dicionario));

	if (d == NULL) return d; //Se o dicionário não puder ser alocado, a função retorna NULL

	File* a = fopen("dicionario.txt", "r");

	while (a != EOF){
		inserePalavra(d, fgets(a));
	}

	//O dicionário começa vazio
	d -> head = d -> tail = NULL;

	return d; //A função retorna o dicionário
}
	
int inserePalavra (Dicionario* d, char* palavra){ //Função que insere uma nova palavra ao dicionário

	if (d == NULL) return 0; //Se o dicionário não existir, a função retorna 0

	Palavra* aux = d -> head; //Ponteiro que percorre o dicionário para checar se a palavra já existe
 
	while (aux != NULL){ //Enquanto aux não chegar ao fim do dicionário
		if ((strcmp(aux -> palavra, palavra)) == 0) return 0; //Se a palavra a ser adicionada for encontrada no dicionário, a função retorna 0
		aux = aux -> next; //Caso contrário, aux continua percorrendo
	}

	Palavra* p = (Palavra*) malloc(sizeof(Palavra));

	if (p == NULL) return 0; //Se a nova palavra não puder ser alocada, a função retorna 0

	p -> next = p -> prev = NULL; //A palavra se inicia sem anteriores ou posteriores
	p -> head = p -> tail = NULL; //A palavra se inicia sem sinonimos
	p -> palavra = (char*) malloc(1000);
	p -> vezesUsada = 0;

	if (p -> palavra == NULL){ //Caso o vetor palavra não puder ser alocado, a função elimina a estrutura p e retorna 0
		free(p);
		return 0;
	}

	strcpy(p -> palavra, palavra);

	if (d -> head == NULL){ //Caso o dicionário esteja vazio, a nova palavra será a primeira
		d -> head = d -> tail = p;
		return 1;
	}

	//Caso o dicionário não esteja vazio, a nova palavra será inserida no fim do mesmo (tail)
	d -> tail -> next = p;
	p -> prev = d -> tail;
	d -> tail = p;
	return 1;
}

int relacionaSinonimo (char* p1, char* p2, Dicionario* d){ //Função que relaciona duas palavras como sinônimos

	if (d == NULL) return 0; 

	Palavra* p = d -> head; //Ponteiro que percorrerá o dicionário e guardará o endereço do nó onde p1 foi encontrado
	Palavra* a = d -> head; //Ponteiro que percorrerá o dicionário e guardará o endereço do nó onde p2 foi encontrado

	while (p != NULL){ //Percorrendo o dicionário á procura de p1
		if ((strcmp(p -> palavra, p1)) == 0) break; //Se p1 foi encontrado, guarda seu endereço
		p = p -> next; //Caso contrário, continua percorrendo
	}

	if (p == NULL) return 0; 

	Sinonimo* aux = p -> head; //Ponteiro que irá percorrer entre os sinonimos de p

	while (aux != NULL){ //Percorrendo os sinônimos de p1 á procura de p2
		if ((strcmp(aux -> p -> palavra, p2)) == 0) return 0; //Caso p2 já seja sinônimo de p1, a função retorna 0
		aux = aux -> next; //Caso contrário, continua percorrendo
	}

	while (a != NULL){ //Percorrendo o dicionário á procura de p2
		if ((strcmp(a -> palavra, p2)) == 0) break; //Se p2 foi encontrado, guarda seu endereço
		a = a -> next; //Caso contrário, continua percorrendo
	}

	if (a == NULL) return 0;

	Sinonimo* s = (Sinonimo*) malloc(sizeof(Sinonimo));
	Sinonimo* s2 = (Sinonimo*) malloc(sizeof(Sinonimo));

	if (s == NULL || s2 == NULL) return 0;

	s -> next = s -> prev = NULL;
	s -> p = a;

	s2 -> next = s2 -> prev = NULL;
	s2 -> p = p;
	
	//Inserindo sinonimo em p1 e p2
	if (p -> head == NULL){
		p -> head = p -> tail = s;
	}else{
		p -> tail -> next = s;
		s -> prev = p -> tail;
		p -> tail = s;
	}

	if (a -> head == NULL){
		a -> head = a -> tail = s2;
	}else{
		a -> tail -> next = s2;
		s2 -> prev = a -> tail;
		a -> tail = s2;
	}

	return 1;	
}

void printaDicionario (Dicionario* d){

	if (d == NULL) return;

	Palavra* p = d -> head;
	Sinonimo* s;

	while (p != NULL){
		s = p -> head;
		printf("Palavra: %s| Vezes usada: %i\n", p -> palavra, p -> vezesUsada);
		printf("Sinonimos: ");
		while (s != NULL){
			printf("%s| ", s -> p -> palavra);
			s = s -> next;
		}
		printf("\n\n");
		p = p -> next;
	}

	return;
}

int destroiDicionario (Dicionario** d){ //Função que destroi um dicionário

	if (*d == NULL) return 0;

	Dicionario* dic = *d;
	Palavra* p = dic -> head;
	Palavra* aux;
	Sinonimo* s;
	Sinonimo* temp;

	while (p != NULL){
		s = p -> head;
		while (s != NULL){
			temp = s;
			s = s -> next;
			free(temp);
		}
		aux = p;
		p = p -> next;
		free(aux -> palavra);
		free(aux);
	}

	free(dic);
	*d = NULL;
	return 1;
}

void trocaTexto (char* texto, Dicionario* d){ //Função que trocará cada palavra de um texto por seus sinônimos
	
	if (d == NULL || texto == NULL) return;

	char* tRetorno = (char*) malloc(100000); //String que guardará o novo texto
	if (tRetorno == NULL) return; 

	char* palavra = (char*) malloc(10000); //String que guardará palavra por palavra
	int prim = 1; //Flag pra identificar que a primeira palavra está sendo lida
	int j = 0;

	for (int i = 0; i < strlen(texto); i++){
		if ((texto[i] != ' ') && (i < strlen(texto))){ //Se foi encontrada um espaço em branco ou é o fim do texto, a palavra deixa de ser lida
			palavra[j] = texto[i];
			j++;
		}else{
			palavra[j] = '\0';
			if (prim == 1){ //Se for a primeira palavra do texto, é realizado strcpy com tRetorno
				strcpy(tRetorno, procuraEtroca(palavra, d));
				strcat(tRetorno, " ");
				prim = 0;
			}else{ //Caso contrário é realizado strcat
				strcat(tRetorno, procuraEtroca(palavra, d));
				strcat(tRetorno, " ");
			}
			j = 0;
		}

	}

	printf("--------------------------Texto modificado--------------------------------\n\n");
	printf("%s\n", tRetorno);
	printf("--------------------------------------------------------------------------\n");
	free(tRetorno);
	free(palavra);

	return;
}

char* procuraEtroca (char* palavra, Dicionario* d){

	Palavra* p = d -> head; //Ponteiro que percorrerá o dicionário á procura da palavra
	srand(time (NULL));

	if (palavra[0] == '\0') return " "; //Caso a palavra seja um espaço em branco retorna espaço em branco

	while (p != NULL){ //Procurando a palavra no dicionário
		if ((strcmp(p -> palavra, palavra)) == 0) break; //Se a palavra for encontrada, o laço se quebra
		p = p -> next;
	}

	if (p == NULL){
		return palavra; //Se a palavra não existe no dicionário, a palavra original do texto é utilizada
	}

	int encontrou = 0; //Flag que indicará se um sinônimo menos vezes usado do que a palavra em si for encontrado
	Sinonimo* s = p -> head; //Ponteiro que percorrerá os sinônimos
	int menor; //Variável que guardará o valor das palavras menos usadas

	menor = p -> vezesUsada; //Menor se inicia como o numero  de vezes que a palavra original foi utilizada

	while (s != NULL){ //Procurando sinônimos
		if (s -> p -> vezesUsada <= p -> vezesUsada){ //Se encontrou um sinônimo menos vezes usado do que a palavra em si
			if (s -> p -> vezesUsada < menor){ //Se tal sinonimo foi menos vezes usado do que o sinonimo da palavra menos usada até aqui
				menor = s -> p -> vezesUsada; //Menor passa a ser o valor atual do sinônimo
			}
			encontrou = 1; //Flag indicando que encontrou pelo menos um sinônimo
		}
		s = s -> next;
	}

	Dicionario* aux = criaDicionario(); //Criando um dicionário auxiliar para guardar os sinônimos menos usados e realizar o sorteio

	if (encontrou == 0 || aux == NULL){ //Caso não se tenha encontrado sinônimos menos usados que a palavra ou aux não puder ser alocado
		if (aux != NULL) destroiDicionario(&aux); 
		//Utiliza-se a própria palavra, e já que a mesma se encontra no dicionário, incrementa-se o número de vezes que ela foi usada
		p -> vezesUsada++;
		return palavra;
	}

	s = p -> head; //Percorrendo os sinônimos de p de novo á procura dos menos usados (numero de vezes usados iguais)

	while (s != NULL){
		if (s -> p -> vezesUsada == menor){
			inserePalavra(aux, s -> p -> palavra); //Quando os mesmos são encontrados, eles são inseridos no dicionário auxiliar
		}
		s = s -> next;
	}

	//Um sorteio é realizado para decidir qual sinônimo será utilizado
	int seed = rand()%10;
	int i = 0;

	Palavra* t = aux -> head;

	while (i < seed){
		if (t == NULL) t = aux -> head;
		i++;
		t = t -> next;
	}

	if (t == NULL) t = aux -> head;

	strcpy(palavra, t -> palavra);

	s = p -> head;

	//Varrendo de novo a lista de sinonimos de p para encontrar qual foi utilizado
	while (strcmp(s -> p -> palavra, palavra)) s = s -> next;

	s -> p -> vezesUsada++; //Incrementando o número de vezes que o mesmo foi utilizado

	destroiDicionario(&aux);

	return palavra;
}