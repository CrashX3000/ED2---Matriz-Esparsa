#include <stdlib.h>
#include "lista.h"

void cria(LISTA *lista){
	lista->primeiro = (PONT)malloc(sizeof(CELULA));
	lista->ultimo = lista->primeiro;
	lista->primeiro->abaixo = NULL;
	lista->primeiro->direita = NULL;
}
