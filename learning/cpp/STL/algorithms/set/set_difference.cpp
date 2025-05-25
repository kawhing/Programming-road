#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//常用集合算法 set_difference
//求两个容器的差集
void print(int val){
    cout << val << " ";
}
void test01(){
    vector<int> v1 = {1, 2, 3, 4, 5}, v2 = {2, 3, 4}, target;
    target.resize(min(v1.size(), v2.size()));
    vector<int>::iterator it = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), target.begin());
    for_each(target.begin(), it, print);
    cout << endl;
}
int main(){
    test01();
    return 0;
}