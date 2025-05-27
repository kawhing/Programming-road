#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    string line;
    ll ans = 0;
    getline(cin, line);
    for(char c : line){
        if(c == ' '){
            ++ans;
        }else{
            if(c <= 'o'){
                int temp = (int(c-'a')+1) % 3;
                if(temp == 0) ans += 3;
                else ans += temp;
            }else if(c >= 'p' && c <= 's'){
                ans += c-'p'+1;
            }else if(c >= 't' && c <= 'v'){
                ans += c-'t'+1;
            }else{
                ans += c-'w'+1;
            }
        }
    }
    cout << ans << endl;
}
int main(){
    solve();
    return 0;
}