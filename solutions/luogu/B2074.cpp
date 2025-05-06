#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b;
void solve(){
    ll day = 1;
    for(ll i = 0; i < b; ++i){
        day *= a;
        day %= 7;
    }
    vector<string> week = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    if(day == 0) cout << "Sunday" << endl;
    else cout << week[day-1];
}
int main(){
    cin >> a >> b;
    solve();
    return 0;
}