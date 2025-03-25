#include <iostream>
#include <cmath>
#include <string>
using namespace std;
// 翻硬币
void test(){
    string str1, str2;// = "*o**o***o***", str2 = "*o***o**o***";
    cin >> str1;
    cin >> str2;
    int strlen = str1.size();
    int min_count = 0;
    
    for(int i = 0; i < strlen-1; ++i){
        if(str1[i] != str2[i]){
            if(str1[i] == '*') str1[i] = 'o';
            else if(str1[i] == 'o') str1[i] = '*';
            if(str1[i+1] == '*') str1[i+1] = 'o';
            else if(str1[i+1] == 'o') str1[i+1] = '*';
            ++min_count;
        }    
    }
    cout << min_count << endl;
}
int main(){
    test();
    return 0;
}