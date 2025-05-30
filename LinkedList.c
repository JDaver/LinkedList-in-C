#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"



//PRINT
void printList(Node* head){
    while (head!=NULL) {
        printf("Curent value is: %d\n",head->val);
        head = head->next;
     }
}

void printLoopedList(Node* head,int size){
    int i;
    if (head == NULL || size <= 0) {
        printf("List is empty or size is invalid.\n");
    return;
    }
    for(i = 0; i < size; i++){
        printf("Curent value is: %d\n",head->val);
        head = head->next;
    }
}

//INSERT IN HEAD
Node* InsertHead(Node* head, int valore){
    Node* currentNode = (Node*)malloc(sizeof(Node));
    currentNode->val = valore;
    currentNode->next = head;
    return currentNode;
}

//INSERT IN TAIL
Node* InsertTail(Node* head, int valore){
    Node* currentNode=(Node*)malloc(sizeof(Node));
    currentNode->val=valore;
    currentNode->next=NULL;
    if(head==NULL){
        return currentNode;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next =currentNode;
    return head;
    }

//DELETE A SPECIFIC NODE
Node* delNode(Node* head, int val){
    Node* temp = head;
    Node* previous = NULL;
    while((temp->next!=NULL)&&(temp->val!=val)){
        previous=temp;
        temp= temp->next;
    }
    if(temp->next==NULL){
        printf("this value is not in the list!\n");
    return head;
    }else {
        previous->next=temp->next;
        free(temp);
        printf("found value, value is now erased %d\n",val);
        return head;
    }
    }

//INSERT AFTER A SPECIFIC NODE 
Node* insertAfter(Node* head, int newVal, int target){
        int check = 0;
        if(head==NULL){
            return head;
        }
        Node* temp = head;

        while (temp!=NULL) {
            if(temp->val == target){
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->next = temp->next;
                temp->next = newNode;
                newNode->val = newVal;
                check = 1;
                break;
            }
            temp = temp->next;
        }
        if(check==1){
            printf("Target node found: %d was inserted after %d.\n",newVal,target);
        }else {
            printf("Target node is not in the list.\n");
        }
        return head;
    }
//INSERT BEFORE A SPECIFIC NODE
Node* InsertBefore(Node* head, int newVal, int target){
    int check = 0;
    if(head==NULL){
            return head;
    }
    Node* previous = NULL;
    Node* temp = head;

    while(temp!=NULL){
        if(temp->val == target){
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->val = newVal;
            if(previous==NULL){
                newNode->next = temp;
                printf("New value is now the new head.\n");
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
        printf("Target node found: %d was inserted before %d.\n",newVal,target);
    }else {
        printf("Target node is not in the list.\n");
    }
    return head;
}

//REMOVE THE HEAD NODE
Node* RemoveHead(Node* head){
    if(head==NULL||head->next==NULL){
        return NULL;
    }
    Node* tempHead = (Node*)malloc(sizeof(Node));
    tempHead = head;
    head = head->next;
    free(tempHead);
    return head;
    }

//REMOVE THE TAIL NODE
Node* RemoveTail(Node* head){
    if(head==NULL||head->next==NULL){
        return NULL;
    }
    Node* temp = head;
    while (temp->next!=NULL) {
        temp = temp->next;
    }
    free(temp);
    return head;
}

//REVERSE A LIST
Node* reverseList(Node* head){
    Node* current = head;
    Node* prev = NULL;
    Node* next_backup = NULL;

    while (current!=NULL) {
    next_backup = current->next;
    current->next = prev;
    prev = current;
    current = next_backup;
    }
    return prev;
}


//THIS FUNCTIONS CHANGES THE ->NEXT OF THE LAST ELEMENT OF THE LIST, FROM NULL TO THE FIRST ELEMENT.
//CREATING A LOOP, BE AWARE OF INFINTE LOOPS ( ͡° ͜ʖ ͡°) 
int createLoop(Node* head){
    int counter=1;
    Node* firstElement = head;
    if (head==NULL) {
        return 0;
    }
    
    while (head->next!=NULL) {
        head = head->next;
        counter ++;
    }
    head->next = firstElement;
    head = head->next;
    return counter;
}
//This can't be used on a looped list to shorten the loop by removing some nodes.
//if the val is not in the list it will end up to an infinite loop.
//i set a limit to ten thousand iteration to avoid the infinite loop.
int createLoopAtValue(Node* head,int val){
    int counter=1;
    Node* temp = head;
    Node* firstElement = temp;
    
    if (head==NULL|| head->next==NULL) {
        printf("Impossible to create a loop, too feew elements.");
        return 0;
    }

    while (head->next!=NULL||counter<10000) {
        if(head->val == val){
            break;
        }
        head = head->next;
        counter ++;
    }
    if(counter>=10000){
        printf("No value found so far, breaking the iteration to avoid infinite loops.\n");
    }
    head->next = firstElement;
    head = firstElement;
    return counter;
}

 void isLoop(Node* head){
    Node * fast = head;
    Node * slow = head;
    
    while(fast->next!=NULL && fast->next->next!= NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            printf("This is a looped list.\n");
            return;
        }
    }

    printf("This is not a looped list.\n");
}