#include <bits/stdc++.h>
using namespace std;
//14. 最长公共前缀
class Solution {
public:
string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    
    int min_len = strs[0].size();
    for(int i = 1; i < strs.size(); ++i)
        min_len = min_len < strs[i].size() ? min_len : strs[i].size();
    
    string str = "";
    for(int i = 0; i < min_len; ++i){
        bool allMatch = true;
        for(int j = 1; j < strs.size(); ++j){
            if(strs[j][i] != strs[0][i]){
                allMatch = false;
                break;
            }
        }
        
        if(allMatch){
            str.push_back(strs[0][i]);
        } else {
            break;
        }
    }
    return str;
}
};

int main(){
    Solution s;
    vector<string> str = {"flower","flow","flight"};
    cout << s.longestCommonPrefix(str) << endl;
    return 0;
}