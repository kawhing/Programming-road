#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define QUEUE_TYPE int
#define ARRAY_TYPE int

typedef struct Queue{
    QUEUE_TYPE data;
    struct Queue *next;
}Queue;

Queue* queueInit(){
    Queue *head = (Queue*)malloc(sizeof(Queue));
    head->data  = 0;
    head->next = NULL;
    return head;
}

bool queueIsEmpty(Queue* head){
    return (head->next == NULL || head->data == 0);
}

void enqueue(Queue *head, QUEUE_TYPE data){
    Queue *newNode = (Queue*)malloc(sizeof(Queue));
    if(!newNode){
        printf("[ERROR]: 分配空间失败!\n");
        return;
    }
    Queue *cnt = head;
    while(cnt->next){
        cnt = cnt->next;
    }
    
    newNode->data = data;
    newNode->next = cnt->next;
    cnt->next = newNode;
    ++head->data;
    printf("[INFO]: 在队列第[%d]个位置入队[%d]成功!\n", head->data, newNode->data);
}

void dequeue(Queue *head){
    if(queueIsEmpty(head)){
        printf("[ERROR]: 出队失败, 队列为空!\n");
        return;
    }

    Queue *temp = head->next;
    head->next = temp->next;
    --head->data;
    printf("[INFO]: 出队[%d]成功!\n", temp->data);
    free(temp);
}

QUEUE_TYPE queueTop(Queue *head){
    if(head->next)
        return head->next->data;
    return -1;
}

void queueClear(Queue *head){
    if(queueIsEmpty(head)){
        printf("[INFO]: 无需清空, 队列已空!\n");
        return;
    }
    Queue *cnt = head->next, *temp;
    while(cnt){
        temp = cnt;
        cnt = cnt->next;
        head->next = cnt;
        free(temp);
        --head->data;
    }
    if(head->next != NULL || head->data != 0)
        printf("[ERROR]: 队列清空失败!\n");
    printf("[INFO]: 队列清空成功!\n");
}

int queueSize(Queue *head){
    return head->data;
}

void queueInsertNode(Queue *head, ARRAY_TYPE array[], int arraySize){
    for(int i = 0; i < arraySize; ++i){
        enqueue(head, array[i]);
        printf("Empty: %d\n", queueIsEmpty(head));
        printf("Top: %d\nSize: %d\n\n", queueTop(head), queueSize(head));
    }
}

void queueDeque(Queue *head){
    while(!queueIsEmpty(head)){
        dequeue(head);
    }
}

int main(){
    ARRAY_TYPE array[] = {0, 1, 2, 3, 4, 5};
    Queue *queue = queueInit();
    queueInsertNode(queue, array, sizeof(array) / sizeof(array[0]));
    queueDeque(queue);
    queueClear(queue);
    return 0;
}