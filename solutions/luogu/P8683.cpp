#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, numN, numM, ans;
vector<ll> nums;

void solve() {
    cin >> n >> m;
    nums.resize(n + m + 1);
    for (int i = 0; i < (int)nums.size(); ++i) cin >> nums[i];

    sort(nums.begin(), nums.end());

    if (m == 0) {
        ans = 0;
        for (ll x : nums) ans += x;
    } else {
        ans = nums.back() - nums.front();
        for (int i = 1; i < (int)nums.size() - 1; ++i) ans += llabs(nums[i]);
    }

    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}