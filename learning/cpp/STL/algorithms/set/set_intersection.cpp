#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//常用集合算法 set_intersection
//求两个容器的交集
void print(int val){
    cout << val << " ";
}
void test01(){
    vector<int> v1 = {1, 2, 3, 4, 5}, v2 = {0, 1, 2, 3, 4}, target;
    target.resize(min(v1.size(), v2.size()));
    //获取交集
    vector<int>::iterator it = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), target.begin());
    //for_each(target.begin(), target.end(), print);//不用这个是由于，当交集的大小小于分配的时候会用0填充
    for_each(target.begin(), it, print);
    cout << endl;
}
int main(){
    test01();
    return 0;
}