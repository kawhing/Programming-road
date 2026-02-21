/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void return_min(int *nums, int numsSize, int* result, int* returnSize){
    int minIndex = 0;
    int min = nums[0];

    for(int i = 0; i < numsSize; ++i){
        if(nums[i] < min){
            min = nums[i];
            minIndex = i;
        }
    }
    for(int j = minIndex; j < numsSize-1; ++j){
        nums[j] = nums[j+1];
    }
    --numsSize;
    result[*returnSize] = min;
    ++(*returnSize);
}

int* numberGame(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    *returnSize = 0;
    while(numsSize){
        return_min(nums, numsSize, result, returnSize);
        numsSize--;
        return_min(nums, numsSize, result, returnSize);
        numsSize--;
        int temp = result[*returnSize-2];
        result[*returnSize-2] = result[*returnSize-1];
        result[*returnSize-1] = temp;
    }
    return result;
}