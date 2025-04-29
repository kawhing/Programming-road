#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
//目前时间复杂高，洛谷上也没有人发完美题解
int main(){
	ll t;
	cin >> t;
	while(t--){
		ll a, b, c, k;
		cin >> a >> b >> c >> k;
		for(ll i = 0; i < k; ++i){
			//ll tmp1 = a, tmp2 = b, tmp3 = c;
			ll tmp1 = (b+c)/2;
			ll tmp2 = (a+c)/2;
			ll tmp3 = (a+b)/2;
			a = tmp1, b = tmp2, c = tmp3;
		}
		cout << a << " " << b << " " << c << endl;
	}	
	return 0;
}
