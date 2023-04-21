#pragma once
#ifndef __FILA_h__
#define __FILA_h__

#define N_FILA 100

struct fila{
	int n;
	int ini;
	float vet[N_FILA];
};

typedef struct lista_f{
	int info;
	struct lista_f *prox;
} Lista_f;

struct filal{
	Lista_f *ini;
	Lista_f *fim;
};



typedef struct fila Fila;
typedef struct filal FilaL;


Fila *fila_cria_vet();
void fila_insere_vet(Fila *f, float v);
float fila_retira_vet(Fila *f);
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