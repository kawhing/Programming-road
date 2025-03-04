#include <stdio.h>

int main() {
    int num;
    printf("Please enter the str'len what you want : ");
    scanf("%d",&num);
    
    int str[num];
    printf("Please enter the str'number one by one :");
    for(int i = 0; i < num; ++i){
        scanf("%d",&str[i]);
    }
    int max_str = str[0], min_str = str[0];
    for(int i = 0; i < num - 1; ++i){
        for(int j = i + 1; j < num; ++j){
            if(str[i] > str[j]){
                max_str = str[i];
            }else if(str[i] < str[j]){
                max_str = str[j];
            }
        }
    }
    printf("%d %d",min_str,max_str);
    return 0;
}