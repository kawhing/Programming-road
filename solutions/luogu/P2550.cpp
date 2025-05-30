#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n;
    cin >> n;
    vector<vector<ll>> nums(n+1, vector<ll>(7));
    vector<ll> ans(7, 0);
    for(ll i = 0; i <= n; ++i){
        for(ll j = 0; j < 7; ++j){
            cin >> nums[i][j];
        }
    }
    for(ll i = 1; i <= n; ++i){
        ll count = 0;
        map<ll, bool> mp;
        for(ll j = 0; j < 7; ++j){
            mp[nums[i][j]] = true;
        }
        for(ll j = 0; j < 7; ++j){
            if(mp.find(nums[0][j]) != mp.end()){
                ++count;
            }
        }
        if(count > 0) ++ans[7-count];
    }
    for(ll num : ans) cout << num << " ";
}
int main(){
    solve();
    return 0;
}