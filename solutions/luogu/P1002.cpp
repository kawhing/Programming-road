#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x, y;
};

Point target, horse;
vector<vector<long long>> dp;

// 马的控制点相对位置
vector<int> dx = {-2, -2, -1, -1, 1, 1, 2, 2};
vector<int> dy = {-1, 1, -2, 2, -2, 2, -1, 1};

bool isBlocked(int x, int y) {
    for(int i = 0; i < 8; i++) {
        if(x == horse.x + dx[i] && y == horse.y + dy[i]) {
            return true;
        }
    }
    return x == horse.x && y == horse.y; // 马本身的位置也不能走
}

void solve(){
    cin >> target.x >> target.y >> horse.x >> horse.y;
    
    // 初始化dp数组
    dp = vector<vector<long long>>(target.x + 1, vector<long long>(target.y + 1, 0));
    
    // 起点
    if(!isBlocked(0, 0)) {
        dp[0][0] = 1;
    }
    
    // 动态规划
    for(int i = 0; i <= target.x; i++) {
        for(int j = 0; j <= target.y; j++) {
            if(isBlocked(i, j)) continue;
            
            if(i > 0 && !isBlocked(i-1, j)) {
                dp[i][j] += dp[i-1][j];
            }
            if(j > 0 && !isBlocked(i, j-1)) {
                dp[i][j] += dp[i][j-1];
            }
        }
    }
    
    cout << dp[target.x][target.y] << endl;
}

int main(){
    solve();
    return 0;
}