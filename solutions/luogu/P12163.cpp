#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isCould(ll num){
    string str = to_string(num);
    ll numSize = str.size();
    if(numSize < 4) return false;
    ll two = 0, zero = 0, five = 0; 
    for(char i : str){
        if(i == '2') two++;
        else if(i == '0') zero++;
        else if(i == '5') five++;
    }
    if(two >= 2 && zero >= 1 && five >= 1) return true;    
    return false;
}
void solve(){
    ll ans = 0;
    for(ll i = 1; i <= 20250412; ++i)
        if(isCould(i))
            ++ans;
    cout << ans << endl;
}
int main(){
    solve();
    return 0;
}