#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    // 计算两只袋鼠之间的空位数
    int left_gap = b - a;
    int right_gap = c - b;
    // 最大移动次数就是最大空位数减1
    cout << max(left_gap, right_gap) - 1 << endl;
}
int main(){
    solve();
    return 0;
}