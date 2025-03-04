#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct Queue{
    Node* front;//队头
    Node* rear;//队尾
}Queue;

void initQueue(Queue* queue){
    queue->front = queue->rear = nullptr;
}

void enQueue(Queue* queue, int x){
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = nullptr;
    if(queue->rear == nullptr){//如果队列为空
        queue->front = queue->rear = newNode;//队头和队尾都指向新节点
        cout << "入队 : " << newNode->data << endl;
        return;
    }

    queue->rear->next = newNode;//
    queue->rear = newNode;
    cout << "入队 : " << newNode->data << endl;
}

void deQueue(Queue* queue){
    if(queue->front == nullptr){
        cout << "队空!" << endl;
        return;
    }
    Node* temp = queue->front;//保存队头元素
    queue->front = queue->front->next;//删除队头元素
    
    if(queue->front == nullptr){//如果队列中只有一个元素，删除后队列为空
        queue->rear = nullptr;//如果队列中只有一个元素，删除后队列为空
    }
    cout << "出队： " << temp->data << endl;
    delete temp;//释放队头元素
    
}

int main(){
    Queue queue;
    initQueue(&queue);
    enQueue(&queue, 10);
    enQueue(&queue, 20);
    enQueue(&queue, 30);
    deQueue(&queue);
    return 0;
}