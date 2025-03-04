#include <iostream>
typedef struct Node{
    int data;
    struct Node* next;
}Node;

void initNode(Node** head){
    *head = new Node();
    (*head)->data = 0; 
    (*head)->next = NULL;
}

void insertNode(Node* head, int data, int index){
    if(index < 0){
        printf("插入位置不合法\n");
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    Node* current = head;
    while(current->next != NULL){
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void printList(Node* head){
    Node* current = head->next;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void deleteNode(Node* head, int data){
    Node* current = head;
    while(current->next != NULL){
        if(current->next->data == data){
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
            return;
        }
        current = current->next;
    }
}
void hebing(Node* head1, Node* head2){
    Node* current = head1;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = head2->next;
    free(head2);
}
int main(){
    Node* list1;
    initNode(&list1);
    for(int i = 0; i < 10; ++i){
        insertNode(list1, i*10+1, i);
    }
    printList(list1);
    Node* list2;
    initNode(&list2);
    for(int i = 0; i < 10; ++i){
        insertNode(list2, i*10+2, i);
    }
    printList(list2);
    hebing(list1, list2);
    printList(list1);
    return 0;
}