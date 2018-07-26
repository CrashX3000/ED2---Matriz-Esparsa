/*
 ============================================================================
 Atividade autoinstrucional
 Estrutura de Dados 2 - 4NA
 Name        : lista.h
 Author      : Arleen Silva
 			  Fernando Thales
             Gabriel Nassif
             
 ============================================================================
 */

#if !defined(LISTA_H)
#define LISTA_H

typedef struct CELULA_TAG *PONT;

typedef struct {
   int linha, coluna;
   double valor;
} ITEM;

typedef struct CELULA_TAG {
   ITEM item;
   PONT direita;
   PONT abaixo;
} CELULA;

typedef struct {
   PONT primeiro, ultimo;
} LISTA;


void criaLista(LISTA*); 
void insereLinha(LISTA*,PONT);
void insereColuna(LISTA*,PONT);

#endif
