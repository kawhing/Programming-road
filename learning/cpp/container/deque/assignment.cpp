#include <iostream>
#include <deque>
using namespace std;

void printDeque(const deque<int> d){
    for(deque<int>::const_iterator it = d.begin(); it < d.end(); ++it)
        cout << *it << " ";
    cout << endl;
}
void test01(){
    deque<int> d;
    for(int i = 0; i < 10; ++i)
        d.push_back(i);
    printDeque(d);
    // operator= 赋值
    deque<int> d2;
    d2 = d;
    printDeque(d2);

    deque<int> d3;
    d3.assign(d.begin(), d.end());
    printDeque(d3);

    deque<int> d4(10, 100);
    printDeque(d4);
}
int main(){
    test01();
    return 0;
}