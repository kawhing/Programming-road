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
    list<int> l1, l2, l3, l4;
    for(int i = 0; i < 5; ++i) l1.push_back(i+1);
    printList(l1);
    l2 = l1;
    printList(l2);
    l3.assign(l2.begin(), l2.end());
    l4.assign(10, 1000);
    printList(l3);
    printList(l4);
}
//交换
void test02(){
    list<int>l1, l2;
    for(int i = 0; i < 5; ++i) l1.push_back(i+1);
    l2.assign(10, 1000);
    cout << "交换前:" << endl;
    printList(l1);
    printList(l2);
    cout << "交换后:" << endl;
    l1.swap(l2);
    printList(l1);
    printList(l2);
}
int main(){
    test02();
    return 0;
}