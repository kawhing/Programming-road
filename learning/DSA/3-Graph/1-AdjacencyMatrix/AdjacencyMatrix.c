#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*  0 - 1, 3
    1 - 0, 2, 3, 5
    2 - 1, 4, 5
    3 - 0, 1, 6, 7
    4 - 2, 4, 9
    5 - 1, 2, 4, 6, 8, 9
    6 - 3, 5, 7, 8
    7 - 3, 6
    8 - 5, 6, 9
    9 - 4, 5, 8
*/
void initGraph(int (*G)[10]){
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            G[i][j] = 0;
        }
    }
}
void print(int (*G)[10]){
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
}
void test1(){
    int G[10][10];
    initGraph(G);
    for(int i = 0; i < 10; ++i){
        printf("请输入与节点%d相连的节点: \n", i);
        printf("请输入数量: \n");
        int c;
        scanf("%d", &c);
        for(int j = 0; j < c; ++j){
            int getNum;
            scanf("%d", &getNum);
            G[i][getNum] = 1;

        }
    }
    print(G);
}
void test2(){
    int G[10][10];

    print(G);
}

int main(){
    test1();
    return 0;
}