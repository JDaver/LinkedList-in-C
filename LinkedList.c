
#include <stdatomic.h>
#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"



//PRINT
void printLista(Nodo* head){
    Nodo* temp = head;
    while (temp!=NULL) {
        printf("il valore e': %d\n",temp->val);
        temp = temp->next;
     }
}

//INSERT IN HEAD
Nodo* InsertHead(Nodo* head, int valore){
    Nodo* currentNode = (Nodo*)malloc(sizeof(Nodo));
    currentNode->val = valore;
    currentNode->next = head;
    return currentNode;
}

//INSERT IN TAIL
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

//DELETE A SPECIFIC NODE
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

//INSERT AFTER A SPECIFIC NODE 
Nodo* insertAfter(Nodo* head, int newVal, int target){
        int check = 0;
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
                check = 1;
                break;
            }
            temp = temp->next;
        }
        if(check==1){
            printf("Nodo target trovato: %d e' stato inserito dopo %d.\n",newVal,target);
        }else {
            printf("Il nodo target non e' presente nella lista.\n");
        }
        return head;
    }
//INSERT BEFORE A SPECIFIC NODE
Nodo* InsertBefore(Nodo* head, int newVal, int target){
    int check = 0;
    if(head==NULL){
            return head;
    }
    Nodo* previous = NULL;
    Nodo* temp = head;

    while(temp!=NULL){
        if(temp->val == target){
            Nodo* newNode = (Nodo*)malloc(sizeof(Nodo));
            newNode->val = newVal;
            if(previous==NULL){
                newNode->next = temp;
                printf("il nuovo valore e' la nuova testa.\n");
                return newNode;
            }else{
                previous->next = newNode;
                newNode->next = temp;
                check = 1;
                break;
            }
            newNode->next = temp;
        }
        previous = temp;
        temp = temp->next;
    }
    if(check==1){
        printf("Nodo target trovato: %d e' stato inserito prima di %d.\n",newVal,target);
    }else {
        printf("Il nodo target non e' presente nella lista.\n");
    }
    return head;
}

//REMOVE THE HEAD NODE
Nodo* RemoveHead(Nodo* head){
    if(head==NULL||head->next==NULL){
        return NULL;
    }
    Nodo* tempHead = (Nodo*)malloc(sizeof(Nodo));
    tempHead = head;
    head = head->next;
    free(tempHead);
    return head;
    }

//REMOVE THE TAIL NODE
Nodo* RemoveTail(Nodo* head){
    if(head==NULL||head->next==NULL){
        return NULL;
    }
    Nodo* temp = head;
    while (temp->next!=NULL) {
        temp = temp->next;
    }
    free(temp);
    return head;
}