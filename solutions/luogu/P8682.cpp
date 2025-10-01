#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll n;
    cin >> n;
    vector<ll> nums(n);
    for(ll i = 0; i < n; ++i)
        cin >> nums[i];
    sort(nums.begin(), nums.end());
    ll minDiff = LLONG_MAX;
    for(ll i = 1; i < nums.size(); ++i){
        minDiff = min(minDiff, nums[i]-nums[i-1]);
    }
    cout << ((nums.back() - nums.front()) / minDiff) + 1;
}
int main(){
    solve();
    return 0;
}