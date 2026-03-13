class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int digitsSize = digits.size();
        vector<int> nums;
        int x = 1, tempNum = 0;
        for(int i = digitsSize - 1; i >= 0; --i){
            tempNum = digits[i] + x;
            nums.push_back(tempNum % 10);
            x = tempNum / 10;
        }
        if(x) nums.push_back(x);
        for(int i = 0; i < nums.size() / 2; ++i){
            swap(nums[i], nums[nums.size()-1-i]);
        }
        return nums;
    }
};