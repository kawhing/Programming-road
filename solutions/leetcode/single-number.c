int singleNumber(int* nums, int numsSize) {
    int mark[numsSize];
    for(int i = 0; i < numsSize; ++i){
        mark[i] = 1;
    }

    if(numsSize == 1){
        return nums[0];
    }else{
        for(int i = 0; i < numsSize-1; ++i){
            for(int j = i+1; j < numsSize; ++j){
                if(nums[i] == nums[j] && mark[i] != 0 && mark[j] != 0){
                    mark[i] = 0;
                    mark[j] = 0;
                    break;
                }
            }
        }
    }
    for(int i = 0; i < numsSize; ++i){
        if(mark[i] == 1){
            return nums[i];
            break;
        }
    }
    
    return 0;
}