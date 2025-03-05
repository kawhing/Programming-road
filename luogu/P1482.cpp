#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}

int main(){ 
    string str1, str2;
    cin >> str1 >> str2;
    
    // 解析第一个分数
    int pos1 = str1.find('/');
    int a1 = stoi(str1.substr(0, pos1));
    int b1 = stoi(str1.substr(pos1 + 1));
    
    // 解析第二个分数
    int pos2 = str2.find('/');
    int a2 = stoi(str2.substr(0, pos2));
    int b2 = stoi(str2.substr(pos2 + 1));
    
    // 计算分数乘积
    int numerator = a1 * a2;
    int denominator = b1 * b2;
    
    // 约分到最简形式
    int g = gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;
    
    // 输出列和行 (根据题意，列对应分母，行对应分子)
    cout << denominator << " " << numerator;
    return 0;
}