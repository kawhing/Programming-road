#include <iostream>
#include <vector>
using namespace std;
//vector容器的插入和删除

// 遍历打印vector容器
void printvector(vector<int>v){
    for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << endl;
}
void test01(){
    vector<int>v1;
    //尾插
    for(int i = 0; i < 5; ++i)
        v1.push_back(10*(i+1));
    printvector(v1);
    //尾删
    v1.pop_back();
    printvector(v1);
    //插入
    v1.insert(v1.begin(), 2, 1000);
    printvector(v1);
    //删除
    v1.erase(v1.begin());
    printvector(v1);
    //清空
    v1.clear();
    printvector(v1);
}

int main(){
    test01();
    return 0;
}