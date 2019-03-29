/*
Modifique o TAD dado em sala de aula para armazenar coordenadas (dois valores float). Chame o TAD de polígono. Especifique num .h as funcionalidades desse TAD:

  - criar polígono

  - inseção em ordem dos pontos do polígono

  - imprimir polígono

  - obter tamanho dos lados do polígono

  - obter perímetro do polígono

  - destruir polígono

Depois implemente as função do TAD.



**Analise para as questões anteriores:

 - Quais mudanças seriam necessárias se houvessem alterações no que o TAD está armazenando?

 - O que seria necessário fazer para que as funções de inserção não fossem limitadas para um tamanho fixo?
*/

#ifndef TAD_POLIGONO
#define TAD_POLIGONO
    /**
    TAD_POLIGONO: Tad responsável pelo fornecimento de funções de: criação de um poligono, inserção em ordem dos pontos, impressão,
    obtenção do tamanho, obtenção do perímetro e destruição do mesmo.
    */

    /**Tipo de dado Pontos: tipo de dado responsável pelo armazenamento das coordenadas x e y de cada ponto do poligono*/
    typedef struct _Pontos_ {
        int x;
        int y;
    }Pontos;

    /**Tipo de dado Poligono: tipo de dado responsável pelo armazenamento das características do polígono que o usuario deseja criar*/
    typedef struct _Poligono_ {
        Pontos* poligono; //Vetor do tipo Pontos que armazenará cada ponto do polígono
        int qtdMaxPontos;	//Quantidade maxima de pontos que o poligono poderá ter (tamanho do vetor poligono)
        int qtdAtualPontos;	//Quantidade de pontos existente no vetor poligono atualmente
        int** quadrantes; //Matriz responsavel por tentar simular o poligono
    }Poligono;


    /**
    @criaPoligono(Poligono* polig, int maxPontos);
    @brief prepara o poligono para receber os pontos
    @param polig estrutura que ira receber as informacoes do poligono
    @param maxPontos maximo de pontos que o vetor poligono podera ter
    @return estrutura polig com todos seus elementos alocados ou NULL caso algo nao pode ser alocado
    */
    Poligono* criaPoligono(Poligono* polig, int maxPontos);

    /**
    @insercao(Poligono* polig, int x, int y);
    @brief insere novos pontos ao vetor poligono
    @param polig estrutura do tipo Poligono que ira receber os pontos
    @param x posicao x do ponto
    @param y posicao y do ponto
    @return 1 caso os pontos tenham sido inseridos com sucesso, 0 caso contrario
    */
    int insercao(Poligono* polig, int x, int y);

    /**
    @impressao(Poligono* polig);
    @brief imprime o poligono na tela
    @param polig estrutura do tipo Poligono que contem os dados necessarios para o poligono ser printado
    @return 1 caso o poligono pode ser printado, 0 caso contrario
    */
    int impressao(Poligono* polig);

    /**
    @tamanhoLados(Poligono* polig);
    @brief calcula o tamanho de cada lado do poligono e printa os mesmos na tela para o usuario
    @return 1 caso os lados puderam ser calculados e printados, 0 caso contrario
    */
    int tamanhoLados(Poligono* polig);

    /**
    @perimetroPoligono(Poligono* polig);
    @brief calcula o perimetro do poligono (soma de todos os lados)
    @param polig poligono a ser utilizado no calculo
    @return 1 caso foi possivel calcular o perimetro, 0 caso contrario
    */
    int perimetroPoligono(Poligono* polig);

    /**
    @destroiPoligono(Poligono** polig);
    @brief desaloca todos os membros da estrutura polig, destruindo o poligono por consequencia
    @param polig poligono a ser destruido
    @return 1 caso foi possivel desalocar todos os membros, 0 caso algo na estrutura polig já tivesse sido desalocado anteriormente
    */
    int destroiPoligono(Poligono** polig);

#endif
