#include <stdio.h>
#include <math.h>

int main(){
    float p = 1, r = 0.09,  year = 0;
    while(year != 11){
        p *= 1+r;
        ++year;
    }
    printf("%f%%",p*100);
    return 0;
}