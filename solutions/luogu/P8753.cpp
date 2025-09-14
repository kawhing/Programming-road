#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        int r = (i * i) % n;
        if (2 * r < n) {
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}