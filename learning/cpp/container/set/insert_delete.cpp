#include <iostream>
#include <set>
using namespace std;
void printSet(set<int>&s){
    for(set<int>::iterator it = s.begin(); it != s.end(); ++it)
        cout << *it << " ";
    cout << endl;
}
void test01(){
    set<int> s1;
    for(int i = 0; i < 5; ++i)
        s1.insert(i+1);
    printSet(s1);
    cout << "删除第一个" << endl;
    s1.erase(s1.begin());
    printSet(s1);
    cout << "删除4" << endl;
    s1.erase(4);
    printSet(s1);
    cout << "清空" << endl;
    s1.clear();
    printSet(s1);
}
int main(){
    test01();
    return 0;
}