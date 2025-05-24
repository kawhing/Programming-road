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
    for(int i = 0; i < 5; ++i)
        m.insert(pair<int, int> (i, i*10));
    printMap(m);
    //查找
    int target = 1;
    if(m.find(target) != m.end()){
        cout << "查到元素" << " " << target << " = " << m[1] << endl;
    }else{
        cout << "未找到元素" << target << endl;
    }
    //计数
    //map容器不允许插入重复key元素
    //multimap的统计可能大于1
    int num = m.count(target);
    cout << target << " 的数量为 " << num << endl;
}
int main(){
    test01();
    return 0;
}