#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> cards(n);
    int cnt0 = 0, cnt5 = 0;
    
    // 统计 0 和 5 的个数
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
        if (cards[i] == 0) cnt0++;
        else cnt5++;
    }
    if(cnt0 == 0) cout << -1 << endl;
    else if(cnt5 >= 9 && cnt0 > 0){
        int temp = cnt5/9*9;
        for(int i = 0; i < temp; ++i){
            cout << 5;
        }
        for(int i = 0; i < cnt0; ++i) cout << 0;
    }else if(cnt5 < 9 && cnt0 > 0) cout << 0 << endl;
    return 0;
}