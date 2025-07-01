#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    ll n, ans = 0;
    cin >> n;
    vector<ll> nums(n);
    for(ll i = 0; i < n; ++i){
        cin >> nums[i];
        ans += nums[i];
    }
    if(ans % 2LL) cout << "Alice" << endl;
    else cout << "Bob" << endl;
}
int main(){
    solve();
    return 0;
}