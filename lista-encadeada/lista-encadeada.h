#ifndef QXD_ED_LISTA_ENCADEADA
#define QXD_ED_LISTA_ENCADEADA 1

#include <stdbool.h>

struct lista_encadeada;
typedef struct lista_encadeada ListaEncInt;

ListaEncInt *lista_enc_criar();
void lista_enc_apagar(ListaEncInt *lista);

bool lista_enc_pertence(ListaEncInt *lista, int elemento);

void lista_enc_inserir_inicio(ListaEncInt *lista, int elemento);
void lista_enc_inserir_fim(ListaEncInt *lista, int elemento);
void lista_enc_inserir_em(ListaEncInt *lista, int elemento, unsigned int indice);

void lista_enc_remover_inicio(ListaEncInt *lista);
void lista_enc_remover_fim(ListaEncInt *lista);
void lista_enc_remover_em(ListaEncInt *lista, int elemento, unsigned int indice);
void lista_enc_remover_todos(ListaEncInt *lista, int elemento);

#endif