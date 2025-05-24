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
void test01(){
    list <int> l;
    cout << "尾插" << endl;
    for(int i = 0; i < 5; ++i) l.push_back(i+1);
    printList(l);
    cout << "头插" << endl;
    l.push_front(10);
    printList(l);
    cout << "尾删" << endl;
    l.pop_back();
    printList(l);
    cout << "头删" << endl;
    l.pop_front();
    printList(l);
    cout << "insert插入" << endl;
    list<int>::iterator it = l.begin();
    l.insert(++it, 100);
    printList(l);
    cout << "删除" << endl;
    it = l.begin();
    l.erase(++it);
    printList(l);
    cout << "移除" << endl;
    for(int i = 0; i < 3; ++i) l.push_back(1000);
    printList(l); 
    l.remove(1000);
    printList(l);
    cout << "清空" << endl;
    l.clear();
    printList(l);

}
int main(){
    test01();
    return 0;
}