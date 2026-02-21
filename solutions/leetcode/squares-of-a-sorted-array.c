/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; ++i){
        result[i] = pow(nums[i], 2);
    }
    for (int i = 0; i < numsSize-1; ++i){
        for (int j = 0; j < numsSize-i-1; ++j){
            if (result[j+1] < result[j]){
                int tmp = result[j];
                result[j] = result[j+1];
                result[j+1] = tmp;
            }
        }
    }
    for (int i = 0; i < numsSize; ++i){
        printf("%d ",result[i]);
    }
    *returnSize = numsSize;
    return result;
}