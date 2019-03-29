#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cassino.h"
#include "jogo.h"

void jogo (){

	FILE* arq = fopen("cartas.txt", "r"); //Abrindo o arquivo que possui as informações de cada carta
	int N; //Número de casos

	if (arq == NULL) return; //Se o arquivo não puder ser aberto, a função retorna imediatamente

	Lista* baralho = criaLista(); //Criando um novo baralho

	if (baralho == NULL){ //Se o baralho não puder ser alocado
		fclose(arq); //O arquivo é fechado
		return; //A função imediatamente retorna
	}  

	char* nome = (char*) malloc(200); //Vetor nome que guardará os nomes de carta presentes no arquivo
	int valor; //Inteiro valor que guardará os valores das cartas presentes no arquivo
	char ch; //Caractere ch que será utilizado para ler quebras de linha

	if (nome == NULL){ //Se o nome não puder ser alocado
		destroiLista(&baralho); //O baralho é destruído
		fclose(arq); //O arquivo é fechado
		return; //A função imediatamente retorna
	}

	while (!(feof(arq))){ //Enquanto não chegar ao fim do arquivo
		fscanf(arq, "%i", &valor); //Lê o número da carta
		fgets(nome, 200, arq); //Lê o nome da carta
		//fscanf(arq, "%c", &ch); //Lê a quebra de linha
		push(&baralho, valor, nome); //Insere as informações em um novo nó a ser inserido
	}

	scanf("%i", &N); //Lendo o número de casos
	
	for (int i = 0; i < N; i++){ //Organizando as entradas para cada número de casos
		ordenaLista(&baralho); //Ordenando as cartas do menor valor ao maior
		shuffles(&baralho); //Realizando os embaralhamentos
		printaLista(baralho); //Printando o baralho após os embaralhamentos
	}

	//Ao fim
	free(nome); //Desaloca o vetor nome 
	destroiLista(&baralho); //Destroi o baralho
	fclose(arq); //Fecha o arquivo

	return;
}

void shuffles (Lista** baralho){ //Função que realizará o embaralhamento de acordo com o input do usuário

	if (*baralho == NULL || (*baralho) -> head == NULL) return; //Se o baralho não existir, a função imediatamente retorna

	Shuffle* shuffle = criaShuffle(); //Criando um novo shuffle que guardará os movimentos
	Carta* pointer; //Ponteiro auxiliar que percorrerá o baralho
	Carta* pointer2; //Ponteiro auxiliar que percorrerá o baralho
	Carta* temp = (Carta*) malloc(sizeof(Mov)); //Estrutura temporária que receberá as informações da carta do baralho á ser trocada
	int origem, destino; //Variáveis que guardarão cada movimento

	temp -> terno = (char*) malloc(200); //Alocando o vetor terno da variável auxiliar

	if ((shuffle != NULL) && (temp != NULL) && (temp -> terno != NULL)){ //Se o shuffle, temp e seu terno foram alocados com sucesso
		int* formacaoAtual = (int*) malloc(52*sizeof(int)); //Vetor que guardará as formações após as mudanças
		int repetido; //Variável que checará se há cartas repetidas na formação atual
		int encontrado; //Flag que checa se um destino foi encontrado
		int B; //Número de shuffles

		
		if (formacaoAtual != NULL){ //Se o vetor formação atual puder ser alocado
			
			scanf("%i", &B); //Lendo a quantidade de embaralhamentos que o dealer conhece
			for (int i = 0; i < 52; i++){ //Startando o input do usuário zerado
				formacaoAtual[i] = 0;
			}

			for (int j = 0; j < B; j++){ //Lendo os embaralhamentos e efetuando os mesmos no baralho
				for (int i = 0; i < 52; i++){ //Lendo um embaralhamento específico
					repetido = 1; //Flag starta como true para o primeiro while se efetivar
					while (repetido == 1 || formacaoAtual[i] > 52 || formacaoAtual[i] < 1){ //Enquanto o input atual for inválido
						repetido = 0; //Flag que checa se há repetidos
						scanf("%i", &formacaoAtual[i]); //Lendo uma carta do usuário
						for (int k = 0; k < i; k++){ //Laço que percorre o vetor até a iteração atual
							if (formacaoAtual[k] == formacaoAtual[i]) repetido = 1; //Se encontrar cartas repetidas ao input do usuário, a flag indicará true
						}
					}
				}

				for (int i = 1; i < 53; i++){ //Laço que percorrerá o vetor buscando alterações no shuffle
					if (formacaoAtual[i - 1] != i){ //Se a carta na posição i for diferente da carta da ordenação original
						int valor; //Variável auxiliar para trocar valores
						enqueueShuffle(shuffle, i, formacaoAtual[i - 1]); //Um novo movimento é adicionado á fila de embaralhamentos
						valor = formacaoAtual[i - 1];
						formacaoAtual[i - 1] = i; //O valor do destino volta a ser condizente com a ordenação crescente de valores
						formacaoAtual[valor - 1] = valor; //O movimento é desfeito: o valor da origem volta a ser condizente com a ordenação crescente de valores
					}
				}

				while (shuffle -> prim != NULL){ //Enquanto todos os movimentos não forem realizados

					encontrado = 0; //Flag que checa se as cartas foram trocadas com sucesso
					pointer = (*baralho) -> head; //Startando ponteiro que percorrerá baralho procurando a carta originária
					pointer2 = pointer; //Startando ponteiro que percorrerá o baralho procurando a carta destinatária
					origem = dequeueShuffle(shuffle, &destino); //As informações serão fornecidas a partir de um dequeue da fila que guarda os movimentos
					for (int i = 1; i < 53; i++){ //i servirá como notação da posição da carta no deck
						if (i == origem){ //Se i for igual á posição origem
							for (int j = 1; j < 53; j++){ //j servirá como notação da posição da carta no deck
								if (j == destino){ //Se j for igual á posição destino
									temp -> valor = pointer -> valor; //Trocando as cartas na lista
									strcpy(temp -> terno, pointer -> terno);
									pointer -> valor = pointer2 -> valor;
									strcpy(pointer -> terno, pointer2 -> terno);
									pointer2 -> valor = temp -> valor;
									strcpy(pointer2 -> terno, temp -> terno);
									encontrado = 1; //Flag simbolizando que as cartas foram trocadas
								}

								if (encontrado == 1) break; //Se as cartas já foram trocadas, o laço é interrompido
								pointer2 = pointer2 -> next; //O ponteiro seguirá percorrendo o baralho caso contrário
							}
						}

						if (encontrado == 1) break; //Se as cartas já foram trocadas, o laço é interrompido
						pointer = pointer -> next; //O ponteiro seguirá percorrendo o baralho caso contrário
					}
				}
			}

			if (formacaoAtual != NULL) free(formacaoAtual); //Liberando da memória a formação atual

		}
	}

	if (temp -> terno != NULL) free(temp -> terno); //Desalocando o terno da variável auxiliar
	if (temp != NULL) free(temp); //Desalocando a estrutura auxiliar
	destroiShuffle(&shuffle); //Destruindo o shuffle

}	

