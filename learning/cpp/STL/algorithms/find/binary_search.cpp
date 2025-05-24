#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//常用查找算法 binary_search
void test01(){
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    bool ret = binary_search(v.begin(), v.end(), 7);
    if(ret) cout << "找到了" << endl;
    else cout << "未找到" << endl;
}
int main(){
    test01();
    return 0;
}