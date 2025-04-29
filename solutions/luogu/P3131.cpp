#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ll n;
	cin >> n;
	vector<ll> a(n+1), sum(n+1), mp(7, -1);
	for(ll i = 1; i <= n; ++i) cin >> a[i];
	mp[0] = 0;
	ll ans = 0;
	for(ll i = 1; i <= n; ++i){
		sum[i] = (sum[i-1]+a[i]) % 7;
		if(mp[sum[i]] != -1)
			ans = max(ans, i-mp[sum[i]]);
		else mp[sum[i]] = i;
	}
	cout << ans << endl;
	return 0;
}