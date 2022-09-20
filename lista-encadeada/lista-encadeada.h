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


struct iterador_lista_encadeada;
typedef struct lista_encadeada ItListaEncInt;

ItListaEncInt *it_lista_enc_criar(ListaEncInt *lista);
void it_lista_enc_apagar(ListaIntIterador *it);
bool it_lista_enc_tem_proximo(ListaIntIterador *it);
int it_lista_enc_obter_elemento(ListaIntIterador *it);
void it_lista_enc_avancar(ListaIntIterador *it);

#endif