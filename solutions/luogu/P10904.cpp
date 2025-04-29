#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);

    // 读取矿洞坐标
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 去重并排序
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    // 滑动窗口计算最大矿石数
    int max_minerals = 0;
    int left = 0;
    for (int right = 0; right < a.size(); right++) {
        // 确保窗口内的移动距离不超过 m
        while (a[right] - a[left] > m) {
            left++;
        }
        // 更新最大矿石数
        max_minerals = max(max_minerals, right - left + 1);
    }

    // 输出结果
    cout << max_minerals << endl;

    return 0;
}