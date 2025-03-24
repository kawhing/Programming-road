#include <iostream>
#include <vector>
using namespace std;
// vector的赋值

// 容器遍历打印
void printvector(vector<int>v){
    for(vector<int>::iterator it =  v.begin(); it < v.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}
void test01(){
    vector<int> v1;
    for(int i = 0; i < 10; ++i)
        v1.push_back(i);
    printvector(v1);
    //赋值 operator=
    vector<int>v2;
    v2 = v1;
    printvector(v2);
    // assign
    vector<int>v3;
    v3.assign(v1.begin(), v1.end());
    printvector(v3);
    // n个elem方式赋值
    vector<int>v4;
    v4.assign(10, 100);
    printvector(v4);
}

int main(){
    test01();
    return 0;
}