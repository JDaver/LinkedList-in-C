#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"




void printLista(Nodo* head){
    Nodo* temp = head;
    while (temp!=NULL) {
        printf("il valore e': %d\n",temp->val);
        temp = temp->next;
     }
}
Nodo* InsertHead(Nodo* head, int valore){
    Nodo* currentNode = (Nodo*)malloc(sizeof(Nodo));
    currentNode->val = valore;
    currentNode->next = head;
    return currentNode;
}

Nodo* InsertTail(Nodo* head, int valore){
    Nodo* currentNode=(Nodo*)malloc(sizeof(Nodo));
    currentNode->val=valore;
    currentNode->next=NULL;
    if(head==NULL){
        return currentNode;
    }
    Nodo* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next =currentNode;
    return head;
    }

Nodo* delNode(Nodo* head, int val){
    Nodo* temp = head;
    Nodo* previous = NULL;
    while((temp->next!=NULL)&&(temp->val!=val)){
        previous=temp;
        temp= temp->next;
    }
    if(temp->next==NULL){
        printf("Il valore non e' presente nella lista!\n");
    return head;
    }else {
        previous->next=temp->next;
        free(temp);
        printf("valore trovato, ho eliminato il valore %d\n",val);
        return head;
    }
    }

    Nodo* insertAfter(Nodo* head, int newVal, int target){
        if(head==NULL){
            return head;
        }
        Nodo* temp = head;

        while (temp!=NULL) {
            if(temp->val == target){
                Nodo* newNode = (Nodo*)malloc(sizeof(Nodo));
                newNode->next = temp->next;
                temp->next = newNode;
                newNode->val = newVal;
                break;
            }
            temp = temp->next;
        }
        return head;
    }