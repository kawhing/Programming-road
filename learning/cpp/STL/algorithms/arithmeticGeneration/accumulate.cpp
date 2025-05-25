#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
//常用算术生成算法 accumulate
//计算区间内容器元素累计总和
void test01(){
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << accumulate(v.begin(), v.end(), 0) << endl; 
}   
int main(){
    test01();
    return 0;
}