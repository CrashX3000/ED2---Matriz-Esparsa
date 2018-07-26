/*
 ============================================================================
 Atividade autoinstrucional
 Estrutura de Dados 2 - 4NA
 Name        : matriz.c
 Author      : Arleen Silva
 			  Fernando Thales
             Gabriel Nassif
             
 ============================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include "matriz.h"

//Cria a matriz inicializando os atributos com o valor default
void criaMatriz(MATRIZ *matriz){
	matriz->nLinhas = 0;
	matriz->nColunas = 0;
	matriz->linha = NULL;
	matriz->coluna = NULL;
}

//Inicializa a matriz com o número de linhas e colunas
void inicializaMatriz (MATRIZ *a, int linhas, int colunas){
	int i;
	LISTA *tmp;
	
	//Cria os vetores do tipo listas e colunas com o tamanho informado
	LISTA *vetLinhas = (LISTA*)malloc(sizeof(LISTA)*linhas);
	LISTA *vetColunas = (LISTA*)malloc(sizeof(LISTA)*colunas);

	
	//Inicializa o vetor de linhas
	tmp = vetLinhas;
	for (i = 0; i < linhas; i++){
		criaLista(tmp);
		tmp++; 
	}
	
	//Inicializa o vetor de colunas
	tmp = vetColunas;
	for (i = 0; i < colunas; i++){
		criaLista(tmp);
		tmp++;
	}
	
	//Atualiza os endereços das linhas e colunas da matriz
	a->linha = vetLinhas;
	a->coluna = vetColunas;
	
	//Atualiza o número de linhas e colunas da matriz
	a->nLinhas = linhas;
	a->nColunas = colunas;
	
}

//Cria a lista criando uma célula cabeçalho e setando os ponteiros para NULL
void criaLista(LISTA *lista){ 
	lista->primeiro = (PONT)malloc(sizeof(CELULA)); 
	lista->ultimo = lista->primeiro;
	lista->primeiro->abaixo = NULL;
	lista->primeiro->direita = NULL;
}


//Insere um valor na matriz a partir de uma linha e coluna
void insereMatriz(MATRIZ *a,int linha,int coluna, double valor){
	CELULA *aux = (PONT)malloc(sizeof(CELULA));
	LISTA *tmp;
	int i, j;

	//Inicializ a item
	aux->item.linha = linha; 
	aux->item.coluna = coluna;
	aux->item.valor = valor;
	aux->direita = NULL;
	aux->abaixo = NULL;
	
	//Acessa a lista certa da linha e chama o método para inserção na lista de linha
	tmp = a->linha;
	for (i = 1; i < linha; i++){
		tmp++;
	}
	insereLinha(tmp, aux);
	
	//Acessa a lista certa da coluna e chama o método para inserção na lista de coluna
	tmp = a->coluna;
	for (i = 1; i < coluna; i++){
		tmp++;
	}
	insereColuna(tmp, aux);
	
	
}


//Metodo para inserção na lista de linha
void insereLinha(LISTA *linha, PONT aux){
	//Verifica se a lista está vazia e coloca na primeira posição
	if (linha->primeiro->direita == NULL){ //O cabeçalho fica no início
		linha->primeiro->direita = aux;
		linha->ultimo = aux;
		return;
	}
	
	//Caso contrário percorre onde deveria ficar
	PONT tmp = linha->primeiro;
	while (tmp->direita != NULL){
		if (aux->item.coluna < tmp->direita->item.coluna){
			aux->direita = tmp->direita;
			tmp->direita = aux;
			return;
		}
		tmp = tmp->direita;
	}
	
	//Se ficar no final da lista
	tmp->direita = aux;
	linha->ultimo = aux;
}


//Metodo para inserção na lista de colunas
void insereColuna(LISTA *coluna, CELULA *aux){
	//Verifica se a lista está vazia e coloca na primeira posição
	if (coluna->primeiro->abaixo == NULL){ //O cabeçalho fica no início
		coluna->primeiro->abaixo = aux;
		coluna->ultimo = aux;
		return;
	}
	
	//Caso contrário percorre onde deveria ficar
	PONT tmp = coluna->primeiro;
	while (tmp->abaixo != NULL){
		if (aux->item.linha < tmp->abaixo->item.linha){
			aux->abaixo = tmp->abaixo;
			tmp->abaixo = aux;
			return;
		}
		tmp = tmp->abaixo;
	}
	
	//Se ficar no final da lista
	tmp->abaixo = aux;
	coluna->ultimo = aux;
}


//Verifica se já existe itens na matriz
int vaziaMatriz(MATRIZ *a){
	LISTA *linha;
	PONT aux;
	int i;
	

	linha = a->linha;
	
//	Percorre as linhas da matriz verificando se elas apontam para algum item. Caso sim, retorna 0
	for (i = 0; i < a->nLinhas; i++){
		
		aux = linha->primeiro->direita;
		
		if (aux != NULL){
			return 0;
		}
		
		linha ++;
	}
//	Se estiver vazia retorna 1
	return 1;
}


void imprimeMatriz(MATRIZ *a){
	int i, j;
	PONT tmpColunas;
	LISTA *tmpLinhas;
	
//	Verifica se a matriz foi inicializada
	if (a->linha == NULL || a->coluna == NULL){ 
		printf("\nMatriz nao foi inicializada\n\n");
		return; 
	}
	

	
 
// 	Aloca a primeira celula
	tmpLinhas = a->linha;
	for (i = 0; i < a->nLinhas; i++){ //Percorre as linhas

	tmpColunas = tmpLinhas->primeiro->direita;
		

		for (j = 0; j < a->nColunas; j++){

			if (tmpColunas == NULL){ //Se a linha estiver vazia
				printf("0.00");
			} else if (j+1 == tmpColunas->item.coluna){ //Se a marcação de coluna coincidir com a do item em questão, ele existe
				printf("%.2lf", tmpColunas->item.valor);
				tmpColunas = tmpColunas->direita;
			} else { //Caso o item não exista
				printf("0.00");
			}
			printf("     ");
			
		}

		printf("\n");
//		Então ele anda com o ponteiro das linhas, indo para a próxima.
		tmpLinhas++;
	}
	printf("\n\n");
}

//Imprime os itens da lista falando quais os itens e sua linha, coluna, e valor. Para verificar se não foi alocado nenhuma célula com valor vazio
void imprimeLinha(MATRIZ *a){
	int i;
	LISTA *lista = a->linha;
	
	for (i = 0; i < a->nLinhas; i++){
		PONT tmp = lista->primeiro->direita;
		while (tmp != NULL){
			printf("Linha: %d; Coluna: %d; Item valor: %.2f\n", tmp->item.linha, tmp->item.coluna, tmp->item.valor);
			tmp = tmp->direita;
		}
		printf("\n");
		lista++;
	}

}


//Lê os dados para uma nova matriz
void leMatriz(MATRIZ *matriz){ 
	int linha, coluna, nLinhas, nColunas;
	double valor;
	
//	Verifica se a matriz já foi inicializada
	if (!vaziaMatriz(matriz)){
		printf("\nMatriz já inicializada.\n");
		return;
	}
	
//	Pega o número de linhas e colunas e inicializa a matriz
	scanf("%d %d", &nLinhas, &nColunas);
	inicializaMatriz(matriz, nLinhas, nColunas);
	
//	Loop para leitura dos valores da matriz enquanto não detectar o valor negativo para quebra do loop
	while (1){
		scanf("%d %d %lf", &linha, &coluna, &valor);
		if (linha < 1) break;
//		Pega os dados e insere na matriz, na posição de linha e coluna com o valor
		insereMatriz(matriz, linha, coluna, valor);
	}
}


//Soma o valor de duas matrizes
void somaMatriz(MATRIZ *a,MATRIZ *b,MATRIZ *c){
	int i, j;
	double valor;
	PONT tmpColunas1, tmpColunas2;
	LISTA *tmpLinhas1, *tmpLinhas2;
	
//	Verifica se as duas matrizes podem ser somadas
	if ((a->nLinhas != b->nLinhas) || (a->nColunas != b->nColunas)){
		printf("\nMatrizes com dimensoes diferentes nao podem ser somadas.\n");
		return;
	}
	
//	Inicializa a matriz de resultado
	inicializaMatriz(c, a->nLinhas, a->nColunas);
	
	tmpLinhas1 = a->linha;
	tmpLinhas2 = b->linha;
	

//	Percorre as linhas e colunas das matrizes somando e adicionando os valores diferentes de zero na nova matriz
	for (i = 0; i < c->nLinhas; i++){

//		Aponta o primeiro elemento de cada linha para fazer a leitura dos dados da linha
		tmpColunas1 = tmpLinhas1->primeiro->direita;
		tmpColunas2 = tmpLinhas2->primeiro->direita;
		
		for (j = 0; j < c->nColunas; j++){
			
			//Faz a soma do valor do campo ij da  nova matriz
			valor = 0;
			
	
			if (tmpColunas1 == NULL && tmpColunas2 == NULL){ //Se os dois campos estiverem vazios
				valor = 0;
			} else if (tmpColunas1 == NULL && (tmpColunas2->item.coluna == j+1)){ //Se apenas uma das matrizes estiver vazia e a outra estiver com um campo NULL
				valor = tmpColunas2->item.valor;
				tmpColunas2 = tmpColunas2->direita;
			} else if (tmpColunas2 == NULL && (tmpColunas1->item.coluna == j+1)){
				valor = tmpColunas1->item.valor;
				tmpColunas1 = tmpColunas1->direita;
			} else if ((tmpColunas1->item.coluna == j+1) && (tmpColunas2->item.coluna == j+1)){ //Se as duas tiverem valor então realiza a soma
				valor = tmpColunas1->item.valor + tmpColunas2->item.valor;
				tmpColunas1 = tmpColunas1->direita;
				tmpColunas2 = tmpColunas2->direita;
			} else if (tmpColunas1 != NULL){ //Se uma das matrizes está com o ponteiro na posição certa, e a outra não está
				if (tmpColunas1->item.coluna == j+1){
					valor = tmpColunas1->item.valor;
					tmpColunas1 = tmpColunas1->direita;
				}
			} else if (tmpColunas2 != NULL){
				if (tmpColunas2->item.coluna == j+1){
					valor = tmpColunas2->item.valor;
					tmpColunas2 = tmpColunas2->direita;
				}
			} else{ //Se não estiver na coluna certa em nunhuma das matrizes
				valor = 0;
			}
			
			
			//Insere na nova matriz apenas se for diferente de 0
			if (valor != 0){
				insereMatriz(c, i+1, j+1, valor);
			}
			
		}
		
//	Anda com o ponteiro de linhas
	tmpLinhas1++;
	tmpLinhas2++;
		
	}

}


//Multiplica duas matrizes
void multiplicaMatriz(MATRIZ *a, MATRIZ *b, MATRIZ *c){
	int i,j, k;
	double valor, valorLinha, valorColuna;
	LISTA *tmpLinhas, *tmpColunas;
	PONT celLinhas, celColunas;
	
//	Verifica se é possível multiplicar as matrizes, onde o número de colunas de A tem que ser igual ao número de linhas de B
	if (a->nColunas != b->nLinhas){
		printf("\nMultiplicacao nao possivel\n");
		return;
	}
	
//	Inicializa a matriz de resultado
	inicializaMatriz(c, a->nLinhas, b->nColunas);
	
//	Aponta os ponteiros de linha de A e colunas de B
	tmpLinhas = a->linha;
	tmpColunas = b->coluna;
	
//	Percorre as linhas
	for (i = 0; i < a->nLinhas; i++){
		
//		Retorna a coluna para a multiplicação de uma nova linha
		tmpColunas = b->coluna;
		
//		Percorre as colunas
		for (j = 0; j < b->nColunas; j++){
			
			celLinhas = tmpLinhas->primeiro->direita;
			celColunas = tmpColunas->primeiro->abaixo;

			
			valor = 0;
			
//			Faz a multiplicação dos itens para a soma da matriz
			for (k = 0; k < a->nColunas; k++){
				
//				Verifica o valor da linha na posição de procura				
				if (celLinhas == NULL){
					valorLinha = 0;
				} else if (celLinhas->item.coluna == k+1){
					valorLinha = celLinhas->item.valor;
					celLinhas = celLinhas->direita;
				} else {
					valorLinha = 0;
				}
				
//				Verifica o valor da coluna na posição de procura
				if (celColunas == NULL){
					valorColuna = 0;
				} else if (celColunas->item.linha == k+1){
					valorColuna = celColunas->item.valor;
					celColunas = celColunas->abaixo;
				} else {
					valorColuna = 0;
				}
				
//				Armazena a multiplicação valor da linha e coluna atuais.
				valor += valorLinha * valorColuna;
				
			}
			
//			Insere na matriz resultado se o resultado for diferente de 0
			if (valor != 0){
				insereMatriz(c, i+1, j+1, valor);
			}
			
//			Anda com o ponteiro da coluna para a multiplicação de novo elemento
			tmpColunas++;

		}
		
//		Anda com o ponteiro da linha para a multiplicação de novo elemento
		tmpLinhas++;
		
		
	}
	
	
}

//Apaga os espaços alocados para uma matriz
void apagaMatriz(MATRIZ *a){
	LISTA *lista;
	PONT cel, aux;	
	int i;
	
//	Percorre a lista de linhas e apaga toda célula alocada para um item
	lista = a->linha;
	for (i = 0; i < a->nLinhas; i++){
		
		cel = lista->primeiro;
		while (cel != NULL){
			aux = cel->direita;
			free(cel);
			cel = aux;
		}
		lista++;
	}
	
//	Apaga as áreas de memória criada para os vetores de lista e coluna
	free(a->linha);
	free(a->coluna);
	
//	Inicializa a matriz com os valores default
	a->linha = NULL;
	a->coluna = NULL;
	a->nLinhas = 0;
	a->nColunas = 0;
}


