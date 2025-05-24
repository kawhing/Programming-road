#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//常用排序算法 sort
void myPrint(int val){
    cout << val << " ";
}
void test01(){
    vector<int> v = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //利用sort进行升序
    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
    //改变为降序
    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}

int main(){
    test01();
    return 0;
}