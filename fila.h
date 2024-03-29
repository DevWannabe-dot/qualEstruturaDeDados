#pragma once
#ifndef __FILA_h__
#define __FILA_h__

#define N_FILA 1000 // (1 <= n <= 1000)

typedef struct fila{
	int n;
	int ini;
	int vet[N_FILA];
} Fila;

typedef struct lista_f{
	int info;
	struct lista_f *prox;
} Lista_f;

typedef struct filal{
	Lista_f *ini;
	Lista_f *fim;
} FilaL;


Fila *fila_cria_vet();
int fila_insere_vet(Fila *f, int v);
int fila_retira_vet(Fila *f);
int fila_vazia_vet(Fila *f);
void fila_libera_vet(Fila *f);

FilaL *fila_cria_l();
int fila_insere_l(FilaL *f, int v);
int fila_retira_l(FilaL* f);
int fila_retira_l_pesquisa(FilaL *f, int query);
int fila_vazia_l(FilaL *f);
void fila_libera_l(FilaL *f);
void fila_imprime_l(FilaL *f);
Lista_f* fila_busca_l(FilaL *fila, int informacao);

#endif