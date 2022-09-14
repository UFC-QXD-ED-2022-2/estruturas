#include <limits.h>
#include <stdlib.h>

#include "lista.h"

struct lista {
  // local de armazenamento
  int *elementos;
  // quantidade de índices *usados*
  unsigned int quantidade;
  // quantidade de índices *alocados*
  unsigned int capacidade;
};

// Cria uma liva lista
ListaInt *lista_criar() {
  // TODO
}

void lista_apagar(ListaInt *lista) {}

void lista_inserir(ListaInt *lista, int elemento) {
  // TODO: Verificar se há capacidade disponível

  // Supondo que existe capacidade
  lista->elementos[lista->quantidade] = elemento;
  ++lista->quantidade;
}

void lista_inserir_ordenado(ListaInt *lista, int elemento) {
  // TODO: Verificar se há capacidade disponível

  if (lista->quantidade == 0) {
    lista->elementos[lista->quantidade] = elemento;
    ++lista->quantidade;
  }

  int j;
  for (j = lista->quantidade - 1; j >= 0 && lista->elementos[j] > elemento;
       --j) {
    lista->elementos[j + 1] = lista->elementos[j];
  }

  lista->elementos[j + 1] = elemento;
  ++lista->quantidade;
}

int lista_remover(ListaInt *lista, unsigned int indice) {
  if (indice >= lista->quantidade) {
    return INT_MIN;
  }

  lista->elementos[indice] = lista->elementos[lista->quantidade - 1];
  --lista->quantidade;

  // TODO: Retornar valor que foi removido
}

int lista_remover_ordenado(ListaInt *lista, unsigned int indice) {
  if (indice >= lista->quantidade) {
    return INT_MIN;
  }

  int i;

  for (i = indice; i < lista->quantidade - 1; ++i) {
    lista->elementos[i] = lista->elementos[i + 1];
  }
  --lista->quantidade;

  // TODO: Retornar valor que foi removido
}

bool lista_buscar(ListaInt *lista, int elemento) {
  unsigned int i;
  for (i = 0; i < lista->quantidade; ++i) {
    if (lista->elementos[i] == elemento) {
      return true;
    }
  }

  return false;
}

int lista_buscar_indice_ordenado(ListaInt *lista, int elemento) {
  unsigned int inicio, fim, meio;

  if (lista->quantidade == 0) {
    return -1;
  }

  inicio = 0;
  fim = lista->quantidade - 1;

  while (inicio <= fim) {
    meio = inicio + (fim - inicio) / 2;

    if (elemento == lista->elementos[meio]) {
      return meio;
    } else if (elemento < lista->elementos[meio]) {
      fim = meio - 1;
    } else {
      inicio = meio + 1;
    }
  }

  return -1;
}

bool lista_buscar_ordenado(ListaInt *lista, int elemento) {
  // TODO: Aproveitar chamando `lista_buscar_indice_ordenado`
}
