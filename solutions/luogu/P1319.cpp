#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    string line;
    getline(cin, line);
    int number;
    istringstream iss(line);
    vector<ll> zipNum;
    while(iss >> number){
        zipNum.push_back(number);
    }
    vector<ll> ans;
    for(ll i = 1; i < zipNum.size(); ++i){
        for(int j = 0; j < zipNum[i]; ++j){
            if(i % 2 == 1) ans.push_back(0);
            else ans.push_back(1);
        }
    }
    for(ll i = 0; i < ans.size(); ++i){
        cout << ans[i];
        if(i % zipNum[0] == zipNum[0]-1) cout << endl;
    }
}
int main(){
    solve();
    return 0;
}