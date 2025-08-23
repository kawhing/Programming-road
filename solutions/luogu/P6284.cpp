#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x, n, ans = 0, sum = 0; //x: MB n: months
    cin >> x >> n;
    vector<int> months(n);
    for(int i = 0; i < n; ++i){
        cin >> months[i];
        sum += months[i];
    }
    ans = x*(n+1)-sum;
    cout << ans << endl;
}
int main(){
    solve();
    return 0;
}