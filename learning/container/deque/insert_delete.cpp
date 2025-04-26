#include <iostream>
#include <deque>
using namespace std;

void printDeque(const deque<int> d){
    for(deque<int>::const_iterator it = d.begin(); it < d.end(); ++it)
        cout << *it << " ";
    cout << endl;
}
void test01(){
    deque<int> d1;
    // 尾插
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);
    printDeque(d1);
    // 头插
    d1.push_front(40);
    printDeque(d1);
    // 尾删
    d1.pop_back();
    printDeque(d1);
    // 头删
    d1.pop_front();
    printDeque(d1);
}
void test02(){
    deque<int> d1;
    d1.insert(d1.begin(), 2, 10000);
    printDeque(d1);

    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);
    d1.insert(d1.begin(), d2.begin(), d2.end());
    printDeque(d1);
}
void test03(){
    deque<int> d1;
    d1.push_back(1);
    d1.push_back(2);
    d1.push_back(3);
    printDeque(d1);
    deque<int>::iterator it = d1.begin();
    it += 2;
    d1.erase(it);
    printDeque(d1);
}
int main(){
    test01();
    return 0;
}