#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void myPrint(int val){
    cout << val << " ";
}
void test01(){
    vector<int> v = {1, 3, 5, 2, 7, 6, 9};
    cout << "反转前" << endl;
    for_each(v.begin(), v.end(), myPrint);
    cout << endl << "反转后:"<< endl;
    reverse(v.begin(), v.end());
    for_each(v.begin(), v.end(), myPrint);
    cout << endl;
}
int main(){
    test01();
    return 0;
}