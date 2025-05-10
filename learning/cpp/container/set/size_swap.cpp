#include <iostream>
#include <set>
using namespace std;
void printSet(set<int>&s){
    for(set<int>::iterator it = s.begin(); it != s.end(); ++it)
        cout << *it << " ";
    cout << endl;
}
void test01(){
    set<int> s1, s2;
    for(int i = 0; i < 3; ++i){
        s1.insert(i+1);
        s2.insert(i*10);
    }
    if(!s1.empty()) cout << "s1不为空" << endl;
    else cout << "s1为空" << endl;
    cout << "交换前:" << endl;
    printSet(s1);
    printSet(s2);
    cout << "交换后:" << endl;
    s1.swap(s2);
    printSet(s1);
    printSet(s2);
}
int main(){
    test01();
    return 0;
}