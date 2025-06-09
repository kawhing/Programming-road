#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
void solve(){
    ll w, x, h, q, ans = 0;
    cin >> w >> x >> h;
    cin >> q;
    vector<bool> used(w*x*h, false);
    while(q--){
        vector<ll> tmp1(3), tmp2(3);
        cin >> tmp1[0] >> tmp1[1] >> tmp1[2];
        cin >> tmp2[0] >> tmp2[1] >> tmp2[2];
        for(ll i = tmp1[0]; i <= tmp2[0]; ++i){
        	for(ll j = tmp1[1]; j <= tmp2[1]; ++j){
        		for(ll k = tmp1[2]; k <= tmp2[2]; ++k){
        			if(used[(i-1)*x*h+(j-1)*h+k-1] == false){
        			    used[(i-1)*x*h+(j-1)*h+k-1] = true;
        			    ++ans;	
        			}	
        		}
        	}
        }
    }
    cout << w*x*h-ans << endl;
}
int main(){
    solve();
    return 0;
}