#ifndef QX_FILA_CIRCULAR
#define QX_FILA_CIRCULAR

FilaCircularInt *fila_circular_criar(unsigned int capacidade);
void fila_circular_devolver(FilaCircularInt *fila);

bool fila_circular_cheia(FilaCircularInt *fila);
bool fila_circular_vazia(FilaCircularInt *fila)

bool fila_circular_enfileirar(FilaCircularInt *fila, int elemento);
// esta função não serve para informar quem foi removido
bool fila_circular_desenfileirar(FilaCircularInt *fila);

// só é válida quando a fila não está vazia!
int fila_circular_inicio(FilaCircularInt *fila);
// só é válida quando a fila não está cheia!
int fila_circular_fim(FilaCircularInt *fila);

// Em tese, quem deveria decidir como apresentar os dados na tela deveria ser o usuário
// da biblioteca. Esta função está aqui apenas para vermos em sala o que está acontecendo.
// (=> Iteradores)
void fila_circular_imprimir_estado(FilaCircularInt *fila);

#endif