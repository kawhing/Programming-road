#include <iostream>
#include <map>
using namespace std;
//自定义map容器的排序顺序
class Compare{
    public:
        bool operator()(int v1, int v2){
            return v1 > v2;
        }
};
void printMap(map<int, int, Compare>m){
    for(map<int, int, Compare>::iterator it = m.begin(); it != m.end(); ++it){
        cout << it->first << " = " << it->second << " ";
    }
    cout << endl;
}
void test01(){
    map<int, int, Compare> m;
    for(int i = 0; i < 5; ++i)
        m.insert(pair<int, int> (i, i*10));
    printMap(m);
    
}
int main(){
    test01();
    return 0;
}