class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int, int> mp, ans;
        vector<int> numsCopy = nums, res = nums;
        sort(numsCopy.begin(), numsCopy.end());
        
        for(int i = 0; i < nums.size(); ++i){
            if(mp.find(nums[i]) != mp.end()){
                mp[nums[i]]++;
            }else{
                mp[nums[i]] = 1;
            }
        }
        ans[numsCopy[0]] = 0;
        for(int i = 1; i < nums.size(); ++i){
            if(numsCopy[i] == numsCopy[i - 1]){
                continue;
            }
            ans[numsCopy[i]] = ans[numsCopy[i - 1]] + mp[numsCopy[i - 1]];
        }
        for(int i = 0; i < nums.size(); ++i){
            res[i] = ans[nums[i]];
        }
        return res;
    }
};
