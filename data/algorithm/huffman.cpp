#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

//定义哈夫曼树节点
struct HuffmanNode{
    char data;//
    int freq;//权重
    HuffmanNode *lchild, *rchild;

    HuffmanNode(char dara, int freq){
        lchild = rchild = nullptr;
        this->data = data;
        this->freq = freq;
    }
};

//比较器,用于优先队列
struct compare{
    bool operator()(HuffmanNode* l, HuffmanNode* r){
        return l->freq > r->freq;
    }
};

void printCode(HuffmanNode* root, string str){
    if(!root) return;
    if(root->data != '$')
        cout << root->data << ": " << str << endl;
    printCode(root->lchild, str + "0");
    printCode(root->rchild, str + "1");
}

//构建哈夫曼树并打印哈夫曼编码
void HuffmanCodes(char data[], int freq[], int size){
    HuffmanNode *lchild, *rchild, *top;

    priority_queue<HuffmanNode* , vector<HuffmanNode*>, compare> minHeap;
    for(int i = 0; i < size; ++i){
        minHeap.push(new HuffmanNode(data[i], freq[i]));
    }

    while(minHeap.size() != 1){
        lchild = minHeap.top();
        minHeap.pop();

        rchild = minHeap.top();
        minHeap.pop();

        top = new HuffmanNode('$', lchild->freq + rchild->freq);
        top->lchild = lchild;
        top->rchild = rchild;
        
        minHeap.push(top);
    }
    printCode(minHeap.top(), "");
}


int main(){
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int size = sizeof(arr) / sizeof(arr[0]);

    HuffmanCodes(arr, freq, size);

    return 0;
}