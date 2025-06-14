#include<bits/stdc++.h>
using namespace std;
void solve(){
    double xa, xb, ya, yb;
    cin >> xa >> ya >> xb >> yb;
    double ans = sqrt((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb));
    printf("%.3f", ans);
}
int main(){
    solve();
    return 0;
}
