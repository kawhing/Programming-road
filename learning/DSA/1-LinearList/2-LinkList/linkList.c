#include <stdio.h>
#include <stdlib.h>
#define LINKLIST_TYPE int

typedef struct LinkList{
    LINKLIST_TYPE data;
    struct LinkList *next;
}List, Node;

List* ListInit(){
    List *head = (List*)malloc(sizeof(List));
    head->data = 0;
    head->next = NULL;
    return head;
}

//头插法
void createNode(List* head, LINKLIST_TYPE data){
    Node *newNode = (Node*)malloc(sizeof(List));
    newNode->data = data;
    newNode->next = head->next;
    head->next = newNode;
    ++head->data;
}

Node* searchNode(List* head, LINKLIST_TYPE data){// 根据 "数值" 查找节点, 并返回该节点
    Node* cnt = head;
    int index = 0;
    while(cnt->next && index >= 0){
        if(cnt->next->data == data){
            printf("\n找到目标节点 [%d] 在链表位置: [%d]!\n", data, index);
            return cnt->next;
        }
        ++index;
        cnt = cnt->next;
    }
    return NULL;// 未找到返回NULL
}

void deleteNode(List* head, LINKLIST_TYPE data){// 根据 "数值" 删除节点
    Node* cnt = head;
    while(cnt->next){
        if(cnt->next->data == data){
            Node* tempNode = cnt->next;
            cnt->next = tempNode->next;
            printf("\n成功删除节点: [%d]\n", tempNode->data);
            free(tempNode);
            --head->data;
            return;
        }
        cnt = cnt->next;
    }
}

void editNode(List* head, LINKLIST_TYPE data, LINKLIST_TYPE target){// 根据节点 "数据" 修改目标节点 "数据"
    Node* cnt = head;
    while(cnt->next){
        if(cnt->next->data == target){
            cnt->next->data = data;
            printf("\n已将目标节点 [%d] 数据修改为指定数据 [%d]!\n", target, data);
            return;
        }
        cnt = cnt->next;
    }
}
void printLinkList(List *head){
    Node* cnt = head;
    while(cnt->next){
        printf("%d -> ", cnt->next->data);
        cnt = cnt->next;
    }
    printf("\n");
}

int main(){
    LINKLIST_TYPE array[] = {0, 1, 2, 3, 4, 5};
    List* head = ListInit();//初始化
    int arraySize = sizeof(array) / sizeof(array[0]);
    for(int i = 0; i < arraySize; ++i){// 按数组插入链表
        createNode(head, array[i]);// 增加一个节点
    }
    printLinkList(head);

    searchNode(head, 4);// 查找节点
    printLinkList(head);

    deleteNode(head, 3);// 删除节点
    printLinkList(head);

    editNode(head, 8, 1);// 修改节点
    printLinkList(head);
    return 0;
}