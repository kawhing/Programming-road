#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    string s;
    cin >> s;
    vector<ll> ans(8, 0);
    for(ll i = 0; i < s.size(); ++i){
        if(s[i] == 'A' || s[i] == 'Q' || s[i] == 'Z' || s[i] == '1') ++ans[0];
        else if(s[i] == '2' || s[i] == 'W' || s[i] == 'S' || s[i] == 'X') ++ans[1];
        else if(s[i] == '3' || s[i] == 'E' || s[i] == 'D' || s[i] == 'C') ++ans[2];
        else if(s[i] == '4' || s[i] == 'R' || s[i] == 'F' || s[i] == 'V') ++ans[3];
        else if(s[i] == '5' || s[i] == 'T' || s[i] == 'G' || s[i] == 'B') ++ans[3];
        else if(s[i] == '6' || s[i] == 'Y' || s[i] == 'H' || s[i] == 'N') ++ans[4];
        else if(s[i] == '7' || s[i] == 'U' || s[i] == 'J' || s[i] == 'M') ++ans[4];
        else if(s[i] == '8' || s[i] == 'I' || s[i] == 'K' || s[i] == ',') ++ans[5];
        else if(s[i] == '9' || s[i] == 'O' || s[i] == 'L' || s[i] == '.') ++ans[6];
        else ++ans[7];
    }
    for(ll i = 0; i < 7; ++i) cout << ans[i] << endl;
    cout << ans[7];
}
int main(){
    solve();
    return 0;
}