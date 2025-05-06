#include <bits/stdc++.h>
using  namespace std;
typedef long long ll;

void solve(vector<vector<ll>> &nums, ll n, ll m){
    vector<vector<ll>> temp = nums;
    for(ll i = 1; i < n-1; ++i){
        for(ll j = 1; j < m-1; ++j){
            nums[i][j] += nums[i-1][j-1] + nums[i][j-1] + nums[i-1][j] + nums[i+1][j];
        }
    }
}
int main(){
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> nums(n, vector<ll> (m));
    for(ll i = 0; i< n; ++i){
        for(ll j = 0; j < m; ++j){
            cin >> nums[i][j];
        }
    }
    solve(nums, n, m);
    return 0;
}