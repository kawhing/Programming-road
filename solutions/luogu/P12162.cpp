#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isFiveSum(ll num){
    string str = to_string(num);
    num = 0;
    for(int i = 0; i < str.size(); ++i)
        num += str[i]-'0';
    if(num % 5 == 0) return true;
    return false;
}
void solve(){
    int ans = 0;
    for(ll i = 1; i < 202504; ++i)
        if(isFiveSum(i))
            ++ans;
    cout << ans << endl;
}
int main(){
    solve();
    return 0;
}