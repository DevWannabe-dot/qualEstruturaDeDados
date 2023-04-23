/**
* @file		main.c
* @brief	Resolu��o do trabalho em dupla para 24/04
* @author	Pedro Henrique Pinto de Oliveira, Raphael In�cio Bicalho de Carvalho
* @date		2023-04-21
*/

// Inclus�es
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
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

// Fun��es
int qual_estrutura(int * cmd, int * x, int n) {
	int CODIGO = 0, i;
	FilaL* f = fila_cria_l();
	Pilha_lst* p = pilha_lst_cria();
	Fila* pr = fila_cria_vet();

	// verifica se � fila
	CODIGO += 1;

	for (i = 0; i < n; i++) {
		if (cmd[i] == 1) {
			if (fila_insere_l(f, x[i]) == x[i]) {
				continue;
			}
			else CODIGO -= 1;  break; // se o valor retornado nao for igual ao valor entrado, impossivel ser esta estrutura
		}
		else if (cmd[i] == 2) {
			if (fila_retira_l(f) == x[i]) { // caso o valor retornado for igual ao valor de x da entrada correspondente
				continue;
			}
			else CODIGO -= 1;  break;
		}
	}

	// verifica se � pilha
	CODIGO += 2;

	for (i = 0; i < n; i++) {
		if (cmd[i] == 1) {
			if (pilha_lst_push(p, x[i]) == x[i]) {
				continue;
			}
			else CODIGO -= 2; break;
		}
		else if (cmd[i] == 2) {
			if (pilha_lst_pop(p) == x[i]) {
				continue;
			}
			else CODIGO -= 2; break;
		}
	}
	
	// verifica se � fila de prioridade
	CODIGO += 3;

	for (i = 0; i < n; i++) {
		if (cmd[i] == 1) {
			if (fila_insere_vet(pr, x[i]) == x[i]) {
				continue;
			}
			else CODIGO -= 3; break;
		}
		else if (cmd[i] == 2) {
			if (fila_retira_vet(pr) == x[i]) {
				continue;
			}
			else CODIGO -= 3; break;
		}
	}


	// Libera a memoria
	fila_libera_l(f);
	pilha_lst_libera(p);
	fila_libera_vet(pr);

	// Decide o protocolo de return
	switch (CODIGO) {
		case 0:
			break;
		case 1:
			return QUEUE;
			break;
		case 2:
			return STACK;
			break;
		case 3:
			return PRIORITY_QUEUE;
			break;
		default:
			return NOT_SURE;
			break;
	}

	return IMPOSSIBLE;
}

int main(int argc, char ** argv) {
	int i = 0, n = 0, * cmd = NULL, * x = NULL, leitura;
	char lixo;
	FILE* arq;
	long cursor = 0;

	printf("Leitura por stdin ou arquivo?\n"
			"1 - stdin\n"
			"2 - arquivo\n");
	scanf("%d%c", &leitura, &lixo);

	
	do {
		if (leitura == 1) {
			scanf("%d", &n);

			x = (int*)realloc(x, sizeof(int) * n);
			cmd = (int*)realloc(cmd, sizeof(int) * n); // (resolu��o #1)

			for (i = 0; i < n; i++) {
				scanf("%d %d", &cmd[i], &x[i]);
				// printf("<%d %d>\n", cmd, x[i]);	// verificar leitura apropriada
			}
		}
		else if (leitura == 2) {
			arq = fopen("teste.txt", "r");
			fseek(arq, cursor, SEEK_SET);

			if (arq) {
				if (!feof(arq)) {
					if (fscanf(arq, "%d", &n) == EOF) return SUCESSO;
					printf("%d\n", n);

					x = (int*)realloc(x, sizeof(int) * n);
					cmd = (int*)realloc(cmd, sizeof(int) * n);

					for (i = 0; i < n; i++) {
						fscanf(arq, "%d %d", &cmd[i], &x[i]);
						printf("%d %d\n", cmd[i], x[i]);
						// printf("<%d %d>\n", cmd, x[i]);	// verificar leitura apropriada
					}
					cursor = ftell(arq);
				}
			}
			else {
				fprintf(stderr, "<Impossivel acessar o arquivo de entrada.>\n"); break;
			}
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