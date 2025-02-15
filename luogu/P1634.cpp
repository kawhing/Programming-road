#include <iostream>
using namespace std;
//禽兽患传染病了。一个禽兽会每轮传染 x 个禽兽。试问 n 轮传染后有多少禽兽被传染？
int main(){
    int x, n;
    long long result = 1; // 使用 long long 以防止结果溢出
    cin >> x >> n;
    for(int i = 0; i < n; ++i){
        result *= (x+1);
    }
    cout << result << endl;
    return 0;
}