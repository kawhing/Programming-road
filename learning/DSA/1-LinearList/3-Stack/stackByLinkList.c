#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Stack_TYPE int

typedef struct Stack{
    Stack_TYPE data;
    struct Stack *next;
}Stack;

Stack* StackInit(){
    Stack *head = (Stack*)malloc(sizeof(Stack));
    head->data = 0;
    head->next = NULL;
    if(head) printf("Success to init Stack\n");
    return head;
}

bool stackIsEmpty(Stack *head){
    return !(head->next && head->data != 0);
}

//尾插法
void stackPush(Stack* head, Stack_TYPE data){
    Stack *cnt = head;
    while(cnt->next){
        cnt = cnt->next;
    }
    Stack *newNode = (Stack*)malloc(sizeof(Stack));
    newNode->data = data;
    newNode->next = cnt->next;

    cnt->next = newNode;
    ++head->data;
}

void stackPop(Stack* head){
    if(stackIsEmpty(head)){
        printf("堆栈为空!\n");
        return;
    }
    Stack *cnt = head;
    int index = 0;
    while(cnt->next){
        if(index + 1 == head->data) break;
        cnt = cnt->next;
        ++index;
    }
    Stack *tempNode = cnt->next;
    cnt->next = NULL;
    printf("Pop: %d\n", tempNode->data);
    free(tempNode);
}

void stackTop(Stack *head){
    if(stackIsEmpty(head)){
        printf("堆栈为空!\n");
        return;
    }
    Stack *cnt = head;
    while(cnt->next){
        cnt = cnt->next;
    }

    printf("Top: %d\n", cnt->data);
}

void stackFree(Stack *head){
    Stack *cnt = head, *temp;
    while(cnt->next){
        temp = cnt;
        cnt = cnt->next;
        free(temp);

    }
    printf("Free over!\n");
}

int main(){
    Stack_TYPE array[] = {0, 1, 2, 3, 4, 5};
    Stack* head = StackInit();
    int arraySize = sizeof(array) / sizeof(array[0]);
    printf("Empty: %d\n",stackIsEmpty(head));
    for(int i = 0; i < arraySize; ++i){
        stackPush(head, array[i]);
        stackTop(head);
        printf("Empty: %d\n",stackIsEmpty(head));
        printf("\n");
    }
    stackPop(head);
    stackFree(head);

    return 0;
}