#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 30

typedef struct BiTreeNode {    
    char data;
    struct BiTreeNode *lchild, *rchild;
} BiTreeNode, *BiTree;

typedef BiTreeNode* ElemType;

typedef struct LinkedStackNode {
    ElemType data;
    struct LinkedStackNode *next;
} LinkedStackNode, *LinkedStack;

typedef struct SequenQueue {
    ElemType data[MAXSIZE];
    int front;
    int rear;
} SequenQueue;

LinkedStack Init_LinkedStack() {
    LinkedStack top = (LinkedStackNode *)malloc(sizeof(LinkedStackNode));
    top->next = NULL;
    return top;
}

int LinkedStack_Empty(LinkedStack top) {
    return top->next == NULL;
}

int Push_LinkedStack(LinkedStack top, ElemType x) {
    LinkedStackNode *node = (LinkedStackNode *)malloc(sizeof(LinkedStackNode));
    if (!node) {
        return 0;
    } else {
        node->data = x;
        node->next = top->next;
        top->next = node;
        return 1;
    }
}

int Pop_LinkedStack(LinkedStack top, ElemType *x) {
    if (top->next == NULL) {
        return 0;
    } else {
        LinkedStackNode *node = top->next;
        *x = node->data;
        top->next = node->next;
        free(node);
        return 1;
    }
}

SequenQueue *Init_SequenQueue() {
    SequenQueue *Q = (SequenQueue *)malloc(sizeof(SequenQueue));
    Q->front = 0;
    Q->rear = 0;
    return Q;
}

int SequenQueue_Full(SequenQueue *Q) {
    return (Q->rear + 1) % MAXSIZE == Q->front;
}

int Enter_SequenQueue(SequenQueue *Q, ElemType x) {
    if (SequenQueue_Full(Q)) {
        return 0;
    } else {
        Q->data[Q->rear] = x;
        Q->rear = (Q->rear + 1) % MAXSIZE;
        return 1;
    }
}

int Delete_SequenQueue(SequenQueue *Q, ElemType *x) {
    if (Q->front == Q->rear) {
        return 0;
    } else {
        *x = Q->data[Q->front];
        Q->front = (Q->front + 1) % MAXSIZE;
        return 1;
    }
}

void Visit(BiTree bt) {
    printf("%c", bt->data);
}

BiTree CreateBiTree(char str[]) {
    BiTree bt;
    static int i = 0;
    char c = str[i++];
    if (c == '.') {
        bt = NULL;
    } else {
        bt = (BiTree)malloc(sizeof(BiTreeNode));
        bt->data = c;
        bt->lchild = CreateBiTree(str);
        bt->rchild = CreateBiTree(str);
    }
    return bt;
}

void LevelOrder(BiTree bt) {
    if (!bt) return;
    SequenQueue *Q = Init_SequenQueue();
    Enter_SequenQueue(Q, bt);
    while (Q->front != Q->rear) {
        BiTree node;
        Delete_SequenQueue(Q, &node);
        Visit(node);
        if (node->lchild) Enter_SequenQueue(Q, node->lchild);
        if (node->rchild) Enter_SequenQueue(Q, node->rchild);
    }
}

void InOrder(BiTree bt) {
    LinkedStack S = Init_LinkedStack();
    BiTree p = bt;
    while (p || !LinkedStack_Empty(S)) {
        if (p) {
            Push_LinkedStack(S, p);
            p = p->lchild;
        } else {
            Pop_LinkedStack(S, &p);
            Visit(p);
            p = p->rchild;
        }
    }
}

int main() {
    BiTree root;
    char tree[MAXSIZE];
    printf("请输入扩展序列创建一棵二叉树!\n");
    scanf("%s", tree);
    root = CreateBiTree(tree);
    printf("\n以下输出二叉树层序遍历结果：\n");
    LevelOrder(root);
    printf("\n以下输出二叉树中序遍历结果（非递归）：\n");
    InOrder(root);
    printf("\n");
    return 0;
}