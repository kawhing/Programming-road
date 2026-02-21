class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        int ans = 0, num = 0;
        for(int i = 0; i < nums.size(); ++i){
            hash[nums[i]] += 1;
            if(hash[nums[i]] > num){
                num = hash[nums[i]];
                ans = nums[i];
            }
            
        }
        return ans;
    }
};