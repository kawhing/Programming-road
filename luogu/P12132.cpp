#include <bits/stdc++.h>
using  namespace std;
typedef long long ll;
//这道题挖了个坑
int main(){
    ll ans = 0, n;
    cin >> n;
    for(ll i = 1; i <= n; ++i){
        ll x;
        cin >> x;
        if(x > 1) ++ans;
    }
    cout << ans;
    return 0;
}