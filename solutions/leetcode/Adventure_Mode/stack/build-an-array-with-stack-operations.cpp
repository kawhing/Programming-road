class Solution {
public:
    bool isEqualTarget(vector<int>& target, stack<int> nums){
        if(target.size() != nums.size()) return false;
        for(int i = target.size() -1 ; i >= 0 ; --i){
            if(target[i] != nums.top()){
                return false;
            }
            nums.pop();
        }
        return true;
    }
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        stack<int> nums;
        int pos = 0;
        for(int i = 0; pos < target.size() && i < n; ++i){
            nums.push(i + 1);
            ans.push_back("Push");
            if(target[pos] == i + 1){
                ++pos;
            }else{
                nums.pop();
                ans.push_back("Pop");
            }
            if(pos + 1 == target.size() && isEqualTarget(target, nums)) break;
        }
        if(!isEqualTarget(target, nums)) return{};
        return ans;
    }
};