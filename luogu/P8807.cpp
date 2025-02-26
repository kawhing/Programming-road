#include <iostream>
using namespace std;
typedef long long ll;

// 计算最大公约数
ll gcd(ll a, ll b) {
    while(b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// 计算两数的最小公倍数，注意防止溢出
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while(T--){
        ll n, m;
        cin >> n >> m;
        
        // 情况1：若 m >= n+2，则必然存在两个大于 n 的数，它们的余数都是 n
        if(m >= n + 2) {
            cout << "Yes\n";
            continue;
        }
        // 情况2：当 m >= 23 时，由于 lcm(2,...,m) 对于 n+1 (n<=1e9) 来说必然过大，不可能整除
        if(m >= 23) {
            cout << "Yes\n";
            continue;
        }
        
        // 否则 m <= n+1 且 m <= 22，枚举 2~m 计算 lcm
        ll L = 1;
        for(ll i = 2; i <= m; i++){
            L = lcm(L, i);
            // 这里 L 可能会迅速增大，不过 m 最大 22，不会有性能问题
            if(L > n + 1) break;
        }
        // 若 n+1 被 L 整除，则 f(x) 单射，各余数分别为 0, 1, 2, ..., m-1，无重复
        if((n + 1) % L == 0)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    return 0;
}
