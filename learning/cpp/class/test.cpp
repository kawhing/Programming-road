#include <iostream>
using namespace std;

void test(int num);
int main(){
    int num = 21;
    while(!(num % 5 == 1 && num % 6 == 5 && num % 7 == 4 && num % 11 == 10)){
        ++num;
    }
    cout << num << endl;
    return 0;
}