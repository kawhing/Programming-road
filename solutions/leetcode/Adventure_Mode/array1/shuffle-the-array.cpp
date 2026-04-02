class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> num1(nums.begin(), nums.begin() + n), num2(nums.begin() + n, nums.end());
        nums.clear();
        for(int i = 0; i < n; ++i){
            nums.push_back(num1[i]);
            nums.push_back(num2[i]);
        }
        return nums;
    }
};