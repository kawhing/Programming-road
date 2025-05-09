#include <iostream>
#include <list>
using namespace std;
void printList(const list<int> l){
    for(list<int>::const_iterator it = l.begin(); it != l.end(); ++it)
        cout << *it << " ";
    cout << endl;
}
void test01(){
    list<int> l1;
    for(int i = 0; i < 5; ++i) l1.push_back(i+1);
    printList(l1);
    if(l1.empty()) cout << "l1为空" << endl;
    else{
        cout << "l1不为空" << endl;
        cout << "l1的大小为: " << l1.size() << endl;
    }
    cout << "重新指定大小" << endl;
    l1.resize(10);
    printList(l1);
}
int main(){
    test01();
    return 0;
}