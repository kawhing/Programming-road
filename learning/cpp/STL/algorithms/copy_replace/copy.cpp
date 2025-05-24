#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//常用拷贝和替换算法 copy
void print(int val){
    cout << val << " ";
}
void test01(){
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9}, v2;
    v2.resize(v1.size());
    copy(v1.begin(), v1.end(), v2.begin());
    for_each(v2.begin(), v2.end(), print);
    cout << endl;
}
int main(){
    test01();
    return 0;
}