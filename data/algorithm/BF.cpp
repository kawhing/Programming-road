#include <iostream>
#include <string>
using namespace std;

int bfsearch(const string &text, const string &pattern){
    int textSize = text.length();//n
    int patternSize = pattern.length();//m

    for(int i = 0; i <= textSize-patternSize; ++i){
        int j = 0;
        while(j < patternSize && text[i+j] == pattern[j]){
            ++j;
        }
        if(j == patternSize){
            return i;
        }
    }
    return -1;
}

int main(){
    string text = "Hello World";
    string pattern = "World";
    int result = bfsearch(text, pattern);
    if(result != -1) cout << "匹配位置 : " << result << endl;
    else cout << "未找到匹配" << endl;
    return 0;
}