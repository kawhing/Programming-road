#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    vector<int> nums(n+1);
    vector<vector<int>> ans(n, vector<int>(n, 0));
    ans[0][n/2] = 1;
    int x = 0, y = n/2;
    for(int i = 2; i <= n*n; ++i){
        if(x == 0 && y != n-1){
            x = n-1, ++y;
            ans[x][y] = i;
        }else if(x != 0 && y == n-1){
            --x, y = 0;
            ans[x][y] = i;
        }else if(x == 0 && y == n-1){
            ++x;
            ans[x][y] = i;
        }else{
            if(!ans[x-1][y+1]){
                --x, ++y;
                ans[x][y] = i;
            }else{
                ++x;
                ans[x][y] = i;
            }
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    solve();
    return 0;
}