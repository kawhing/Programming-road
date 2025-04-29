#include <stdio.h>

int main(){
    int num_m, num_n;
    printf("请输入数字m : ");
    scanf("%d", &num_m);
    printf("请输入数字n : ");
    scanf("%d",&num_n);

    int max = (num_m > num_n) ? num_m : num_n;
    int min = (num_m < num_n) ? num_m : num_n;

    for(int i = min; i >= 2; --i){
        if(num_m % i == 0 && num_n % i == 0){
            printf("m和n的最大公约数为 : %d\n", i);
        }
    }

    for(int i = max; i < num_m * num_n; ++i){
        if(i % num_m == 0 && i % num_n == 0){
            printf("m和n的最小公倍数为 : %d\n",i);
        }
    }

    return 0;
}