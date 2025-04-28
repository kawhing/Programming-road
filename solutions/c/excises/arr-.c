#include <stdio.h>

int main() {
    int num;
    printf("Plese enter a number : ");
    scanf("%d",&num);
    
    int str[num];
    printf("Please enter the arr one by one : \n");
    for(int i = 0; i < num; ++i){
        scanf("%d",&str[i]);
    }
    
    printf("The turned arr is : ");
    for(int i = 0; i < num - 1; ++i){
        for(int j = i + 1; j < num; ++j){
            if(str[i] > str[j]){
                int tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }
        }
    }
    for(int i = 0; i < num; ++i){
        printf("%d ",str[i]);
    }
    return 0;
}