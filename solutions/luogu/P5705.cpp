#include <iostream>
#include <string>
using namespace std;

void test(){
    double num;
    cin >> num;
    string str = to_string(num);
    for(int i = str.size()-6; i >= 0; --i) cout << str[i];
}

int main(){
    test();
    return 0;
}