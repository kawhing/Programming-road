#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n;
int main() {
	cin >> t;
	while(t--){
		string s;
		cin >> n;
		cin >> s;
		ll noPatch = 0, minNoPatch = 0;
		for(ll i = 0; i < 2*n; ++i){
			if(i%2 == 0){
				if(s[i] != 'A') ++noPatch;
			}else{
				if(s[i] != 'B') ++noPatch;
			}
		}
		minNoPatch = noPatch;
		noPatch = 0;
		for(ll i = 0; i < 2*n; ++i){
			if(i%2 == 0){
				if(s[i] != 'B') ++noPatch;
			}else{
				if(s[i] != 'A') ++noPatch;
			}
		}
		minNoPatch = min(minNoPatch, noPatch);
		cout << minNoPatch/2 << endl;
	}
	return 0;
}