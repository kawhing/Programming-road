#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//常用遍历算法 transform
class Transform{
    public:
        int operator()(int element){
            return element; 
        }
};
class MyPrint{
    public:
        void operator()(int val){
            cout << val << " ";
        }
};

void test01(){
    vector<int> v = {1, 2, 3, 4, 5}, target;
    target.resize(v.size());//搬运前需要先开辟空间,否则会失败
    transform(v.begin(), v.end(), target.begin(), Transform());
    for_each(target.begin(), target.end(), MyPrint());
    cout << endl;
}
int main(){
    test01();
    return 0;
}