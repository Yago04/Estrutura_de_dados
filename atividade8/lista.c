#include "lista1.h"
#include <stdio.h>
#include <stdlib.h>

No* lista_criar() {
    No* novo = (No*)malloc(sizeof(No));
    novo->proximo = NULL;
    return novo;
}

void lista_destruir(No* L) {
	No* temp;
    while (L->proximo != NULL) {
        No* temp = L->proximo;
        L->proximo = temp->proximo;
        free(temp);
    }
    free(L);
}

int lista_verificar_existencia(No* L, char valor_busca) {
    No* atual = L->proximo;

    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            return 1;
        }
        atual = atual->proximo;
    }

    return 0;
}

int lista_verificar_ocorrencias(No* L, char valor_busca) {
    int ocorrencias = 0;
    No* atual = L->proximo;

    while (atual != NULL) {
        if (atual->valor == valor_busca) {
            ocorrencias++;
        }
        atual = atual->proximo;
    }

    return ocorrencias;
}

void lista_imprimir_inversa(No* L) {
    if (L->proximo != NULL) {
        lista_imprimir_inversa(L->proximo);
        printf("%c ", L->valor);
    }
}

void lista_inserir_no_i(No* L, int i, char novo_valor) {
    No* novo_no = (No*)malloc(sizeof(No));
    novo_no->valor = novo_valor;

    No* atual = L;
    int j;
    for (j = 0; j < i; j++) { 
        if (atual->proximo == NULL) {
            free(novo_no);
            return;
        }
        atual = atual->proximo;
    }

    novo_no->proximo = atual->proximo;
    atual->proximo = novo_no;
}

void lista_remover_no_i(No* L, int i) {
    No* atual = L;
    int j ;
    for ( j = 0; j < i; j++) {
        if (atual->proximo == NULL) {
            return;
        }
        atual = atual->proximo;
    }

    No* no_remover = atual->proximo;
    if (no_remover != NULL) {
        atual->proximo = no_remover->proximo;
        free(no_remover);
    }
}

void lista_remover_no(No* L, char valor_busca) {
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
