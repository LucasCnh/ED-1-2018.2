/*
Questão 5

Uma pilha, como um tipo de dado abstrato, pode armazenar de 0 a infinitos
elementos. Porém, uma implementação de pilha prevê não mais que um certo número
N de elementos. Explique o porquê desse limite, considerando algumas formas de se
implementar uma pilha.
*/

/*
	A pilha limita o número máximo de elementos dependendo de qual estrutura
de dados foi utilizada na implementação, caso a mesma utiliza de um vetor como
representação de seus dados, a mesma se torna limitada ao tamanho N do vetor,
apesar de ser possível a criação de vetores dinâmicos para tal implementação,
 o custo de realocação é muito alto para uma pilha com muitos elementos, já que
para fazer tal operação é necessário deslocar cada posição interando por toda a estrutura
novamente. A mesma lógica vale para a implementação por meio de matrizes. 
	Caso a pilha tenha sido implementada por meio de listas encadeadas a mesma
pode assumir tamanhos infinitos pois se torna menos custoso a alocação de uma nova posição
na mesma, sendo possível fazer apenas referenciando a próxima posição, sem o custo de deslocamento.
*/