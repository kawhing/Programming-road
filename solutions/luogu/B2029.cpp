#include <bits/stdc++.h>
#define PI 3.14
using namespace std;

void solve(){
    int h, r;
    cin >> h >> r;
    float ans = 20000 / (PI * r * r * h);
    if(ans > (int)ans)
        ans = (int)ans + 1;
    cout << ans << endl;
}

int main(){
    solve();
    return 0;
}