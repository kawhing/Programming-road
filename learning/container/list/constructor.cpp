#include <iostream>
#include <list>
using namespace std;
void printList(const list<int> l){
    for(list<int>::const_iterator it = l.begin(); it != l.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}
void test01(){
    //默认构造
    list<int> l1;
    for(int i = 0; i < 5; ++i)
        l1.push_back(i);
    printList(l1);
    //区间构造
    list<int> l2(l1.begin(), l1.end());
    printList(l2);
    //拷贝构造
    list<int> l3(l2);
    printList(l3);
    //n个element
    list<int> l4(10, 1000);
    printList(l4);
}
int main(){
    test01();
    return 0;
}