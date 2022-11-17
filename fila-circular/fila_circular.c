#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct qx_fila_circular {
    int *elementos;
    unsigned int inicio;
    unsigned int fim;
    unsigned int capacidade;
} FilaCircularInt;

FilaCircularInt *fila_circular_criar(unsigned int capacidade) {
    FilaCircularInt *nova_fila = malloc(sizeof(struct qx_fila_circular));

    nova_fila->elementos = malloc(sizeof(int)*capacidade);
    nova_fila->capacidade = capacidade;
    nova_fila->inicio = 0;
    nova_fila->fim = 0;
}

void fila_circular_devolver(FilaCircularInt *fila) {
    // ! IMPORTANTE: fizemos **duas** alocações para criar. A ordem de desalocação **sempre** importa.
    free(fila->elementos);
    free(fila);
}

bool fila_circular_cheia(FilaCircularInt *fila) {
    unsigned int novo_fim = (fila->fim + 1) % fila->capacidade;

    return fila->inicio == novo_fim;
}

bool fila_circular_vazia(FilaCircularInt *fila) {
    return fila->inicio == fila->fim;
}

bool fila_circular_enfileirar(FilaCircularInt *fila, int elemento) {
    if(fila_circular_cheia(fila)) {
        return false;
    }

    // fim marca a posição onde inserir
    fila->elementos[fila->fim] = elemento;
    fila->fim = (fila->fim + 1) % fila->capacidade;

    return true;
}

// esta função não serve para informar quem foi removido
bool fila_circular_desenfileirar(FilaCircularInt *fila) {
    if(fila_circular_vazia(fila)) {
        return false;
    }

    // inicio marca a posição de quem será removido
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
}

// só é válida quando a fila não está vazia!
int fila_circular_inicio(FilaCircularInt *fila) {
    return fila->elementos[fila->inicio];
}

// só é válida quando a fila não está cheia!
int fila_circular_fim(FilaCircularInt *fila) {
    // TODO ???
}

void fila_circular_imprimir_estado(FilaCircularInt *fila) {
    printf("elementos = [\n\t");
    for(unsigned int i = 0; i < fila->capacidade; i++) {
        printf("%i, ", fila->elementos[i]);
    }
    printf("\n]\ninicio = %u\nfim = %u\n", fila->inicio, fila->fim);
}