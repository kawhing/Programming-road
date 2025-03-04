#include<iostream>
using namespace std;
typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
}Node;

void initList(Node** head){
    *head = new Node();
    (*head)->data = 0;
    (*head)->prev = nullptr;
    (*head)->next = nullptr;
}

void insertNode(Node* head, int data, int index){
    if(index < 0){
        cout << "插入位置不合法!" << endl;
        return;
    }
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    Node* current = head;
    while(current->next != nullptr){
        current = current->next;
    }
    newNode->next = current->next;
    newNode->prev = current;
    current->next = newNode;
    
    ++head->data;
}

void printList(Node* head){
    Node* current = head->next;
    while(current != nullptr){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
int main(){
    Node* list;
    initList(&list);
    insertNode(list, 1, 0);
    insertNode(list, 10, 0);
    insertNode(list, 100, 0);
    printList(list);
    return 0;
}