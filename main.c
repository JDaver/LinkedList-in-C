
#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"


int main(){
    Node* lista = NULL;
    Node* loopedList = NULL;

    lista = InsertHead(lista, 12);
    lista = InsertHead(lista, 111);
    lista = InsertHead(lista, 85);
    lista = InsertTail(lista,44);
    lista = delNode(lista, 111);
    lista = InsertTail(lista,56);
    lista = InsertTail(lista,445);
    lista = insertAfter(lista, 999,445);
    lista = InsertBefore(lista, 55, 999);
    printList(lista);
    printf("********************\n");
    loopedList = InsertHead(loopedList,12);
    loopedList = InsertHead(loopedList,14);
    loopedList = InsertHead(loopedList,22);
    loopedList = InsertHead(loopedList,55);
    loopedList = InsertHead(loopedList,89);
    int size = createLoop(loopedList);
    printf("%d\n",size);
    printLoopedList(loopedList, size);
    printf("********************\n");
    size = createLoopAtValue(loopedList, 55);
    printLoopedList(loopedList, size);
    
    

    //Free the looped list when no longer needed, Using common list functions on it could cause infinite loops.
    free(loopedList); 
    return 0;
}