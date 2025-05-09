#include <iostream>
#include <list>
using namespace std;
//list容器数据存取
void printList(const list<int> l){
    if(l.size() == 0){
        cout << "list为空" << endl;
        return;
    }
    for(list<int>::const_iterator it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;
}
void test01(){
    list<int> l;
    for(int i = 0; i < 5; ++i) l.push_back(i+1);
    printList(l);
    cout << "第一个元素: " << l.front() << endl;
    cout << "最后一个元素: " << l.back() << endl;
    //不可以使用[]和at访问list容器中的元素
    //因为list本质上是链表,不连续
    //支持双向不支持随机访问
}
int main(){
    test01();
    return 0;
}