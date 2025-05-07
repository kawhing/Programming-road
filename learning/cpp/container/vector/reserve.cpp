#include <iostream>
#include <vector>
using namespace std;
//vector容器 预留空间
void test01(){
    vector<int> v;
    v.reserve(100000); //预留100000个空间
    int num = 0;
    int *p = NULL;
    for(int i = 0; i < 100000; ++i){
        v.push_back(i);
        if(p != &v[0]){
            p = &v[0];
            num++;
        }
    }
    cout << num << endl;
}
int main(){
    test01();
    return 0;
}