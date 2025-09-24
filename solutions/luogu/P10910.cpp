#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n, m;
    cin >> n >> m;
    string s = "";
    vector<char> t;
    for(ll i = 0; i < n; ++i){
        char a;
        cin >> a;
        s.push_back(a);
    }
    for(ll i = 0; i < m; ++i){
        char a;
        cin >> a;
        t.push_back(a);
    }
    sort(t.begin(), t.end());
    ll i = 0, j = 0;
    vector<char> ans;
    while(i < n && j < m){
        if(s[i] <= t[j]){
            ans.push_back(s[i]);
            ++i;
        }else{
            ans.push_back(t[j]);
            ++j;
        }
    }
    while(i < n){
        ans.push_back(s[i]);
        ++i;
    }
    while(j < m){
        ans.push_back(t[j]);
        ++j;
    }
    for(char c : ans) cout << c;
}
int main(){
    solve();
    return 0;
}