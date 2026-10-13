#include <stdio.h>
#include <stdlib.h>
#define TREE_TYPE int
#define ARRAY_TYPE int

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

void preorderTraversal(Tree *tree){
    if(!tree) return;
    printf("%d -> ", tree->data);
    preorderTraversal(tree->left);
    preorderTraversal(tree->right);
}

void inorderTraversal(Tree *tree){
    if(!tree) return;
    inorderTraversal(tree->left);
    printf("%d -> ", tree->data);
    inorderTraversal(tree->right);
}

void postorderTraversal(Tree *tree){
    if(!tree) return;
    postorderTraversal(tree->left);
    postorderTraversal(tree->right);
    printf("%d -> ", tree->data);
}

void treeFree(Tree *tree){
    if(!tree) return;
    treeFree(tree->left);
    treeFree(tree->right);
    free(tree);
}

int main(){
    ARRAY_TYPE array[] = {1, 2, 3, 4, 5, 6, 7};
    int arraySize = sizeof(array) / sizeof(ARRAY_TYPE);
    Tree *tree = insertNode(array, arraySize, 0);

    printf("先序遍历:\n");
    preorderTraversal(tree);
    printf("\n中序遍历:\n");
    inorderTraversal(tree);
    printf("\n后序遍历:\n");
    postorderTraversal(tree);
    printf("\n");

    treeFree(tree);
    return 0;
}