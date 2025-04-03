#include <iostream>
#include <string>
using namespace std;

void test(){
    string pwd;
    cin >> pwd;
    for(long long i = 0; i < pwd.size(); ++i){
        if(pwd[i] == '\\'){
            pwd[i] = '/';
        }
    }
    cout << pwd << endl;
}

int main(){
    test();
    return 0;
}