#include <iostream>
#include <map>
using namespace std;
void printMap(map<int, int>m){
    for(map<int, int>::iterator it = m.begin(); it != m.end(); ++it){
        cout << it->first << " = " << it->second << " ";
    }
    cout << endl;
}
void test01(){
    map<int, int> m;
    m.insert(pair<int, int> (1, 10));
    m.insert(pair<int, int> (2, 20));
    m.insert(pair<int, int> (3, 30));
    m.insert(pair<int, int> (4, 40));
    printMap(m);
    if(m.empty()) cout << "m为空" << endl;
    else{
        cout << "m不为空" << endl;
        cout << "m的大小为" << m.size() << endl;
    }
    map<int, int> m2;
    m2.insert(pair<int, int> (2, 10));
    m2.insert(pair<int, int> (3, 20));
    m2.insert(pair<int, int> (4, 30));
    cout << "交换前" << endl;
    cout << "map m" << endl;
    printMap(m);
    cout << "map m2" << endl;
    printMap(m2);

    cout << "交换后" << endl;
    m.swap(m2);
    cout << "map m" << endl;
    printMap(m);
    cout << "map m2" << endl;
    printMap(m2);
}
int main(){
    test01();
    return 0;
}