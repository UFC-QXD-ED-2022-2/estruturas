#include <stdio.h>

#include "fila_circular.h"

int main() {
    FilaCircularInt *fila = fila_circular_criar(5);
    fila_circular_desenfileirar(fila);
    fila_circular_enfileirar(fila, 9);
    fila_circular_enfileirar(fila, 6);
    fila_circular_desenfileirar(fila);
    fila_circular_enfileirar(fila, 7);
    fila_circular_desenfileirar(fila);
    fila_circular_enfileirar(fila, 2);
    fila_circular_enfileirar(fila, 69);
    fila_circular_desenfileirar(fila);
    fila_circular_imprimir_estado(fila);
    // fila_circular_desenfileirar(fila);
    // printf("vazia? = %i\n", fila_circular_vazia(fila));
    // fila_circular_desenfileirar(fila);
    // printf("vazia? = %i\n", fila_circular_vazia(fila));
    fila_circular_enfileirar(fila, 5);
    printf("cheia? = %i\n", fila_circular_cheia(fila));
    fila_circular_enfileirar(fila, 4);
    printf("cheia? = %i\n", fila_circular_cheia(fila));
    fila_circular_imprimir_estado(fila);
    return 0;
}