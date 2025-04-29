#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      bool isValid(string s) {
        if(s.size()%2) return false;
        stack<char> stacks;
        unordered_map<char, char> mp = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
        for(int i = 0; i < s.size(); ++i) {
            if(mp.count(s[i])){
                if(stacks.empty() || stacks.top() != mp[s[i]]) return false;
                stacks.pop();
            }else{
                stacks.push(s[i]);
            }
        }
        return stacks.empty();
    }
};

int main(){ 
    Solution s;
    cout << s.isValid("()");
    return 0;
}