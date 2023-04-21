/**
* @file		main.c
* @brief	Resolução do trabalho em dupla para 24/04
* @author	Pedro Henrique Pinto de Oliveira, Raphael Inácio Bicalho de Carvalho
* @date		2023-04-21
*/

// Inclusões
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "fila.h"
#include "pilhas.h"

// Constantes
#define SUCESSO			(0)
/* ------------ */
#define STACK			(203)
#define QUEUE			(204)
#define PRIORITY_QUEUE	(205)
#define NOT_SURE		(106)
#define IMPOSSIBLE		(2023)
/* ------------ */
#define INSERIR			(1)
#define RETIRAR			(2)

// Tipos

// Funções
int qual_estrutura(int cmd, int * x, int n) {
	int i;

	for (i = 0; i < n; i++) {

	}
	
	return IMPOSSIBLE;
}

int main(int argc, char ** argv) {
	int i = 0, n = 0, cmd = 0, * x = NULL;

	do {
		scanf("%d", &n);
		x = (int*) realloc(x, sizeof(int) * n);

		for (i = 0; i < n; i++) {
			scanf("%d %d", &cmd, &x[i]);
			printf("<%d %d>\n", cmd, x[i]);
		}

		switch (qual_estrutura(cmd, x, n)) {
			case STACK:
				printf("stack\n");
				break;
			case QUEUE:
				printf("queue\n");
				break;
			case PRIORITY_QUEUE:
				printf("priority queue\n");
				break;
			case NOT_SURE:
				printf("not sure\n");
				break;
			case IMPOSSIBLE:
				printf("impossible\n");
				break;
		}
	} while (1);
	
	return SUCESSO;
}