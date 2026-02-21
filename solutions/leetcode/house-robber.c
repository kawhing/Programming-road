int rob(int* nums, int numsSize) {
    if (numsSize == 0){
        return 0; 
    }else{
        int result[numsSize], num = 0;
        for(int i = 0; i < numsSize; ++i){
            if(i == 0){
                result[num] = nums[i];
            }else if(i == 1){
                result[num] = nums[i] > nums[i-1] ? nums[i] : nums[i-1];
            }else{
                result[num] = nums[i] + result[num-2] > result[num-1] ? nums[i] + result[num-2] : result[num-1];
            }
            ++num;
        }

        return result[num-1];
    }
    return 0;
}