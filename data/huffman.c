#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 256

// 定义哈夫曼树节点结构
typedef struct Node {
    char data;
    int freq;
    struct Node *left;
    struct Node *right;
} Node;

// 创建新节点
Node* createNode(char data, int freq) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// 合并两个节点
Node* mergeNodes(Node* left, Node* right) {
    Node* node = createNode('\0', left->freq + right->freq);
    node->left = left;
    node->right = right;
    return node;
}

// 打印哈夫曼编码
void printCodes(Node* root, int code[], int length) {
    if (root->left) {
        code[length] = 0;
        printCodes(root->left, code, length + 1);
    }
    if (root->right) {
        code[length] = 1;
        printCodes(root->right, code, length + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < length; i++)
            printf("%d", code[i]);
        printf("\n");
    }
}

int main() {
    // 输入字符和对应频率
    char data[] = { 'a', 'b', 'c', 'd', 'e' };
    int freq[] = { 5, 9, 12, 13, 16 };
    int size = sizeof(data) / sizeof(data[0]);

    // 创建节点数组
    Node* nodes[MAX_NODES];
    for (int i = 0; i < size; i++)
        nodes[i] = createNode(data[i], freq[i]);

    // 构建哈夫曼树
    int n = size;
    while (n > 1) {
        // 找到频率最小的两个节点
        int min1 = -1, min2 = -1;
        for (int i = 0; i < n; i++) {
            if (min1 == -1 || nodes[i]->freq < nodes[min1]->freq)
                min1 = i;
        }
        for (int i = 0; i < n; i++) {
            if (i != min1 && (min2 == -1 || nodes[i]->freq < nodes[min2]->freq))
                min2 = i;
        }
        // 合并最小的两个节点
        Node* merged = mergeNodes(nodes[min1], nodes[min2]);
        nodes[min1] = merged;
        nodes[min2] = nodes[n - 1];
        n--;
    }

    // 打印哈夫曼编码
    int code[MAX_NODES], length = 0;
    printCodes(nodes[0], code, length);

    return 0;
}