#include <stdio.h>
#include <string.h>
#include "util.h"

/**
 * Fun��o auxiliar para imprimir tracinhos.
 * @param nTracinhos N�mero de tracinhos a ser impresso na tela.
 */
void util_imprimeTracinhos(int nTracinhos) {

    int i;

    for (i = 0; i < nTracinhos; i++) {
        printf("-");
    }
}

/**
 * Fun��o que remove o \n deixado pelo fgets
 * @param dados Endereco  da cadeia de caracteres a ter o \n final removido.
 */
void util_removeQuebraLinhaFinal(char dados[]) {
    int tamanho;
    tamanho = (int) strlen(dados);
    if ((tamanho > 0) && (dados[tamanho - 1] == '\n')) {
        dados[tamanho - 1] = '\0';
    }
}