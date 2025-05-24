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
    cout << "插入" << endl;
    cout << "第一种" << endl;
    m.insert(pair<int, int>(1, 10));
    printMap(m);
    cout << "第二种" << endl;
    m.insert(make_pair<int, int>(2, 20));
    printMap(m);
    cout << "第三种" << endl;
    m.insert(map<int, int>::value_type(3, 30));
    printMap(m);
    cout << "第四种" << endl;
    m[4] = 40;
    printMap(m);
    cout << m[5] << endl;//不推荐这种做法，当访问不存在的键值，map容器会自动创建并赋值为0
    printMap(m);
    cout << "删除" << endl;
    cout << "第一种" << endl;
    m.erase(m.begin());
    printMap(m);
    cout << "第二种" << endl;
    m.erase(20);
    printMap(m);
    cout << "第三种" << endl;
    m.erase(m.begin(), m.end());
    printMap(m);
}
int main(){
    test01();
    return 0;
}