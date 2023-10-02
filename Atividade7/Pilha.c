#include "pilha.h"
#include <stdlib.h>

Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

int pilhaVazia(Pilha* pilha) {
    return (pilha->topo == NULL);
}

void empilhar(Pilha* pilha, char nucleotideo) {
    NoPilha* novoNo = (NoPilha*)malloc(sizeof(NoPilha));
    novoNo->nucleotideo = nucleotideo;
    novoNo->prox = pilha->topo;
    pilha->topo = novoNo;
}

void desempilhar(Pilha* pilha) {
    if (pilhaVazia(pilha)) {
        printf("A pilha esta vazia.\n");
        return;
    }

    NoPilha* temp = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(temp);
}

void imprimirPilha(Pilha* pilha) {
    NoPilha* atual = pilha->topo;
    while (atual != NULL) {
        printf("%c", atual->nucleotideo);
        atual = atual->prox;
    }
    printf("\n");
}
