/*
 ============================================================================
 Atividade autoinstrucional
 Estrutura de Dados 2 - 4NA
 Name        : matriz.h
 Author      : Arleen Silva
 			  Fernando Thales
             Gabriel Nassif
             
 ============================================================================
 */
 
#if !defined(MATRIZ_H)
#define MATRIZ_H

#include "lista.h"

typedef struct {
  int nLinhas, nColunas;
  LISTA *linha;
  LISTA *coluna;
} MATRIZ;

void criaMatriz(MATRIZ*);
void inicializaMatriz (MATRIZ*, int, int);
void insereMatriz(MATRIZ*,int,int,double);
void testeInsere(LISTA*, PONT);
int  vaziaMatriz(MATRIZ*);
void leMatriz(MATRIZ*);
void somaMatriz(MATRIZ*,MATRIZ*,MATRIZ*);
void multiplicaMatriz(MATRIZ*,MATRIZ*,MATRIZ*);
void imprimeMatriz(MATRIZ*);
void apagaMatriz(MATRIZ*);
void imprimeLinha(MATRIZ*);

#endif
