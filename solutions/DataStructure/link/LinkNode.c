#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;
typedef struct{
    Node* head;
}LinkedNode;

int initNode(LinkedNode* list){
    list->head = NULL;
    return 1;
}

void insertNode(LinkedNode* list, int element, int index){
    Node* newNode = malloc(sizeof(Node));
    newNode->data = element;
    newNode->next = NULL;
    if(index < 0){
        printf("插入位置不合法！\n");
        return;
    }else if(index == 0){
        newNode->next = list->head;
        list->head = newNode;
    }else{
        Node* current = list->head;
        for(int i = 0; i < index - 1 && current != NULL; ++i){
            current = current->next;
        }
        if(current != NULL){
            newNode->next = current->next;
            current->next = newNode;
        }else{
            printf("插入位置不合法！\n");
            return;
        }
    }
}
void printNode(LinkedNode* list){
    Node* current = list->head;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
void deleteNode(LinkedNode* list, int index){
    if(index < 0){
        printf("删除位置不合法！\n");
        return;
    }
    if(list->head == NULL){
        printf("链表为空,删除失败!\n");
        return;
    }
    Node* temp;
    if(index == 0){
        list->head = list->head->next;
        free(temp);
    }else{
        Node* current = list->head;
        for(int i = 0; i < index-1 && current != NULL; ++i){
            current = current->next;
        }
        if(current != NULL){
            temp = current->next;
            current->next = current->next->next;
            free(temp);
        }else{
            printf("删除位置不合法!\n");
            return;
        }
    }
}
void changeNode(LinkedNode* list, int element, int index){
    Node* current = list->head;
    for(int i = 0; i < index-1 && current != NULL; ++i){
        current = current->next;
    }
    if(current != NULL){
        current->next->data = element;
    }
}

int main(){
    LinkedNode list;
    initNode(&list);

    insertNode(&list, 2023, 0);
    insertNode(&list, 2025, 1);
    insertNode(&list, 2027, 2);
    printNode(&list);
    deleteNode(&list, 1);
    printNode(&list);
    changeNode(&list, 2024, 1);
    printNode(&list);
    return 0;
}