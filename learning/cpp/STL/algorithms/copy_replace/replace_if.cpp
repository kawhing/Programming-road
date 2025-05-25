#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//常用拷贝和替换算法 replace_if
class MyPrint{
    public:
        void operator()(int val){
            cout << val << " ";
        }
};
class GreaterThirty{
    public:
        bool operator()(const int val){
            return val > 30;
        }
};
void test01(){
    vector<int> v = {10, 20, 30, 50, 40, 70, 60};
    //将大于30的替换为3000
    cout << "替换前:" << endl;
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;
    cout << "替换后:" << endl;
    replace_if(v.begin(), v.end(), GreaterThirty(), 3000);
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;    
}
int main(){
    test01();
    return 0;
}