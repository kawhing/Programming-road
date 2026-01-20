#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Stack_TYPE Tree*
#define TREE_TYPE int
#define ARRAY_TYPE int

// 二叉树部分
typedef struct Tree{
    TREE_TYPE data;
    struct Tree *left, *right;
}Tree;

Tree* treeNode(TREE_TYPE data){
    Tree* tree = (Tree*)malloc(sizeof(Tree));
    if(!tree){
        printf("申请空间失败!\n");
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

// 堆栈部分
typedef struct Stack{
    Stack_TYPE data;
    int size;
    struct Stack *next;
}Stack;

Stack* StackInit(){
    Stack *head = (Stack*)malloc(sizeof(Stack));
    head->data = treeNode(0);
    head->next = NULL;
    if(!head){
        printf("Stack initialization failed\n");
        exit(-1);
    }
    return head;
}

bool stackIsEmpty(Stack *head){
    return !(head->next && head->data->data != 0);
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
    ++head->data->data;
}

void stackPop(Stack* head){
    if(stackIsEmpty(head)){
        printf("堆栈为空!\n");
        return;
    }
    Stack *cnt = head;
    int index = 0;
    while(cnt->next){
        if(index + 1 == head->data->data) break;
        cnt = cnt->next;
        ++index;
    }
    Stack *tempNode = cnt->next;
    cnt->next = NULL;
    free(tempNode);
    --head->data->data;
}

Tree* stackTop(Stack *head){
    if(stackIsEmpty(head)){
        printf("堆栈为空!\n");
        return NULL;
    }
    Stack *cnt = head;
    while(cnt->next){
        cnt = cnt->next;
    }
    return cnt->data;
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

// 二叉树遍历部分

void preorderTraversal(Tree *tree){
    if(!tree) return;
    Stack *stack = StackInit();
    while(tree || !stackIsEmpty(stack)){
        while(tree){
            printf("%d -> ", tree->data);
            if(tree->right)
                stackPush(stack, tree->right);
            tree = tree->left;
        }
        if(!stackIsEmpty(stack)){
            tree = stackTop(stack);
            stackPop(stack);
        }
    }
}

void inorderTraversal(Tree *tree){
    if(!tree) return;
    Stack *stack = StackInit();
    while(tree || !stackIsEmpty(stack)){
        while(tree){
            stackPush(stack, tree);
            tree = tree->left;
        }
        if(!stackIsEmpty(stack)){
            tree = stackTop(stack);
            printf("%d -> ", tree->data);
            stackPop(stack);
            tree = tree->right;
        }
    }
}

void postorderTraversal(Tree *tree){
    if(!tree) return;
    Stack *stack = StackInit();
    Tree *lastVisited = NULL;
    while(tree || !stackIsEmpty(stack)){
        while(tree){
            stackPush(stack, tree);
            tree = tree->left;
        }
        Tree *top = stackTop(stack);
        if(top->right && top->right != lastVisited){
            tree = top->right;
        } else {
            printf("%d -> ", top->data);
            lastVisited = top;
            stackPop(stack);
        }
    }
    printf("\n");
    stackFree(stack);
}

void treeFree(Tree *tree){
    if(!tree) return;
    treeFree(tree->left);
    treeFree(tree->right);
    free(tree);
}


