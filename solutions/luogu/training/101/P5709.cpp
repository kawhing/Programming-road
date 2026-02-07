#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int isBigZero(ll num){
	return num > 0;
}

void solve(){
	ll m, t, s;
	cin >> m >> t >> s;
	if(t == 0){
        cout << 0 << endl;
        return;
    }			
	ll eatNum = s / t + isBigZero(s % t);
	ll ans = m - eatNum;
    if(ans < 0) ans = 0;
	cout << ans << endl;
}

int main(){
	solve();
	return 0;
}