#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void solve(){
        ll n, q;
        cin >> n >> q;
        map<string, string> que;
        //vector<vector<string>> que;
        for(ll i = 0; i < n; ++i){
                string question, ans;
                cin >> question >> ans;
                que[question] = ans;
        }
        while(q--){
                string question;
                cin >> question;
                vector<string> ans(4);
                for(int i = 0; i < 4; ++i) cin >> ans[i];
		char flag = 'A';
                for(int i = 0; i < 4; ++i){
                        if(que[question] == ans[i]){
                                flag = 'A' + i;
                                break;
                        }                
                }
                cout << flag << endl; 
        }
}
int main(){
        solve();
        return 0;
}
