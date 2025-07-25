#include <bits/stdc++.h>
using namespace std;

void solve(){
    int N, Na, Nb;
    cin >> N >> Na >> Nb;
    vector<int> A(Na), B(Nb), ans(2, 0);
    for(int i = 0; i < Na; ++i) cin >> A[i];
    for(int i = 0; i < Nb; ++i) cin >> B[i];
    vector<vector<int>> compare = { // 0 -> 平 1 -> 甲输乙 2 -> 甲胜乙
        {0, 1, 2, 2, 1},
        {2, 0, 1, 2, 1},
        {1, 2, 0, 1, 2},
        {1, 1, 2, 0, 2},
        {2, 2, 1, 1, 0}
    };
    int index = 0;
    while(N--){
        int ia, ib;
        if((index + 1) % Na == 0) ia = Na - 1;
        else ia = ((index + 1) % Na) - 1;
        if((index + 1) % Nb == 0) ib = Nb - 1;
        else ib = ((index + 1) % Nb) - 1;
    
        if(compare[A[ia]][B[ib]] == 1) ++ans[1];
        else if(compare[A[ia]][B[ib]] == 2) ++ans[0];
        ++index;
    }
    cout << ans[0] << " " << ans[1];
}
int main(){
    solve();
    return 0;
}