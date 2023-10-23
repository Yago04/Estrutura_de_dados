#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

No* lista_criar() {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        perror("Erro na alocação de memória.");
        exit(EXIT_FAILURE);
    }
    novo->proximo = NULL;
    return novo;
}

void lista_destruir(No* L) {
    No* atual = L;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}

void lista_inserir_no_ordenado(No* L, No* no) {
    No* atual = L;
    while (atual->proximo != NULL && no->valor > atual->proximo->valor) {
        atual = atual->proximo;
    }
    no->proximo = atual->proximo;
    atual->proximo = no;
}

void lista_inserir_no_i(No* L, int i, float novo_valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    if (novo_no == NULL) {
        perror("Erro na alocação de memória.");
        exit(EXIT_FAILURE);
    }
    novo_no->valor = novo_valor;

    No* atual = L;
    int j;
    for (j = 0; j < i; j++) {
        if (atual->proximo == NULL) {
            free(novo_no);
            perror("Posição de inserção inválida.");
            exit(EXIT_FAILURE);
        }
        atual = atual->proximo;
    }

    novo_no->proximo = atual->proximo;
    atual->proximo = novo_no;
}

void lista_remover_no_i(No* L, int i) {
    No* atual = L;
    int j;
    for (j = 0; j < i; j++) {
        if (atual->proximo == NULL) {
            perror("Posição de remoção inválida.");
            exit(EXIT_FAILURE);
        }
        atual = atual->proximo;
    }

    No* no_remover = atual->proximo;
    if (no_remover != NULL) {
        atual->proximo = no_remover->proximo;
        free(no_remover);
    }
}

void lista_remover_no(No* L, float valor_busca) {
    No* atual = L;
    while (atual->proximo != NULL) {
        if (atual->proximo->valor == valor_busca) {
            No* no_remover = atual->proximo;
            atual->proximo = no_remover->proximo;
            free(no_remover);
        } else {
            atual = atual->proximo;
}
}
}
