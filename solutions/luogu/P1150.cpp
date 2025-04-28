#include <iostream>
using namespace std;
/*peter的烟
    # Peter 的烟

## 题目背景

**温馨提醒：吸烟有害健康，请勿尝试吸烟！**

## 题目描述

Peter 有 $n$ 根烟，他每吸完一根烟就把烟蒂保存起来，$k$（$k>1$）个烟蒂可以换一个新的烟，那么 Peter 最终能吸到多少根烟呢？

与某些脑筋急转弯不同的是，Peter 并不能从异次元借到烟蒂，抽完后再还回去。

## 输入格式

每组测试数据一行包括两个整数 $n, k$（$1 < n, k \le 10^8$）。

## 输出格式

对于每组测试数据，输出一行包括一个整数表示最终烟的根数。

*/
int main(){
    int n, k;
    cin >> n >> k;
    int sum = n;
    while(n >= k){
        sum += n / k;
        n = n % k + n / k;
    }
    cout << sum << endl;
}