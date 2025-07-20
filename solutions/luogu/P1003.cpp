#include <bits/stdc++.h>
using namespace std;
struct Carpet{
    int a, b, g, k;
};
bool isBlongTo(Carpet carpet, int x, int y){
    if(carpet.a > x || carpet.a + carpet.g - 1 < x) return false;
    if(carpet.b > y || carpet.b + carpet.k - 1 < y) return false;
    return true;
}
void solve(){
    int n;
    cin >> n;
    vector<Carpet> carpets(n);
    int x, y;
    for(int i = 0; i < n; ++i)
        cin >> carpets[i].a >> carpets[i].b >> carpets[i].g >> carpets[i].k;
    cin >> x >> y;
    for(int i = n - 1; i >= 0; --i){
        if(isBlongTo(carpets[i], x, y)){
            cout << i + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}
int main(){
    solve();
    return 0;
}