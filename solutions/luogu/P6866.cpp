#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, ans = 0;
vector<ll> row = {-1, 1, 0, 0}, col = {0, 0, -1, 1};

void dfs(ll i, ll j, vector<vector<char>> &nums, vector<vector<bool>> &used) {
    // 边界检查
    if (i <= 0 || i > n || j <= 0 || j > m || used[i][j] || nums[i][j] == '.') {
        return;
    }
    
    used[i][j] = true;
    
    // 遍历四个方向
    for (ll k = 0; k < 4; ++k) {
        ll ni = i + row[k];
        ll nj = j + col[k];
        dfs(ni, nj, nums, used);
    }
}

void solve() {
    cin >> n >> m;
    vector<vector<char>> nums(n + 1, vector<char>(m + 1));
    vector<vector<bool>> used(n + 1, vector<bool>(m + 1, false));
    
    // 读入矩阵
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            cin >> nums[i][j];
        }
    }
    
    // 寻找连通块
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            if (!used[i][j] && nums[i][j] == '*') {
                dfs(i, j, nums, used);
                ++ans;
            }
        }
    }
    
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}