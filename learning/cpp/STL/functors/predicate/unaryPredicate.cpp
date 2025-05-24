#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//仿函数 返回值类型是bool类型，称为谓词
//一元谓词
class lagerFive{
    public:
        bool operator()(int val){
            return val > 5;
        }
};
void test01(){
    vector<int> v;
    for(int i = 0; i < 10; ++i){
        v.push_back(i+1);
    }
    //查找容器中 有没有大于5的数字
    vector<int>::iterator it =  find_if(v.begin(), v.end(), lagerFive());
    if(it != v.end()){
        cout << "找到了大于5的数组为:" << *it << endl;
    }else cout << "未找到" << endl;
}
int main(){
    test01();
    return 0;
}