#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll ans = 0;
    vector<ll> nums(10);
    map<ll, bool> mp;
    for(ll i = 0; i < 10; ++i){
        cin >> nums[i];
        ll temp = nums[i]%42;
        if(mp.find(temp) != mp.end()) continue;
        else{
            mp[temp] = true;
            ++ans;
        }
    }
    cout << ans << endl;
}
int main(){
    solve();
    return 0;
}