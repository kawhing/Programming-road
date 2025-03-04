#include <stdio.h>
#include <string.h>

//编写一个程序，实现将一个整数数组按照升序或降序排列，并使用指针来操作数组元素。

int main(){
    int size;
    printf("Please enter the size of arr :");
    scanf("%d",&size);

    int str[size];
    printf("Please enter a arr : ");
    
    for(int i = 0; i < size; ++i){
        scanf("%d",&str[i]);
    }
    int *p;
    int (*p)[size] = &str;

    //升序排列
    for(int i = 0; i < size-1; ++i){
        for(int j = 0; j < size-i-1; ++j){
            if(*(p+j) > *(p+j+1)){
                int tmp = *(p+j);
                *(p+j) = *(p+j+1);
                *(p+j+1) = tmp;
            }
        }
    }
    
    for(int i = 0; i < size; ++i){
        printf("%d ",*(p+i));
    }
}