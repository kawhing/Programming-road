#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k, n;
    cin >> k >> n;
    
    // 存储每次训练中奶牛的排名
    // ranks[i][j] 表示在第i次训练中排名为j的奶牛的编号
    vector<vector<int>> ranks(k, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ranks[i][j];
        }
    }
    
    int consistent_pairs = 0;
    
    // 检查每一对奶牛
    for (int cow1 = 1; cow1 <= n; cow1++) {
        for (int cow2 = 1; cow2 <= n; cow2++) {
            if (cow1 == cow2) continue; // 跳过相同的奶牛
            
            bool always_better = true;
            
            // 检查在所有训练中cow1是否始终比cow2表现更好
            for (int session = 0; session < k; session++) {
                int pos1 = -1, pos2 = -1;
                
                // 找到cow1和cow2在当前训练中的位置
                for (int pos = 0; pos < n; pos++) {
                    if (ranks[session][pos] == cow1) pos1 = pos;
                    if (ranks[session][pos] == cow2) pos2 = pos;
                }
                
                // 如果cow1的排名不比cow2好（即位置值更大），则不一致
                if (pos1 >= pos2) {
                    always_better = false;
                    break;
                }
            }
            
            if (always_better) consistent_pairs++;
        }
    }
    
    cout << consistent_pairs << endl;
    return 0;
}