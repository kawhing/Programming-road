#include <bits/stdc++.h>
using namespace std;

void solve(){
    char c;
    int size = 0;
    vector<char> chars;
    string line;
    getline(cin, line);
    chars.resize(line.size()*line.size());
    for(int i = 0; i < chars.size(); ++i){
        if(i < line.size()) chars[i] = line[i];
        else cin >> chars[i];
    }
    bool flag;
    int nums = 0;

    vector<int> ans;
    ans.push_back(line.size());
    for(int i = 0; i < chars.size(); ++i){
        if(i == 0 || (i > 0 && chars[i-1] != chars[i])) flag = true;
        else flag = false;
        if(flag){
            if(((nums+1) % 2 == 0 && chars[i] == '0') || ((nums+1) % 2 == 1 && chars[i] == '1')){
                ans.push_back(0);
                ++nums;
            }
            ans.push_back(1);
            ++nums;
        }else ++ans.back();
    }
    for(int i : ans){
        cout << i << " ";
    }
}
int main(){
    solve();
    return 0;
}