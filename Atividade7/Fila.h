

#ifndef FILA_H
#define FILA_H

typedef struct Node {
    char nucleotideo;
    struct Node* prox;
} No;

typedef struct {
    No* inicio;
    No* fim;
} Fila;

Fila* criarFila();
int filaVazia(Fila* fila);
void enfileirar(Fila* fila, char nucleotideo);
void desenfileirar(Fila* fila);
void imprimirFila(Fila* fila);

#endif

