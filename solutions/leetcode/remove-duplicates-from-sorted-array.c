int removeDuplicates(int* nums, int numsSize) {
    if(numsSize == 0){
        return 0;
    }else{
        int newlenth = 1;
        for(int i = 1; i < numsSize; ++i){
            if(nums[i] != nums[newlenth-1]){
                nums[newlenth] = nums[i];
                ++newlenth;
            }
        }
        return newlenth;
    }
}