Shuffle* criaShuffle (void){ //Função que criará estrutura do tipo Shuffle que guardará os movimentos

	Shuffle* shuffle = (Shuffle*) malloc(sizeof(Shuffle)); //Alocando uma nova estrutura do tipo Shuffle

	if (shuffle == NULL) return shuffle; //Se shuffle não puder ser alocada, a função retorna NULL

	shuffle -> prim = NULL; //A fila se inicia vazia
	shuffle -> ult = NULL;

	return shuffle; //A função retorna a estrutura alocada
}

int enqueueShuffle (Shuffle* shuffle, int origem, int destino){ //Função que insere um novo movimento ao fim da estrutura shuffle

	if (shuffle == NULL) return 0; //Se a estrutura não estiver alocada, a função retorna 0

	Mov* novo = (Mov*) malloc(sizeof(Mov)); //Alocando um novo movimento

	if (novo == NULL) return 0; //Se o novo movimento não puder ser alocado, a função retorna 0

	if (shuffle -> prim == NULL){ //Caso a fila esteja vazia
		shuffle -> prim = novo; //A primeira posição será o novo movimento
		shuffle -> ult = novo; //A última posição será o novo movimento
		shuffle -> ult -> next = NULL; //Setando a próxima posição como NULL
		novo -> origem = origem; //O valor origem da nova posição será igual ao passado como parâmetro
		novo -> destino = destino; //O valor destino da nova posição será igual ao passado como parâmetro
	}else{ //Caso contrário
		shuffle -> ult -> next = novo; //A nova posição será inserida após a última
		shuffle -> ult = novo; //O último passará a ser a nova posição
		novo -> origem = origem; //O valor origem da nova posição será igual ao passado como parâmetro
		novo -> destino = destino; //O valor destino da nova posição será igual ao passado como parâmetro
		shuffle -> ult -> next = NULL; //Setando a próxima posição como NULL
	}
	
	return 1; //A função retorna 1, simbolizando que a inserção foi um sucesso
}

int dequeueShuffle (Shuffle* shuffle, int* ret){ //Função que retorna os valores origem e destino de um movimento

	if (shuffle == NULL || shuffle -> prim == NULL) return -1; //Caso shuffle não exista ou seja igual á NULL, a função retorna -1

	Mov* aux = shuffle -> prim; //Aux recebe a primeira posição da fila

	int origem = aux -> origem; //A variável a ser retornada recebe o valor da origem
	*ret = aux -> destino; //A variável a ser modificada recebe o valor do destino

	shuffle -> prim = shuffle -> prim -> next; //A primeira posição passa a ser a próxima
	free(aux); //O antigo prim é desalocado
	aux = NULL; //A variável aux passa a apontar para NULL

	return origem; //A função retorna o valor da origem e destino
}

int destroiShuffle (Shuffle** shuffle){ //Função que destroi estrutura do tipo Shuffle

	if ((*shuffle) == NULL) return 0; //Se a estrutura shuffle já estiver desalocada, a função retorna 0

	Shuffle* aux = (*shuffle); //Criando variável auxiliar que guardará a fila a ser desalocada
	int temp; //Variável auxiliar a ser usada no dequeue

	while (aux -> prim != NULL){ //Até que a fila esteja vazia
		dequeueShuffle(aux, &temp); //Desaloca a primeira posição da fila
	}

	free(aux); //Desaloca a estrutura em si
	(*shuffle) = NULL; //Atribuindo NULL ao ponteiro passado como parâmetro

	return 1; //A função retorna 1, simbolizando que a destruição foi um sucesso
}
