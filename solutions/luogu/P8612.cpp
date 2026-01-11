#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int num[51][51];
int n, m, k, ans = 0;

void dfs(int x, int y, int maxV, int numV){
    if(x > n || y > m) return;
    if(x == n && y == m){
        if(numV == k || (numV == k - 1 && maxV < num[x][y]))
            ans++;  
        ans %= MOD;
        return;         
    }
    dfs(x + 1, y, maxV, numV);
    dfs(x, y + 1, maxV, numV);
    if (maxV < num[x][y]) {
        dfs(x + 1, y, num[x][y], numV + 1);
        dfs(x, y + 1, num[x][y], numV + 1);
    }
}
void solve(){
   cin >> n >> m >> k;
   for(int i = 1; i <= n; ++i){
       for(int j = 1; j <= m; ++j){
           cin >> num[i][j];  
       }
   }
   dfs(1, 1, -1, 0);
   cout << ans;
}
int main(){
    solve();
    return 0;
}