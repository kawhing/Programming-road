#include <stdio.h>

void test(int num){
    int test = 1;
    for(int i = 2; i*i <= num; ++i){
        for(int j = i*i; j < num; j += i){
            if(num % j == 0){
                test = 0;
                break;
            }
        }
    }
    if(test == 0){
        printf("%d不是素数", num);
    }else{
        printf("%d是素数",num);
    }
}
int main(){
    int number;
    printf("请输入一个数字 : ");
    scanf("%d",&number);
    test(number);

    return 0;
} 