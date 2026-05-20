class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> being(nums.size(), false);
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i){
            if(being[nums[i] - 1] == false) being[nums[i] - 1] = true;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(!being[i]) ans.push_back(i + 1);
        }
        return ans;
    }
};