#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    if(n < 2){
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    vector<bool> used(n, false);
    for(int i = 0; i < n-1; ++i){
        string tmp = str.substr(i, 2);
        if(tmp == "VK"){
            used[i] = true;
            used[i+1] = true;
            ++ans;
        }
    }
    for(int i = 0; i < n; ++i){
        if(used[i]) continue;
        if(str[i] == 'V'  && i != n-1 && !used[i+1]){
            ++ans;
            break;
        }
        if(str[i] == 'K' && i != 0 && !used[i-1]){
            ++ans;
            break;
        }
    }
    cout << ans << endl;
}
int main(){
    solve();
    return 0;
}
