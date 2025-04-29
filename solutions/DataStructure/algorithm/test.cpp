#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct HuffmanNode{
    char data;
    int freq;
    HuffmanNode *lchild, *rchild;
    HuffmanNode(char data, int freq){
        this->data = data;
        this->freq = freq;
        lchild = rchild = nullptr;
    }
};

struct Compare{
    bool operator()(HuffmanNode* l, HuffmanNode* r){
        return l->freq > r->freq;
    }
};

void printHuffmanCodes(HuffmanNode* root, string code, unordered_map<char, string>& huffmanCode) {
    if(!root) return;
    if(!root->lchild && !root->rchild){
        cout << root->data << ": " << code << endl;
        huffmanCode
    }
}

int main(){

    return 0;
}