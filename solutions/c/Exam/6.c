#include <stdio.h>
#include <stdbool.h>

int main(){
    int len = 100, result;
    bool str[len+1];
    for(int i = 0; i <= len+1; ++i){
        str[i] = true;
    }

    for(int i = 2; i*i < len; ++i){
        for(int j = i*i; j < len+1; j += i){
            str[j] = false;
        }
    }

    for(int i = 2; i < len+1; ++i){
        if(str[i] == true){
            printf("%d ",i);
        }
    }
}