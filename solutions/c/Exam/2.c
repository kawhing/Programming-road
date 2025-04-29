#include <stdio.h>

int main(){
    char str[5];
    for(int i = 0; i < 5; ++i){
        str[i] = getchar();
        getchar();
    }
    for(int i = 0; i < 5; ++i){
        printf("%c   ",str[i]+4);
        putchar(str[i]+4);
        printf("\n");
    }
    return 0;
}