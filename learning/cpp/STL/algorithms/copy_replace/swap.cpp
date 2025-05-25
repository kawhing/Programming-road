#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//常用拷贝和替换算法 swap
void print(int val){
    cout << val << " ";
}
void test01(){
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9}, v2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "交换前:" << endl;
    for_each(v1.begin(), v1.end(), print);
    cout << endl;
    for_each(v2.begin(), v2.end(), print);
    cout << endl;
    cout << "交换后:" << endl;
    swap(v1, v2);
    for_each(v1.begin(), v1.end(), print);
    cout << endl;
    for_each(v2.begin(), v2.end(), print);
    cout << endl;
}
int main(){
    test01();
    return 0;
}