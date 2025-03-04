#include <stdio.h>

int main() {
    int num;
    printf("Please enter what you want number for fib : ");
    scanf("%d",&num);
    
    int fib[num];
    fib[0] = fib[1] = 1;
    
    for(int i = 2; i < num; ++i){
        fib[i] = fib[i-1] + fib[i-2];
    }
    for(int i = 0; i < num; ++i){
        printf("%d ",fib[i]);
    }
    return 0;
}