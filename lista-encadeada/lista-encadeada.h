#ifndef QXD_ED_LISTA_ENCADEADA
#define QXD_ED_LISTA_ENCADEADA 1

#include <stdbool.h>

struct lista_encadeada;
typedef struct lista_encadeada ListaEncInt;

ListaEncInt *lista_enc_criar();
void lista_enc_apagar(ListaEncInt *lista);

bool lista_enc_pertence(ListaEncInt *lista, int elemento);

void lista_enc_inserir_inicio(ListaEncInt *lista, int elemento);

void lista_enc_remover_inicio(ListaEncInt *lista);

#endif