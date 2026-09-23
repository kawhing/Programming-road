#include <stdio.h>
#define LENGTH 10

void insertionSort(int nums[]){
    int i;
    for(i = 1; i < LENGTH; ++i){
        int j, k = i;
        for(j = i - 1; j >= 0; --j){
            if(j == 0 && nums[i] < nums[j]){
                k = 0;  
            }else if(nums[i] >= nums[j]){
                k = j + 1;
                break;
            }
        }
        int temp = nums[i];
        for(j = i; j > k; --j){
            nums[j] = nums[j - 1]; 
        }
        nums[k] = temp;
    }
    for(i = 0; i < LENGTH; ++i){
        printf("%d ", nums[i]);
    }
    printf("\n");
}
int main(){
    int nums[LENGTH] = {5, 4, 3, 2, 1, 0, 9, 8, 7, 6};
    insertionSort(nums);
    return 0;
}
