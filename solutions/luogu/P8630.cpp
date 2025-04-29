#include <iostream>
#include <vector>
#include <string>
using namespace std;
//个别测试案例过大，容易超时，目前本人编程能力有限，暂时无法解决
vector<int> test3(string s){//统计字符串中每个字母出现的次数
    vector<int> aphal(26, 0);
    for(int i = 0; i < s.size(); ++i){
        ++aphal[s[i]-'a'];
    }
    return aphal;
}

int test2(string str, string s){//判断字符串中是否包含密码,输出匹配的个数
    int count = 0;
    vector<int> aphla1 = test3(str);
    vector<int> aphla2 = test3(s);
    for(int i = 0; i < 26; ++i){
        if(aphla1[i] != aphla2[i]){
            return 0;
        }
    }
    return 1;
}

void test1(string str, int n, vector<string> password){
    int result = 0;
    for(int i = 0; i < str.size()-8+1; ++i){
        string s = str.substr(i, 8);
        for(int j = 0; j < n; ++j){
            result += test2(s, password[j]);
        }
    }
    cout << result << endl;
}

int main(){
    string str;
    cin >> str;
    int n ;
    cin >> n;
    vector<string> password(n);

    for(int i = 0; i < n; ++i){
        cin >> password[i];
    }
    test1(str, n, password);
    return 0;
}