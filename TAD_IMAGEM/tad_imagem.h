/*
5) escreva um TAD genérico Imagem. 
Esse TAD armazena Pixels numa matriz. 
Cada pixel pode ter um tipo diferente, 
o mais comum é que seja RGC (vetor de char de 3 posiçoes), 
mas pode ser de qualquer tipo. 
Cada pixel possui ainda uma coordenada dentro da imagem. Implemente as funções:

 - construir (vc decide como receber os pixels)

 - get1Pixel (recebendo a coordenada desejada)

 - set1Pixel (recebendo a coordenada desejada e o valor para atualizar)

 - getRect (recebendo a coordenada do ponto mais superior e a esquerda desejado, a largura e comprimento. Deve retornar um TAD Imagem com a região solicitada da imagem)
*/

#ifndef TAD_IMAGEM
#define TAD_IMAGEM

/**
@TAD_IMAGEM tad criado para criar imagens a partir de pixels
*/

typedef int (*Comparar) (void* a, void* b); //Funcao que compara valores genericos

typedef _Pixel_ { //Estrutura que armazenara a informacao de cada pixel 
	char* RGC; //Vetor RGC que armazenara as tonalidades do pixel
	void* x; //Posicao x do pixel
	void* y; //Posicao y do pixel
	Comparar comp;
}Pixel;

typedef _Imagem_ { //Estrutura que guardara as informacoes para a imagem ser printada
	Pixel* pixels; //Pixels
	int** plano; //Matriz que sera usada pra printar a imagem
	int qtdMaxPixels; //Quantidade maxima de pixels (tamanho do vetor pixels)
	int qtdAtualPixels; //Quantidade atual de pixels armazenados
}Imagem;

/**
@construir (int max)
@brief aloca cada elemento da estrutura imagem assim como a mesma
@param max maximo de pixels a serem armazenados
@return imagem alocada e pronta para insercao de dados
*/
Imagem* construir (int max, Comparar c);

/**
@get1Pixel (void* x, void* y, char* RGC)
@brief insere um novo pixel na imagem
@param img imagem que recebera os pontos
@param x coordenada x dada pelo usuario
@param y coordenada y dada pelo usuario
@param RGC tonalidades do pixel
@return 1 caso o pixel pode ser inserido, 0 caso contrario
*/
int get1Pixel (Imagem* img, void* x, void* y, char* RGC);

/**
@set1Pixel (void* xAtual, void* yAtual, void* x, void* y)
@brief atualiza a posicao x e y de um dos pixels
@param img imagem que recebera os pontos
@param xAtual coordenada x a ser modificada de um dos pixels
@param yAtual coordenada y a ser modificada de um dos pixels
@param x coordenada x atualizada
@param y coordenada y atualizada
@return 1 caso se pode atualizar, 0 caso contrario
*/
int set1Pixel (Imagem* img, void* xAtual, void* yAtual, void* x, void* y);

/**
@getRect(void* x, void* y, int largura, int comprimento)
@brief especifica um retangulo com as caracteristicas dadas pelo usuario
@param x coordenada x do ponto de inicio
@param y coordenada y do ponto de inicio
@param largura do retangulo desejado
@param comprimento do retangulo desejado
@return TAD imagem com o retangulo especificado caso o NULL caso contrario
*/
Imagem* getRect (void* x, void* y, int largura, int comprimento);

/**
@printaImagem (Imagem* img)
@brief printa a forma que esta armazenada no TAD imagem
@param img imagem a ser printada
*/
void printaImagem (Imagem* img);

/**
@int destroiImagem (Imagem** img)
@brief destroi a imagem desalocando cada um de seus membros assim como a propria estrutura do tipo Imagem
@param img imagem a ser destruida
@return 1 caso a destruicao tenha sido um sucesso, 0 caso contrario
*/
int destroiImagem (Imagem** img);

#endif