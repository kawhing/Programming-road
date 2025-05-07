#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
// deque容器的数据存取
void printDeque(const deque<int> d){
    for(deque<int>::const_iterator it = d.begin(); it < d.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

void test01(){
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(30);
    d1.push_back(20);
    d1.push_back(14);
    printDeque(d1);
    sort(d1.begin(), d1.end());
    printDeque(d1);
}

int main(){
    test01();
    return 0;
}