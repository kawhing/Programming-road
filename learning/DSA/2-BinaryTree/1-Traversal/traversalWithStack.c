#include "traversalWithStack.h"

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
    

    treeFree(tree);
    return 0;
}