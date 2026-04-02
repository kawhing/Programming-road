class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, count = 0, cnt = 0;
        bool isGroup = true;
        while(cnt < nums.size()){
            
            if(nums[cnt] == 1){
                    ++count;
            }else{
                ans = max(count, ans);
                count = 0;
            }
            ++cnt;
        }
        ans = max(count, ans);
        return ans;
    }
};