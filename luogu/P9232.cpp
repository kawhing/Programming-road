#include <iostream>
#include <vector>
#include <string>
using namespace std;
// not rearly reslove
bool isTrue(const string& str1, const string& str2) {
    int num1 = stoi(str1);
    int num2 = stoi(str2);
    return num1 < num2;
}

void turnRound(string &str, int start, int end) {
    while(start < end) {
        swap(str[start], str[end]);
        start++;
        end--;
    }
}

void test() {
    string str;
    cin >> str;
    int strSize = str.size();
    int result = 0;
    for(int start = 0; start < strSize-1; ++start) {
        for(int end = start+1; end < strSize; ++end) {
            string temp = str;
            turnRound(temp, start, end);
            if(isTrue(temp, str)) ++result;
        }
    }
    cout << result << endl;
}

int main() {
    test();
    return 0;
}