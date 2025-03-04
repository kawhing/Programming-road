#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

typedef struct {
    int weight;
    int parent, left, right;
} HuffmanNode;

void createHuffmanTree(HuffmanNode htree[], int weights[], int n) {
    int m = 2 * n - 1; // Total nodes in Huffman tree
    for (int i = 0; i < m; i++) {
        htree[i].weight = (i < n) ? weights[i] : 0;
        htree[i].parent = htree[i].left = htree[i].right = -1;
    }
    for (int i = n; i < m; i++) {
        int min1 = -1, min2 = -1;
        for (int j = 0; j < i; j++) {
            if (htree[j].parent == -1) {
                if (min1 == -1 || htree[j].weight < htree[min1].weight) {
                    min2 = min1;
                    min1 = j;
                } else if (min2 == -1 || htree[j].weight < htree[min2].weight) {
                    min2 = j;
                }
            }
        }
        htree[i].weight = htree[min1].weight + htree[min2].weight;
        htree[i].left = min1;
        htree[i].right = min2;
        htree[min1].parent = htree[min2].parent = i;
    }
}

int main() {
    int n = 4;
    int weights[] = {5, 3, 8, 2};
    HuffmanNode htree[MAX_NODES];
    createHuffmanTree(htree, weights, n);

    printf("Node\tWeight\tParent\tLeft\tRight\n");
    for (int i = 0; i < 2 * n - 1; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", i, htree[i].weight, htree[i].parent, htree[i].left, htree[i].right);
    }

    return 0;
}
