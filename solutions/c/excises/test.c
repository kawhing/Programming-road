#include <stdio.h>

int test(int x, int n);
int main(){
    int x, n;
    printf("请输入n的值 : ");
     scanf("%d", &n);
     printf("请输入x的值 : ");
     scanf("%d", &x);

     printf("%d",test(x,n));
     return 0;
}
int test(int x, int n){
     if(n < 0){
         return 0;
     }else if(n == 1){
         return 1;
     }else if(n > 1){
         return x*test(x, n-1) + (n-2)*test(x, n-2);
     } 
}
