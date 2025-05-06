#include <bits/stdc++.h>
using  namespace std;
typedef long long ll;

void solve(){
    vector<ll> nums(3);
    cin >> nums[0] >> nums[1] >> nums[2];
    for(ll i = 0; i < 3; ++i){
        string s = to_string(nums[i]);
        ll sSize = s.size();
        if(sSize <= 8){
            s.insert(s.begin(), 8-sSize,' ');
        }
        if(i == 2){
            cout << s;
        }else{
            cout << s << " ";
        }
    }
    
}
int main(){
    solve();
    return 0;
}