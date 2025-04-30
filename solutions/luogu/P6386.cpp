#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c, d, ans = 0;
void barg(ll man){
    ll ans = 0;
    if(man%(a+b) <= a &&  man%(a+b) > 0) ++ans;
    if(man%(c+d) <= c && man%(c+d) > 0) ++ ans;
    if(ans == 0) cout << "none" << endl;
    else if(ans == 1) cout << "one" << endl;
    else cout << "both" << endl;
}
void solve(){
    cin >> a >> b >> c >> d;
    vector<ll> post(3);
    cin >> post[0] >> post[1] >> post[2];
    for(ll i = 0; i < 3; ++i){
        barg(post[i]);
    }
}
int main(){
    solve();
    return 0;
}