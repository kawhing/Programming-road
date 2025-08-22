#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    int sSize = s.size();
    
    // 计数数组
    vector<int> cnt(26, 0);
    
    // 统计每个字符出现的次数
    for(int i = 0; i < sSize; ++i){
        cnt[s[i] - 'a']++;
    }
    
    // 找出出现次数最多的字符
    int ans = 0;
    for(int i = 0; i < 26; ++i){
        ans = max(ans, cnt[i]);
    }
    
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}