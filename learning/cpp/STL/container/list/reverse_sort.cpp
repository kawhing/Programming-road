#include <iostream>
#include <list>
using namespace std;
void printList(const list<int> l){
    if(l.size() == 0){
        cout << "list为空" << endl;
        return;
    }
    for(list<int>::const_iterator it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;
}
bool myCompare(int v1, int v2){
    //降序
    return v1>v2;
}
void test01(){
    list<int> l;
    for(int i = 0; i < 5; ++i) l.push_back(i+1);
    cout << "反转前" << endl;
    printList(l);
    cout << "反转后" << endl;
    l.reverse();
    printList(l);
    cout << "排序前" << endl;
    printList(l);
    cout << "排序后" << endl;
    //所有不支持随机访问迭代器的容器不支持sort库函数
    //但内部会提供对应的算法
    cout << "升序:" << endl;
    l.sort();//从小到大
    printList(l);
    cout << "降序:" << endl;
    l.sort(myCompare);//从大到小
    printList(l);
}
int main(){
    test01();
    return 0;
}