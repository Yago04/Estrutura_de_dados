
#ifndef PILHA_H
#define PILHA_H

typedef struct NoPilha {
    char nucleotideo;
    struct NoPilha* prox;
} NoPilha;

typedef struct {
    NoPilha* topo;
} Pilha;

Pilha* criarPilha();
int pilhaVazia(Pilha* pilha);
void empilhar(Pilha* pilha, char nucleotideo);
void desempilhar(Pilha* pilha);
void imprimirPilha(Pilha* pilha);

#endif
