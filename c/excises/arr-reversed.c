#include <stdio.h>

int main() {
    int num;
    printf("Please enter strlen : ");
    scanf("%d",&num);
    
    int str[num];
    printf("Please enter the str ine by one : \n");
    for(int i = 0; i < num; ++i){
        scanf("%d",&str[i]);
    }
    printf("The Reversed arr is : ");
    for(int i = 0; i < num/2; ++i){
        int tmp = str[i];
        str[i] = str[num-i-1];
        str[num-i-1] = tmp;
    }
    
    for(int i = 0; i < num; ++i){
        printf("%d ",str[i]);
    }
    return 0;
}