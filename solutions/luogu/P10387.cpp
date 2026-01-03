#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int m = 1e6 + 10;
ll n, s, ans, now, sum, cnt[m], p[m], c[m];
void solve(){
    //第i次训练
    for(ll i = 0; i < 1e6; ++i){
        if(now < s) break;
        ans += s;
        sum -= now;
        now -= cnt[i+1];
    }
    cout << sum + ans;
}
int main(){
    cin >> n >> s;
    for(ll i = 0; i < n; ++i){
        cin >> p[i] >> c[i];
        cnt[c[i]] += p[i];
        sum += p[i] * c[i];
        now += p[i];
    }
    solve();
}
