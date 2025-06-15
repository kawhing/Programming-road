#include <bits/stdc++.h>
using namespace std;
void solve(){
    vector<vector<int>> scores(5, vector<int>(4));
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 4; ++j){
            cin >> scores[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < 5; ++i){
        int sum = 0;
        for(int j = 0; j < 4; ++j){
            sum += scores[i][j];
        }
        scores[i][0] = sum;
        if(scores[ans][0] < sum) ans = i; 
    }
    cout << ans+1 << " " << scores[ans][0];
}
int main(){
    solve();
    return 0;
}
