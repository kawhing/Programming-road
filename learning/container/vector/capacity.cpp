#include <iostream>
#include <vector>
using namespace std;
//vector容器的容量和大小操作

// 遍历打印vector容器
void printvector(vector<int>v){
    for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

void test01(){
    vector<int>v1;
    for(int i = 0; i < 10; ++i)
        v1.push_back(i);
    printvector(v1);

    if(v1.empty()){//容器为空
        cout << "v1容器为空" << endl;
    }else{
        cout << "v1容器不为空" << endl;
        cout << "v1容器的容量为 : " << v1.capacity() << endl;
        cout << "v1容器的大小为 : " << v1.size() << endl;
    }
    //重新指定容器大小
    v1.resize(15, 100);
    printvector(v1);// 如果指定的大小比原来的长会用0填充
    //如果指定的大小比原来的短会删除多余的元素
    v1.resize(5);
    printvector(v1);
}

int main(){
    test01();
    return 0;
}