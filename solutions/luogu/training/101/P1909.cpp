#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll costPencil(ll pencil, ll cost, ll n){
    ll count = n / pencil;
    if(n % pencil) ++count;
    return count * cost;
}
void solve(){
    ll n;
    cin >> n;
    ll pencil1[2], pencil2[2], pencil3[2];
    cin >> pencil1[0] >> pencil1[1];
    cin >> pencil2[0] >> pencil2[1];
    cin >> pencil3[0] >> pencil3[1];
    ll cost1 = costPencil(pencil1[0], pencil1[1], n);
    ll cost2 = costPencil(pencil2[0], pencil2[1], n);
    ll cost3 = costPencil(pencil3[0], pencil3[1], n);
    ll ans = min(min(cost1, cost2), cost3);
    cout << ans << endl;
}
int main() {
    solve();
    return 0;
}
