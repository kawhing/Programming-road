#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;
//内建函数对象 关系仿函数
//大于 greater为例
class MyCompare{
    public:
        bool operator()(int v1, int v2){
            return v1 > v2;
        }
};
void test01(){
    vector<int> v;
    for(int i = 0; i < 5; ++i) v.push_back(i+1);
    //sort(v.begin(), v.end(), MyCompare());//自己实现
    sort(v.begin(), v.end(), greater<int>());//内建函数对象
    for(int nums : v) cout << nums << " ";
    cout << endl;
}
int main(){
    test01();
    return 0;
}