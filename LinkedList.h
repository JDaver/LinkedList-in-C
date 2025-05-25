#ifndef LINKEDLIST_H
#define LINKEDLIST_H
typedef struct Nodo{
    int val;
    struct Nodo* next;
}Nodo;

void printLista(Nodo* head);

Nodo* InsertHead(Nodo* head, int val);

Nodo* InsertTail (Nodo* head,int val);

Nodo* delNode(Nodo* head, int val);
 
Nodo* insertAfter(Nodo* head, int newVal, int target);

#endif