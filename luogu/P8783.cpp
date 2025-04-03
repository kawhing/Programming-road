#include <iostream>
#include <vector>
using namespace std;

void test(){
    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<int>> array(m, vector<int>(n));
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cin >> array[i][j];
        }
    }
    vector<vector<long long>> prefix(m + 1, vector<long long>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            prefix[i][j] = array[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }
    long long count = 0;
    for (int i1 = 1; i1 <= m; ++i1) {
        for (int j1 = 1; j1 <= n; ++j1) {
            // 枚举子矩阵的右下角
            for (int i2 = i1; i2 <= m; ++i2) {
                for (int j2 = j1; j2 <= n; ++j2) {
                    // 计算子矩阵的和
                    long long sum = prefix[i2][j2] - prefix[i2][j1-1] - prefix[i1-1][j2] + prefix[i1-1][j1-1];
                    if (sum <= k) {
                        count++;
                    } else {
                        break; // 如果当前j2使得和超过k，更大的j2也会超过k
                    }
                }
            }
        }
    }
    cout << count << endl;
}
int main(){
    test();
    return 0;
}