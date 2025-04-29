#include <stdio.h>

int main(){
    int len = 10, num[len];
    printf("请输入十个数字 : ");
    for(int i = 0; i < len; ++i){
        scanf("%d", &num[i]);
    }

    for(int i = 0; i < len-1; ++i){
        int min = i;
        for(int j = i+1; j < len; ++j){
            if(num[j] < num[min]){
                min = j;
            }
        }
        int temp = num[min];
        num[min] = num[i];
        num[i] = temp;
    }

    for(int i = 0; i < len; ++i){
        printf("%d ",num[i]);
    }
    return 0;
}