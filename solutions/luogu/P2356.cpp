#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void solve(){
    ll n, used;
    cin >> n;
    vector<vector<ll>> game(n, vector<ll>(n));
    vector<ll> row_sum(n), col_sum(n);
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            cin >> game[i][j];
            if (game[i][j]) ++used;
            row_sum[i] += game[i][j];
            col_sum[j] += game[i][j];
        }
    }
    if(used == n*n){
        cout << "Bad Game" << endl;
        return;
    }
    ll ans = 0;
    for(ll i = 0; i < n; ++i){
        for(ll j = 0; j < n; ++j){
            if(game[i][j]) continue;
            if(ans < row_sum[i]+col_sum[j]) ans = row_sum[i]+col_sum[j];
        }
    }
    cout << ans << endl;
}
int main(){
    solve();
    return 0;
}
