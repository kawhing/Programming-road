#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//常用排序算法 merge
void myPrint(int val){
    cout << val << " ";
}
void test01(){
    vector<int> v1, v2;
    for(int i = 0; i < 10; ++i){
        v1.push_back(i);
        v2.push_back(i+1);
    }
    vector<int> target;
    target.resize(v1.size()+v2.size());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), target.begin());
    for_each(target.begin(), target.end(), myPrint);
    cout << endl;
}
int main(){
    test01();
    return 0;
}