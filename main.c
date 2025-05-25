
#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"


int main(){
    Nodo* lista = NULL;

    lista = InsertHead(lista, 12);
    lista = InsertHead(lista, 111);
    lista = InsertHead(lista, 85);
    lista = InsertTail(lista,44);

    lista = delNode(lista, 111);

    lista = InsertTail(lista,56);
    lista = InsertTail(lista,445);
    lista = insertAfter(lista, 999,56);
    printLista(lista);
    return 0;
}