#include <stdio.h>

int main(){
    int num_n, num_a;
    printf("请输入数字n : ",&num_n);
    scanf("%d",&num_n);
    printf("请输入数字a : ");
    scanf("%d",&num_a);

    int result = num_a;
    for(int i = 0; i < num_n-1; ++i){
        result += result*10 + num_a;
    }

    printf("%d",result);
    return 0;
}