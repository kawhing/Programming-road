#include <stdio.h>

int main(){
    int num_k;

    float result = 0;
    for(int i = 0; i < 100; ++i){
        result += i+1;
    }

    for(int i = 0; i < 50; ++i){
        result += (i+1)*(i+1);
    }

    for(float i = 0; i < 10; ++i){
        result += 1/(i+1);
    }

    printf("%f",result);
    return 0;
}