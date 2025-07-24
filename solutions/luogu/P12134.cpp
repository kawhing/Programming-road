#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<ll> nums(n);  // 使用 long long
    for(int i = 0; i < n; ++i) cin >> nums[i];
    sort(nums.begin(), nums.end());
    
    ll ans = LLONG_MAX;  // 使用 long long
    
    for(int i = 0; i <= n - m; ++i){
        ll sum = 0;
        for(int j = i; j < i + m - 1; ++j){
            sum += abs(nums[j+1] * nums[j+1] - nums[j] * nums[j]);
            if(sum >= ans) break;  // 剪枝优化
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);  // 加速IO
    cin.tie(0);
    solve();
    return 0;
}