#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    if(n * 5 >= 3 * n + 11)
        cout << "Luogu" << endl;
    else
        cout << "Local" << endl;     
}

int main(){
    solve();
    return 0;
}