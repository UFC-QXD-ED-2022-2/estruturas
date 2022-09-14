#include <stdio.h>

#include "lista.h"

int main() {
    ListaInt *lista = lista_criar();
    lista_inserir(lista, 10);
    lista_inserir(lista, 30);
    lista_inserir(lista, 0);

    // lista_remover(lista, 1);

    printf("10 = %d, 30 = %d, 0 = %d, 20 = %d\n",
        lista_buscar(lista, 10),
        lista_buscar(lista, 30),
        lista_buscar(lista, 0),
        lista_buscar(lista, 20)
    );

    ListaIntIterador *it;

    printf("Lista = ");
    for(
        it = it_lista_criar(lista);
        it_lista_tem_proximo(it);
        it_lista_avancar(it)
    ) {
        printf("%d, ", it_lista_obter_elemento(it));
    }
    printf("\n");

    return 0;
}
