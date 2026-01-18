#include <stdio.h>
#include <stdlib.h>
#define LINKLIST_TYPE int

typedef struct LinkList{
    LINKLIST_TYPE data;
    struct LinkList *next;
}List;

List* ListInit(){
    List *head = (List*)malloc(sizeof(List));
    head->data = 0;
    head->next = NULL;
    return head;
}

//头插法
void createNode(List* head, LINKLIST_TYPE data){
    List *newNode = (List*)malloc(sizeof(List));
    newNode->data = data;
    newNode->next = head->next;
    head->next = newNode;
    ++head->data;
}

void printLinkList(List *head){
    List *cnt = head;
    while(cnt->next){
        printf("%d -> ", cnt->next->data);
        cnt = cnt->next;
    }
    printf("\n");
}

int main(){
    LINKLIST_TYPE array[] = {0, 1, 2, 3, 4, 5};
    List* head = ListInit();
    int arraySize = sizeof(array) / sizeof(array[0]);
    for(int i = 0; i < arraySize; ++i){
        createNode(head, array[i]);
    }
    printLinkList(head);
    return 0;
}