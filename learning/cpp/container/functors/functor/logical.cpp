#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
//内建函数对象 逻辑仿函数
//在实际开发中基本上用不到
void test01(){
    vector<bool> v;
    v.push_back(true);
    v.push_back(true);
    v.push_back(false);
    v.push_back(true);
    v.push_back(true);
    for(bool flag : v) cout << flag << " ";
    cout << endl;
    //利用逻辑非 将容器v搬运到容器v2中,并进行取反操作
    vector<bool> v2;
    v2.resize(v.size());
    transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());
    for(bool flag : v2) cout << flag << " ";
    cout << endl;
}
int main(){
    test01();
    return 0;
}