#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

void solve(){
    ll t, a, b, c, k;
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> k;
        for(int i = 0; i < min(k, 50LL); ++i){
            ll temp_a = (b+c)/2, temp_b = (a+c)/2, temp_c = (a+b)/2;
            if(temp_a == a && temp_b == b && temp_c == c) {
                break;
            }
            
            a = temp_a, b = temp_b, c = temp_c;
        }
        
        cout << a << " " << b << " " << c << endl;
    }
}

int main(){
    solve();
    return 0;
}