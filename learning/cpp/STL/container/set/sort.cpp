#include <iostream>
#include <set>
using namespace std;
class Compare{
    public:
        bool operator()(int v1, int v2){
            return v1 > v2;
        }
};
void printSet(set<int, Compare>&s){
    for(set<int, Compare>::iterator it = s.begin(); it != s.end(); ++it)
        cout << *it << " ";
    cout << endl;
}
void test01(){
    set<int, Compare> s;
    for(int i = 0; i < 5; ++i)
        s.insert(i+1);
    cout << "排序后" << endl;
    printSet(s); 
}
int main(){
    test01();
    return 0;
}