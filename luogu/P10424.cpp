#include <iostream>
#include <string>
using namespace std;
// Quetiosn number C (good number) the 15th lanqiao Cup 
void test(){
    long long n, goodNum = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        string str = to_string(i);
        long long strSize = str.size();
        long long count = 0;
        for(int j = strSize-1; j >= 0; --j){
            if((strSize-j)%2 == 0){
                if(str[j] % 2 == 0) ++count;
                else break;
            }else{
                if(str[j]%2 == 1) ++count;
                else break;
            }
        }
        if(count == strSize) ++goodNum;
    }
    cout << goodNum << endl;
}

int main(){
    test();
    return 0;
}