#include<iostream>
using namespace std;
//辗转相除法求最大公约数
int test(int a, int b){
    if(b < 0) b = -b;
    while(b%a != 0){
        int temp = b%a;
        b = a;
        a = temp;
    }
    return a; 

}
int main(){
    int result = test(125, 610);
    cout << result << endl;
    return 0;
}