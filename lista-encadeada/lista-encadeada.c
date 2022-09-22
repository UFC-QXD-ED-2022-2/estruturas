#include "lista-encadeada.h"

#include <stdlib.h>

typedef struct no_encadeado {
  int elemento;
  struct no_encadeado *proximo;
} NoEnc;

struct lista_encadeada {
  NoEnc *primeiro;
};

// Funções privadas >>>

NoEnc *no_enc_criar(int elemento) {
  NoEnc *novo_no = malloc(sizeof(struct no_encadeado));

  novo_no->elemento = elemento;
  novo_no->proximo = NULL;

  return novo_no;
}

void no_enc_apagar(NoEnc *no) { free(no); }

// Funções públicas >>>

ListaEncInt *lista_enc_criar() {
  ListaEncInt *nova_lista = malloc(sizeof(struct lista_encadeada));

  nova_lista->primeiro = NULL;

  return nova_lista;
}

void lista_enc_apagar(ListaEncInt *lista) {
  // TODO: Apagar também todos os nós da Lista

  free(lista);
}

bool lista_enc_pertence(ListaEncInt *lista, int elemento) {
  NoEnc *atual = lista->primeiro;

  while (atual != NULL) {
    if (atual->elemento == elemento) {
      return true;
    }

    atual = atual->proximo;
  }

  // * Versão mais enxuta >>>
  // * for (atual = lista->primeiro; atual != NULL; atual = atual->proximo)
  // * (...)

  return false;
}

void lista_enc_inserir_inicio(ListaEncInt *lista, int elemento) {
  NoEnc *novo_no = no_enc_criar(elemento);

  novo_no->proximo = lista->primeiro;
  lista->primeiro = novo_no;
}

void lista_enc_inserir_fim(ListaEncInt *lista, int elemento) {
  NoEnc *ultimo = lista->primeiro;
  NoEnc *novo_no = no_enc_criar(elemento);

  if(lista->primeiro == NULL) { // Lista vazia
    lista->primeiro = novo_no;
  } else {
    while(ultimo->proximo != NULL) {
      ultimo = ultimo->proximo;
    }

    ultimo->proximo = novo_no;
  }
}

bool lista_enc_inserir_em(ListaEncInt *lista, int elemento, unsigned int indice) {
  if(indice == 0) {
    NoEnc *novo_no = no_enc_criar(elemento);

    novo_no->proximo = lista->primeiro;
    lista->primeiro = novo_no;
  } else {
    NoEnc *anterior = lista->primeiro;

    while(indice > 1 && anterior != NULL) {
      anterior = anterior->proximo;
      --indice;
    }

    if(anterior != NULL) {
      NoEnc *novo_no = no_enc_criar(elemento);

      novo_no->proximo = anterior->proximo;
      anterior->proximo = novo_no;
    } else {
      return false;
    }
  }

  return true;
}

void lista_enc_remover_inicio(ListaEncInt *lista) {
  if (lista->primeiro != NULL) {
    NoEnc *removido = lista->primeiro;

    lista->primeiro = lista->primeiro->proximo;
    no_enc_apagar(removido);

    // * Versão alternativa >>>
    // * NoEnc *novo_primeiro = lista->proximo->proximo;
    // * no_enc_apagar(lista->proximo);
    // * lista->primeiro = novo_primeiro;
  }
}

void lista_enc_remover_fim(ListaEncInt *lista) {
  if(lista->primeiro == NULL) {
    return; // Pois a lista está vazia
  } else {
    NoEnc *atual, *anterior;

    if(lista->primeiro->proximo == NULL) {
      // Tornando a lista vazia
      no_enc_apagar(lista->primeiro);
      lista->primeiro = NULL;
    } else {
      anterior = lista->primeiro;
      atual = anterior->proximo;

      while(atual->proximo != NULL) {
        anterior = atual;
        atual = atual->proximo;
      }

      no_enc_apagar(atual); // Pois `atual` marca o último neste ponto
      anterior->proximo = NULL;
    }
  }
}

}