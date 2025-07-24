#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int a[10][10];
int dp[20][10][10];

int main() {
    cin >> n;
    
    memset(a, 0, sizeof(a));
    
    int x, y, val;
    while (cin >> x >> y >> val) {
        if (x == 0 && y == 0 && val == 0) break;
        a[x-1][y-1] = val;
    }
    
    // 初始化
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = a[0][0];
    
    // DP
    for (int k = 1; k < 2 * n - 1; k++) {
        for (int i = 0; i < n; i++) {
            for (int p = 0; p < n; p++) {
                int j = k - i;
                int q = k - p;
                
                // 检查边界
                if (j < 0 || j >= n || q < 0 || q >= n) continue;
                
                int maxVal = -1;
                
                // 四种转移方式
                if (i > 0 && p > 0 && dp[k-1][i-1][p-1] >= 0)
                    maxVal = max(maxVal, dp[k-1][i-1][p-1]);
                if (i > 0 && dp[k-1][i-1][p] >= 0)
                    maxVal = max(maxVal, dp[k-1][i-1][p]);
                if (p > 0 && dp[k-1][i][p-1] >= 0)
                    maxVal = max(maxVal, dp[k-1][i][p-1]);
                if (dp[k-1][i][p] >= 0)
                    maxVal = max(maxVal, dp[k-1][i][p]);
                
                if (maxVal >= 0) {
                    dp[k][i][p] = maxVal;
                    if (i == p && j == q) {
                        // 同一位置，只取一次
                        dp[k][i][p] += a[i][j];
                    } else {
                        // 不同位置，取两次
                        dp[k][i][p] += a[i][j] + a[p][q];
                    }
                }
            }
        }
    }
    
    cout << dp[2*n-2][n-1][n-1] << endl;
    
    return 0;
}