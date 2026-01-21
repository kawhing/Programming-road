#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define QUEUE_TYPE Tree*
#define ARRAY_TYPE int
#define TREE_TYPE int

typedef struct Tree{
    TREE_TYPE data;
    struct Tree *left, *right;
}Tree;

Tree* treeNode(TREE_TYPE data){
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    if(!tree){
        printf("[ERROE]: 申请空间失败!\n");
        exit(-1);
    }
    tree->data = data;
    tree->left = tree->right = NULL;
    return tree;
}

Tree* insertNode(ARRAY_TYPE array[], int arraySize, int index){
    if(index >= arraySize) return NULL;
    Tree *tree = treeNode(array[index]);
    tree->left = insertNode(array, arraySize, 2 * index + 1);
    tree->right = insertNode(array, arraySize, 2 * index + 2);
    return tree;
}

void treeFree(Tree *tree){
    if(!tree) return;
    treeFree(tree->left);
    treeFree(tree->right);
    free(tree);
}

typedef struct Queue{
    QUEUE_TYPE data;
    struct Queue *next;
}Queue;

Queue* queueInit(){
    Queue *head = (Queue*)malloc(sizeof(Queue));
    head->data = treeNode(0);
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
    ++head->data->data;
    printf("[INFO]: 在队列第[%d]个位置入队[%d]成功!\n", head->data->data, newNode->data->data);
}

void dequeue(Queue *head){
    if(queueIsEmpty(head)){
        printf("[ERROR]: 出队失败, 队列为空!\n");
        return;
    }

    Queue *temp = head->next;
    head->next = temp->next;
    --head->data->data;
    printf("[INFO]: 出队[%d]成功!\n", temp->data->data);
    free(temp);
}

QUEUE_TYPE queueTop(Queue *head){
    if(head->next)
        return head->next->data;
    return NULL;
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
        --head->data->data;
    }
    if(head->next != NULL || head->data != 0)
        printf("[ERROR]: 队列清空失败!\n");
    printf("[INFO]: 队列清空成功!\n");
}

int queueSize(Queue *head){
    return head->data->data;
}

//层次遍历部分
void levelOrder(Tree *tree){
    Queue *queue = queueInit();
    enqueue(queue, tree);
    while(!queueIsEmpty(queue)){
        tree = queueTop(queue);
        dequeue(queue);
        printf("%d -> \n", tree->data);
        if(tree->left)
            enqueue(queue, tree->left);
        if(tree->right)
            enqueue(queue, tree->right);
    }
        
}