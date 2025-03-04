#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXVALUE 32767

typedef struct {
    int weight;
    int parent, lchild, rchild;
} HNodeType;

typedef struct {
    int bit[8];
    int start;
} HCodeType;

HNodeType HuffNode[10]; // 增加数组大小以适应最多9个节点
HCodeType HuffCode[10];
int n;

void CreateHuffTree(void) {
    int m, i, j, x1, x2, m1, m2;
    //printf("请输入叶子节点个数: ");
    scanf("%d", &n);
    m = 2 * n - 1;
    for (i = 1; i <= n; i++) {
        //printf("请输入第%d个叶子节点的权值: ", i);
        scanf("%d", &HuffNode[i].weight);
        HuffNode[i].parent = -1;
        HuffNode[i].lchild = -1;
        HuffNode[i].rchild = -1;
    }
    for (i = n + 1; i <= m; i++) {
        HuffNode[i].weight = 0;
        HuffNode[i].parent = -1;
        HuffNode[i].lchild = -1;
        HuffNode[i].rchild = -1;
    }
    for (i = n + 1; i <= m; i++) {
        m1 = m2 = MAXVALUE;
        x1 = x2 = 0;
        for (j = 1; j <= i - 1; j++) {
            if (HuffNode[j].parent == -1 && HuffNode[j].weight < m1) {
                m2 = m1;
                x2 = x1;
                m1 = HuffNode[j].weight;
                x1 = j;
            } else if (HuffNode[j].parent == -1 && HuffNode[j].weight < m2) {
                m2 = HuffNode[j].weight;
                x2 = j;
            }
        }
        HuffNode[x1].parent = i;
        HuffNode[x2].parent = i;
        HuffNode[i].lchild = x1;
        HuffNode[i].rchild = x2;
        HuffNode[i].weight = HuffNode[x1].weight + HuffNode[x2].weight;
    }
}

void PrintHuffTree() {
    int i;
    printf("哈夫曼树各项数据如下表所示:\n");
	printf("        结点i weight parent    lchid   rchild\n");
    for (i = 1; i < 2 * n; i++)
		printf("\t%d\t%d\t%d\t%d\t%d\n",i,HuffNode[i].weight,HuffNode[i].parent,
		       HuffNode[i].lchild,HuffNode[i].rchild);
    printf("\n");
}

void CreateHuffCode(void) {
    int i, c, p;
    HCodeType cd;
    for (i = 1; i <= n; i++) {
        cd.start = n - 1;
        c = i;
        p = HuffNode[c].parent;
        while (p != -1) {
            if (HuffNode[p].lchild == c)
                cd.bit[cd.start] = 0;
            else
                cd.bit[cd.start] = 1;
            cd.start--;
            c = p;
            p = HuffNode[c].parent;
        }
        for (int j = cd.start + 1; j < n; j++)
            HuffCode[i].bit[j] = cd.bit[j];
        HuffCode[i].start = cd.start;
    }
}

void PrintHuffcode(void) {
    int i, j;
    printf("每个叶子结点的哈夫曼编码为:\n");
    for (i = 1; i <= n; i++) {
        for (j = HuffCode[i].start + 1; j < n; j++)
            printf("%d", HuffCode[i].bit[j]);
        printf("\n");
    }
}

int main(void) {
    CreateHuffTree();
    PrintHuffTree();
    CreateHuffCode();
    PrintHuffcode();
    return 0;
}