#include <iostream>
#include <string>
#include <vector>
using namespace std;

//计算部分匹配表 前缀函数
vector<int> computeLPSArray(const string &pattern){
    int patternSize = pattern.length();
    vector<int> lps(patternSize, 0);//初始化为0
    int len = 0;
    int i = 1;

    while(i < patternSize){
        if(pattern[i] == pattern[len]){
            ++len;
            lps[i] = len;
            ++i;
        }else{
            if(len != 0) len = lps[len-1];
            else {
                lps[i] = 0;
                ++i;
            }
        }
    }
    return lps;
}
int KMP_search(const string &text, const string &pattern){
    int textSize = text.length();
    int patternSize = pattern.length();
    if(patternSize == 0) return 0;

    vector<int> lps = computeLPSArray(pattern);
    int i = 0, j = 0;


    while(i < textSize){
        if(pattern[j] == text[i]){
            ++i;
            ++j;
        }
        if(j == patternSize) return i-j;
        else if(i < textSize && pattern[j] != text[i]){
            if(j != 0) j = lps[j-1];
            else ++i; 
        }
    }
    return -1; 
}
int main(){
    string text = "Hello World!";
    string pattern = "World";
    int result = KMP_search(text, pattern);
    if(result != -1) cout << "匹配位置 : " << result << endl;
    else cout << "未找到匹配" << endl;
    return 0;
}