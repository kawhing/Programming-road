#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 计算最大公约数
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// 计算两个数的最小公倍数
int lcm2(int a, int b) {
    return (long long)a / gcd(a, b) * b;
}

// 计算三个数的最小公倍数
int lcm3(int a, int b, int c) {
    return lcm2(lcm2(a, b), c);
}

void solve() {
    int n;
    cin >> n;
    vector<int> rock(n);
    for(int i = 0; i < n; ++i)
        cin >> rock[i];
    
    int maxS = 0;
    vector<int> bestCombo = {0, 0, 0};
    
    for(int i = 0; i < n-2; ++i) {
        for(int j = i+1; j < n-1; ++j) {
            for(int k = j+1; k < n; ++k) {
                int a = rock[i], b = rock[j], c = rock[k];
                
                // 计算各部分的LCM
                int lcm_ab = lcm2(a, b);
                int lcm_ac = lcm2(a, c);
                int lcm_bc = lcm2(b, c);
                int lcm_abc = lcm3(a, b, c);
                
                // 计算精美程度S
                long long S = (long long)a * b * c * lcm_abc / 
                            ((long long)lcm_ab * lcm_ac * lcm_bc);
                
                // 更新最大值
                if (S > maxS) {
                    maxS = S;
                    bestCombo = {a, b, c};
                } else if (S == maxS) {
                    // 如果S相同，选择字典序最小的
                    vector<int> currCombo = {a, b, c};
                    sort(currCombo.begin(), currCombo.end());
                    sort(bestCombo.begin(), bestCombo.end());
                    if (currCombo < bestCombo) {
                        bestCombo = currCombo;
                    }
                }
            }
        }
    }
    
    // 输出结果（确保升序排列）
    sort(bestCombo.begin(), bestCombo.end());
    cout << bestCombo[0] << " " << bestCombo[1] << " " << bestCombo[2] << endl;
}

int main() {
    solve();
    return 0;
}