#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//常用拷贝和替代算法 replace
class Print{
    public:
        void operator()(int val){
            cout << val << " ";
        }
};
void test01(){
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "替换前:" << endl;
    for_each(v1.begin(), v1.end(), Print());
    cout << endl << "替换后:" << endl;
    replace(v1.begin(), v1.end(), 3, 2000);
    for_each(v1.begin(), v1.end(), Print());
    cout << endl;
}
int main(){
    test01();
    return 0;
}