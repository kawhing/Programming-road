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
        s1.insert(5-i+1);
    //所有元素在插入就自动排序,且不允许插入重复值
    printSet(s1);
    set<int> s2(s1);
    printSet(s2);

    set<int> s3;
    s3 = s2;
    printSet(s3);
}
int main(){
    test01();
    return 0;
}