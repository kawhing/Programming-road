#include <iostream>
using namespace std;
#define MAXSIZE 100

typedef struct BinaryTree{
    int data[MAXSIZE];
    int size;
}BinaryTree;

void initTree(BinaryTree &tree, int size){
    tree->size = size;
    for(int i = 0; i < size; ++i){
        tree->data[i] = -1;
    }
}

void setRoot(BinaryTree &tree, int root){
    if(tree.data[0] != -1){
        tree->data = root;
    }
}

void setRChild(BinaryTree &tree, int Index, int value){
    
}
int main(){

    return 0;
}