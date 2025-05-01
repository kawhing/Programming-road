#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    ll a, day = 1;
    cin >> a;
    while(a > 1){
        a /= 2;
        ++day;
    }
    if(a == 1)
        cout << day << endl;
}
int main(){
    solve();
    return 0;
}