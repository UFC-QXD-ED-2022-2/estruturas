#ifndef QXD_ED_LISTA
#define QXD_ED_LISTA 1

#include <stdbool.h>

struct lista;
typedef struct lista ListaInt;
ListaInt *lista_criar();
void lista_apagar(ListaInt *lista);

void lista_inserir(ListaInt *lista, int elemento);
void lista_inserir_ordenado(ListaInt *lista, int elemento);
int lista_remover(ListaInt *lista, unsigned int indice);
int lista_remover_ordenado(ListaInt *lista, unsigned int indice);
bool lista_buscar(ListaInt *lista, int elemento);
int lista_buscar_indice_ordenado(ListaInt *lista, int elemento);

#endif