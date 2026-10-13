#include <stdio.h>
#include <stdlib.h>
#define DATA int
//邻接表
typedef struct Node{
    DATA data;
    struct Node *next;    
}Node;

typedef struct AdjacencyList{
    Node *head;
}AdjacencyList;

void initList(AdjacencyList *list){
    for(int i = 0; i < 10; ++i){
        //带头节点的结构体数组
        Node *headNode = (Node*)malloc(sizeof(Node));
        headNode->data = 0;//头节点 data域存储改链表的长度
        headNode->next = NULL;
        //插入头节点到结构体数组中的第i位置
        list[i].head = headNode;
    }
}
void insertEdge(AdjacencyList *list, int src, int dest){
    //创建新节点
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = dest;
    newNode->next = list[src].head->next;
    //将新节点用头插法插入到结构体数组的链表中 长度并自增
    list[src].head->next = newNode;
    list[src].head->data++;//长度加一
}
void printEdge(AdjacencyList *list){
    for(int i = 0; i < 10; ++i){
        printf("第%d个结构体 : ", i);
        Node *current = list[i].head->next;
        int size = list[i].head->data; 
        while(size-- && current != NULL){
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}
void freeAdjacencyList(AdjacencyList *list){
    for(int i = 0; i < 10; ++i){
        Node *temp = list[i].head;
        while(temp != NULL){
            Node *next = temp->next;
            free(temp);
            temp = next;
        }
    }
    printf("运行结束,释放内存完毕!\n");
}
int main(){
    AdjacencyList list[10];
    initList(list);
    int G[10][10] = {
        {1, 3, -1},
        {0, 2, 3, 5, -1},
        {1, 4, 5, -1},
        {0, 1, 6, 7, -1},
        {2, 4, 9, -1},
        {1, 2, 4, 6, 8, 9, -1},
        {3, 5, 7, 8, -1},
        {3, 6, -1},
        {5, 6, 9, -1},
        {4, 5, 8, -1}
    };
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10 && G[i][j] != -1; ++j){
            insertEdge(list, i, G[i][j]);
        }
    }
    //打印邻接表
    printEdge(list);
    //释放内存
    freeAdjacencyList(list);
    return 0;
}