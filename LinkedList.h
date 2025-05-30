#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node{
    int val;
    struct Node* next;
}Node;

void printList(Node* head);

void printLoopedList(Node* head,int size);

Node* InsertHead(Node* head, int val);

Node* InsertTail (Node* head,int val);

Node* delNode(Node* head, int val);
 
Node* insertAfter(Node* head, int newVal, int target);

Node* RemoveHead(Node* head);

Node* RemoveTail(Node* head);

Node* InsertBefore(Node* head, int newVal, int target);

Node* reverseList(Node* head);

int createLoop(Node* head);

int createLoopAtValue(Node* head,int val);

void isLoop(Node* head);
#endif