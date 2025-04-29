#include <stdio.h>

int * test(int * a){   
    return a;
}

int main(){
    int a = 10;
    int * p = test(&a);  
    printf("%d\n", *p);
  	printf("%d", *test(&a)); 
}