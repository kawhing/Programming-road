#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string maxname(map<string, ll> &names, map<string, ll>::iterator it){
    ll sum = 0;
    for(map<string, ll>::iterator it1 = names.begin(); it1 != names.end();++it1){
        if(it1 == it) continue;
        sum += it1->second;
    }
    if(it->second-1 > sum) {
        return it->first;
    }
    return "";
}
void solve(){
    ll n, ans = 0;
    cin >> n;
    map<string, ll> names;
    for(ll i = 0; i < n; ++i){
        string name;
        cin >> name;
        if(names.find(name) != names.end()){
            names[name]++;
            if(names[name] >= 2){
                auto it = names.find(name);
                if(maxname(names, it) == name) ++ans;
            }
        }
        else names[name] = 1;
        
        
    }
    cout << ans << endl;
}
int main(){
    solve();
    return 0;
}
