class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int numsSize = nums.size();
        map<int, int> mp;
        for(int i = 0; i < numsSize; ++i){
            map<int, int>::iterator it = mp.find(target - nums[i]);
            if(it != mp.end())
                return {it->second, i};
            mp[nums[i]] = i;
        }
        return {};
    }
};