class Solution {
public:
    bool isValid(string s) {
        int sSize = s.size();
        if(sSize % 2 == 1) return false;
        stack<char> stk;
        map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        for(int i = 0; i < sSize; ++i){
            if(pairs.count(s[i])){
                if(stk.empty() || stk.top() != pairs[s[i]]){
                    return false;
                }
                stk.pop();
            }else
                stk.push(s[i]);
        }
        return stk.empty();
    }
};