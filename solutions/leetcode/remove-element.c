int removeElement(int* nums, int numsSize, int val) {
    int newlenth = 0;
    for(int i = 0; i < numsSize; ++i){
        if(nums[i] != val){
            nums[newlenth] = nums[i];
            ++newlenth;
        }
    }
    return newlenth;
}