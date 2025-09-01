#include <bits/stdc++.h>
using namespace std;

int l, n, m;
vector<int> nums;

bool check(int d) {
    int cnt = 0, last = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] - last < d) {
            cnt++; // 移走当前石头
        } else {
            last = nums[i];
        }
    }
    // 终点也要考虑
    if (l - last < d) cnt++;
    return cnt <= m;
}

void solve() {
    cin >> l >> n >> m;
    nums.resize(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    // 二分答案
    int left = 1, right = l, ans = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}