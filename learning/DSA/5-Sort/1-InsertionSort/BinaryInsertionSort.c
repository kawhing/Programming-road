#include <stdio.h>
#define LENGTH 10

void binaryInSertionSort(int nums[]){
    int i, j, low, high, mid;
    for(int i = 2; i <= LENGTH; ++i){
        low = 1, high = i - 1;
        nums[0] = nums[i];
        while(low <= high){
            mid = (low + high) / 2;
            if(nums[mid] > nums[i]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        for(int j = i - 1; j > high; --j){
            nums[j + 1]  = nums[j];
        }
        nums[high + 1] = nums[0];
    }
    for(i = 1; i <= LENGTH; ++i){
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main(){
    int nums[LENGTH + 1] = {-1, 5, 4, 3, 2, 1, 0, 9, 8, 7, 6};
    binaryInSertionSort(nums);
    return 0;
}