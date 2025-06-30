#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int temp = 1;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n-i; ++j){
            if(temp < 10) cout << 0 << temp;
            else cout << temp;
            ++temp;
        }
        cout << endl;
    }
}
int main(){
    solve();
    return 0;
}