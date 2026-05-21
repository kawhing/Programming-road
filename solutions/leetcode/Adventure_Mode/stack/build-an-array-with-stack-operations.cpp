class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int pos = 0;
        for (int i = 1; i <= n && pos < target.size(); ++i) {
            ans.push_back("Push");

            if (i == target[pos]) {
                ++pos;
            } else {
             ans.push_back("Pop");
            }
        }
        return ans;
    }
};