/*
 ============================================================================
 Atividade autoinstrucional
 Estrutura de Dados 2 - 4NA
 Name        : main.c
 Author      : Arleen Silva
 			  Fernando Thales
             Gabriel Nassif
             
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "matriz.h"

int main(int argc, char *argv[])
{
  MATRIZ a, b, c;
  
  printf("Primeiro grupo de matrizes\n");
  criaMatriz(&a); leMatriz(&a); imprimeMatriz(&a);
  criaMatriz(&b); leMatriz(&b); imprimeMatriz(&b);
  printf("Soma\n");
  criaMatriz(&c); somaMatriz(&a, &b, &c); imprimeMatriz(&c);
  printf("Produto\n");
  apagaMatriz(&c); multiplicaMatriz(&a, &b, &c); imprimeMatriz(&c);

  printf("Segundo grupo de matrizes\n");
  apagaMatriz(&a); apagaMatriz(&b);apagaMatriz(&c);
  leMatriz(&a); imprimeMatriz(&a);  
  leMatriz(&b); imprimeMatriz(&b);
  printf("Soma\n");
  criaMatriz(&c); somaMatriz(&a, &b, &c); imprimeMatriz(&c);
  printf("Produto\n");
  apagaMatriz(&c); multiplicaMatriz(&a, &b, &c); imprimeMatriz(&c);
  
  apagaMatriz(&a);
  apagaMatriz(&b);
  apagaMatriz(&c);
      
  return 0;
}
