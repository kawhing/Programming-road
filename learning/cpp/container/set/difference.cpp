#include <iostream>
#include <set>
using namespace std;
void printSet(multiset<int>&s){
    for(set<int>::iterator it = s.begin(); it != s.end(); ++it)
        cout << *it << " ";
    cout << endl;
}
void test01(){
    set<int> s;
    pair<set<int>::iterator, bool> ret = s.insert(10);
    if(ret.second) cout << "第一次插入成功" << endl;
    else cout << "第一次插入失败" << endl;
    ret = s.insert(10);
    if(ret.second) cout << "第二次插入成功" << endl;
    else cout << "第二次插入失败" << endl; 
    multiset<int> ms;
    for(int i = 0; i < 5; ++i)
        ms.insert(10);
    printSet(ms);
}
int main(){
    test01();
    return 0;
}