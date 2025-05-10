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
    for(int i = 1; i <= 5; ++i)
        s1.insert(i);
    set<int>::iterator it = s1.find(5);
    if(it != s1.end()) cout << "找到元素" << *it << endl;
    else cout << "未找到" << endl;
    int num = s1.count(5);
    cout << "找到" << num << "个" << 5 << endl;
}
int main(){
    test01();
    return 0;
}