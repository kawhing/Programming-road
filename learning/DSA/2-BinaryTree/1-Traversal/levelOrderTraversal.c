#include "levelOrderTraversal.h"



int main(){
    ARRAY_TYPE array[] = {1, 2, 3, 4, 5, 6, 7};
    int arraySize = sizeof(array) / sizeof(ARRAY_TYPE);
    Tree *tree = insertNode(array, arraySize, 0);

    printf("层序遍历:\n");
    levelOrder(tree);
    printf("\n");
    treeFree(tree);
    return 0;
}