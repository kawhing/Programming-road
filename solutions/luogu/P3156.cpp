#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n, m;
    cin >> n >> m;
    vector<ll> nums(n), ask(m);
    for(ll i = 0; i < n; ++i) cin >> nums[i];
    for(ll i = 0; i < m; ++i) cin >> ask[i];
    for(ll i = 0; i < m; ++i){
        cout << nums[ask[i]-1] << endl;
    }
}
int main(){
    solve();
    return 0;
}