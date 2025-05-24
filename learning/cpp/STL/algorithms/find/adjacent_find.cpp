#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//常用查找算法 adjacent_find
//查找相邻重复元素
void test01(){
    vector<int> v = {1, 2, 5, 5, 6, 7, 9};
    vector<int>::iterator it =  adjacent_find(v.begin(), v.end());
    if(it != v.end()) cout << "找到相邻重复元素:" << *it << endl;
    else cout << "没有找到相邻重复元素" << endl;
}
int main(){
    test01();
    return 0;
}