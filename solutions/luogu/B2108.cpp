#include <bits/stdc++.h>
using  namespace std;
typedef long long ll;
void solve(vector<vector<ll>> &nums, ll n, ll m){
    vector<vector<ll>> temp = nums;
    for(ll i = 1; i < n-1; ++i){
        for(ll j = 1; j < m-1; ++j){
            ll sum = temp[i][j] + temp[i-1][j] + temp[i+1][j] + temp[i][j-1] + temp[i][j+1];
            nums[i][j] = (sum + 2) / 5;
        }
    }
    for(ll i = 0; i < n; ++i){
        for(ll j = 0; j < m; ++j){
            cout << nums[i][j];
            if(j < m-1) cout << " ";
        }
        cout << endl;
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