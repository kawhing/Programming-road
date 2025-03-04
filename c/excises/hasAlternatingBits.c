#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool hasAlternatingBits(int n){
    int bit[64];
    int test = 1, num = 0;
    
    while(n/2 != 0){
        bit[num] = n%2;
        n /= 2;
        ++num;
    }
    bit[num] = n%2;
    ++num;
    
    
    for(int i = 0; i < num-1; ++i){
        if(bit[i] == bit[i+1]){
            test = 0;
            break;
        }
    }
    
    if(test == 1){
        return true;
    }{
        return false;
    }
}

int main() {
    int num;
    printf("Please enter a num : ");
    scanf("%d", &num);
    
    if(hasAlternatingBits(num)){
        printf("true");
    }else{
       printf("false"); 
    }
    
    return 0;
}