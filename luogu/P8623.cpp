#include <iostream>
#include <cmath>
using namespace std;

void test(){
    int w, m, n;
    cin >> w >> m >> n;
    
    // 计算行列索引
    int m_x = (m - 1) / w + 1;  // 行号从1开始
    int m_y = (m - 1) % w + 1;  // 列号从1开始
    
    int n_x = (n - 1) / w + 1;
    int n_y = (n - 1) % w + 1;
    
    // 处理蛇形排列（奇数行需要反转列的顺序）
    if(m_x % 2 == 0) m_y = w - m_y + 1;
    if(n_x % 2 == 0) n_y = w - n_y + 1;
    
    // 输出坐标和曼哈顿距离
    // cout << m_x << " " << m_y << " " << n_x << " " << n_y << endl;  // 调试用
    cout << abs(m_x - n_x) + abs(m_y - n_y) << endl;
}

int main(){
    test();
    return 0;
}