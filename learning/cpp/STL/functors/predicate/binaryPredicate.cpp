#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//二元谓词
class MyCompare{
    public:
        bool operator()(int v1, int v2){
            return v1 > v2;
        }
};
void test01(){
    vector<int> v;
    for(int i = 0; i < 10; ++i) v.push_back(i+1);
    //使用函数对象 改变算法策略,变为排序规则为从大到小
    sort(v.begin(), v.end(), MyCompare());
    for(int num : v) cout << num << " ";
    cout << endl;
}
int main(){
    test01();
    return 0;
}