#include <iostream>
using namespace std;
#define MAX 100

typedef struct Queue{
    int *base;
    int front;
    int rear;
}Queue;

void initQueue(Queue * queue){
    queue->base = new int[MAX];
    queue->front = queue->rear = 0;
}

bool isEmpty(Queue* queue){
    return queue->rear == queue->front;
}

bool isFull(Queue* queue){
    return (queue->rear+1) % MAX == queue->front;
}

void enQueue(Queue* queue, int x){
    if(isFull(queue)){
        cout << "队列已满!" << endl;
        return;
    }
    queue->base[queue->rear] = x;
    queue->rear = (queue->rear+1) % MAX;
    cout << "入队 : " << x << endl;
}

void deQueue(Queue* queue){
    if(isEmpty(queue)){
        cout << "队列为空!" << endl;
        return;
    }
    int x = queue->base[queue->front];
    queue->front = (queue->front+1) % MAX;
    cout << "出队 : " << x << endl;
}

int main(){
    Queue queue;
    initQueue(&queue);
    enQueue(&queue, 10);
    enQueue(&queue, 20);
    enQueue(&queue, 30);

    return 0;
}