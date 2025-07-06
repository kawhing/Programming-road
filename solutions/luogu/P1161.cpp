#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<bool> lantern(2000001, false);
    while(n--){
        double a;
        int t;
        cin >> a >> t;
        for(int i = 1; i <= t; ++i){
            lantern[int(a*i)] = !lantern[int(a*i)];
        }
    }
    for(int i = 0; i < lantern.size(); ++i)
        if(lantern[i]){
            cout << i << endl;
            return;
        }
}
int main(){
    solve();
    return 0;
}