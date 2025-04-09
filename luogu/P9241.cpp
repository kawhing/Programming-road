#include <iostream>
#include <vector>
using namespace std;

int n;
struct Plane {
    int t, d, l;  // 到达时间，可盘旋时间，降落所需时间
};
vector<Plane> planes;
vector<bool> used;  // 标记飞机是否已安排

// DFS函数尝试安排飞机降落
bool dfs(int dep, int cur_time) {
    // 所有飞机都已安排
    if (dep == n) return true;
    for (int i = 0; i < n; i++) {
        // 跳过已安排的飞机和无法在当前时间安排的飞机
        if (used[i] || cur_time > planes[i].t + planes[i].d) {
            continue;
        }
        // 计算实际开始降落时间（不早于飞机到达时间）
        int start_time = max(cur_time, planes[i].t);
        // 如果超过了最晚降落时间，则跳过
        if (start_time > planes[i].t + planes[i].d) {
            continue;
        }
        used[i] = true;
        // 递归尝试安排下一架飞机
        if (dfs(dep + 1, start_time + planes[i].l)) {
            return true;
        }
        used[i] = false;  // 回溯
    }
    
    return false;
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        cin >> n;
        planes.resize(n);
        used.resize(n);
        
        for (int i = 0; i < n; i++) {
            cin >> planes[i].t >> planes[i].d >> planes[i].l;
            used[i] = false;  // 初始化为未使用
        }
        
        bool result = dfs(0, 0);
        cout << (result ? "YES" : "NO") << endl;
    }
    
    return 0;
}