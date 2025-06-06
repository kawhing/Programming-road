#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void solve(){
    ll n, m, k, ans = 0;
    map<ll, bool> a;
    cin >> n >> m >> k;
    while(k > 0){
        ll t;
        cin >> t;
        a[t] = true;
        --k;
    }
    ll pos = 0;
    while(pos < n){
        pos += m;
        ++ans;
        if(a.find(pos) != a.end()) m++;
    }
    cout << ans << endl;
}
int main(){
    solve();
    return 0;
}