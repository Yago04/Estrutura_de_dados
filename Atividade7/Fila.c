#include "fila.h"
#include <stdlib.h>

Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

int filaVazia(Fila* fila) {
    return (fila->inicio == NULL);
}

void enfileirar(Fila* fila, char nucleotideo) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->nucleotideo = nucleotideo;
    novoNo->prox = NULL;

    if (filaVazia(fila)) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else {
        fila->fim->prox = novoNo;
        fila->fim = novoNo;
    }
}

void desenfileirar(Fila* fila) {
    if (filaVazia(fila)) {
        printf("A fila esta vazia.\n");
        return;
    }

    No* temp = fila->inicio;
    fila->inicio = fila->inicio->prox;

    if (fila->inicio == NULL)
        fila->fim = NULL;

    free(temp);
}

void imprimirFila(Fila* fila) {
    No* atual = fila->inicio;
    while (atual != NULL) {
        printf("%c", atual->nucleotideo);
        atual = atual->prox;
    }
    printf("\n");
}
