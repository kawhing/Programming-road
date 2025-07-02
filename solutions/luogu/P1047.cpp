#include <bits/stdc++.h>
using namespace std;

struct zone{
    int u, v;
};
void solve(){
    int l, m, ans = 0;
    cin >> l >> m;
    vector<bool> line(l+1, true);
    vector<zone> zones(m);
    for(int i = 0; i < m; ++i){
        cin >> zones[i].u >> zones[i].v;
        for(int j = zones[i].u; j <= zones[i].v; ++j) line[j] = false;
    }
    for(bool i : line)
        if(i) ++ans;
    cout << ans << endl;
}
int main(){
    solve();
    return 0;
}