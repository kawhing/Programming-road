#include<stdio.h>
#include<math.h>

int main(){
    int num, sum = 0;
    printf("Please enter a number : ");
    scanf("%d",&num);

    for(int i = 1; i <= num; ++i){
        sum += pow(i,2);
    }
    printf("1^2 + 2^2 + ··· + %d^2 = %d",num,sum);
    return 0;
}