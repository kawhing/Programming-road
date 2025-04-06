#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void initNode(Node** head){
    *head = new Node();
    (*head)->data = 0;
    (*head)->next = *head;
}

void insertNode(Node* head, int data, int index){
    if(index < 0){
        cout << "插入位置不合法!" << endl;
        return;
    }
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    Node* current = head;
    while(current->next != head){
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}