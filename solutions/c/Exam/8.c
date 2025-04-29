#include <stdio.h>

int main(){
    int len = 3, num[len][len];
    printf("请输入一个%d*%d的整数数组 : ", len, len);
    for(int i = 0; i < len; ++i){
        for(int j = 0; j < len; ++j){
            scanf("%d",&num[i][j]);
        }
    }

    int result = 0;
    for(int i = 0; i < len; ++i){
        result += num[i][i] + num[i][len-i-1];
    }
    result -= num[1][1];
    printf("%d",result);
    return 0;
}