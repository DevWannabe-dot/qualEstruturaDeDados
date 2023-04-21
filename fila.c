#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"



static int incr(int i){
	return (i+1)%N_FILA;
}

Fila *fila_cria_vet(){
	Fila *f = (Fila *) malloc(sizeof(Fila));
	f->n = 0;
	f->ini = 0;
	return f;
}

int fila_insere_vet(Fila *f, int v){
	int fim;

	if(f->n == N_FILA){
		printf("Capacidade da fila estourou\n");
		exit(1);
	}
	fim = (f->ini + f->n) % N_FILA;	
	f->vet[fim] = v;
	f->n++;
	return f->vet[fim];
}

int fila_retira_vet(Fila *f){
	int v, fim, prioridade_max = 0;

	if(fila_vazia_vet(f)){
		printf("Fila vazia!\n");
		exit(1);
	}
	fim = (f->ini + f->n) % N_FILA;
	for (int i = 0; i < fim; i++) {
		if (f->vet[i] > f->vet[prioridade_max]) prioridade_max = i;
	}
	v = f->vet[prioridade_max];
	f->vet[prioridade_max] = 0; /* 
	não realiza a remoção apropriada, porém faz com que o maior elemento 
	encontrado seja 0, o que impede que seja removido novamente */
	
	return v;
}

int fila_vazia_vet(Fila *f){
	return (f->n == 0);
}

void fila_libera_vet(Fila *f){
	free(f);
}


// Lista encadeada
FilaL *fila_cria_l(){
	FilaL *f = (FilaL *) malloc(sizeof(FilaL));
	f->ini = f->fim = NULL;
	return f;
}

int fila_insere_l(FilaL *f,int v){
	Lista_f *n = (Lista_f *) malloc(sizeof(Lista_f));
	n->info=v;
	n->prox = NULL;
	if(f->fim != NULL) f->fim->prox = n;
	else f->ini = n;
	f->fim = n;
	return v;
}

int fila_retira_l(FilaL *f){
	Lista_f *t;
	int v;
	if(fila_vazia_l(f)){
		printf("Fila vazia!");
		exit(1);
	}
	t = f->ini;
	v = t->info;
	f->ini = t->prox;
	if(f->ini==NULL) f->fim = NULL;
	// free(t);
	return v;
}

int fila_retira_l_pesquisa(FilaL* f, int query) {
	Lista_f* t, * u;
	int v;
	int n = 0, i = 0;

	if (fila_vazia_l(f)) {
		printf("Fila vazia!");
		exit(1);
	}
	t = f->ini;
	v = t->info;
	do {
		if (query != v) {
			u = t->prox;
			v = u->info;
			n++;
		}
		else {
			
		}
	} while (t->prox);

	i = 0;
	u = t;
	t = f->ini;

	do {
		if (t->prox /*&& u->prox*/) {
			
		}
		else break;
		i++;
		u = u->prox;
		t = t->prox;
	} while (1);

	f->ini = t;

	if (f->ini == NULL) f->fim = NULL;
	// free(t);
	return v;
}

int fila_vazia_l(FilaL *f){
	return (f->ini == NULL);
}

void fila_libera_l(FilaL *f){
	Lista_f *q = f->ini;
	while(q!=NULL){
		Lista_f *t = q->prox;
		free(q);
		q = t;
	}
	free(f);
}

Lista_f* fila_busca_l(FilaL *fila, int informacao){
	Lista_f *q;
	for(q=fila->ini; q!=NULL; q=q->prox){
		if(informacao == q->info){
			return q;
		}
	}
	return NULL;
}

// Funções de impressão

void fila_imprime_vet(Fila *f){
	int i;
	for(i=0;i<f->n; i++) printf("%d \n", f->vet[(f->ini+i)%N_FILA]);
}

void fila_imprime_l(FilaL *f){
	Lista_f *q;
	for(q=f->ini; q!= NULL; q=q->prox) printf("\t%d\n",q->info);
}