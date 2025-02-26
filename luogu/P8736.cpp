#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
void swapdp(vector<vector<int>>& dp, string str){
    for(int i = 0; i < dp.size()-1; ++i){
        for(int j = 0; j < dp.size()-i-1; ++j){
            if(str[dp[j][0]] > str[dp[j+1][0]]){
                swap(dp[j][0], dp[j+1][0]);
                swap(dp[j][1], dp[j+1][1]);
            }
        }
    }
}
*/
bool isAvilable(string str1, string str2){
    for(int i = 0; i < min(str1.size(), str2.size()); ++i){
        if(str1[i] >= str2[i]) return false;
    }
    return true;
}
vector<int> mindp(vector<vector<int>> dp, string str){
    int max_index = 0, max_len = 0;
    for(int i = 0; i < dp.size(); ++i){
        if(i != dp.size()-1){
            int index = dp[i][0], len = dp[i][1];
            for(int j = i; j < dp.size()-1; ++j){
                if(isAvilable(str.substr(dp[j][0], dp[j][1]), str.substr(dp[j+1][0], dp[j+1][1]))){
                    len += dp[j+1][1];
                }else break;
            }
            if(len > max_len){
                max_index = index;
                max_len = len;
            }
        }else{
            if(dp[i][1] > max_len){
                max_index = i;
                max_len = dp[i][1];
            }
        }

    }

    return vector<int>{ dp[max_index][0], max_len };
}

int main(){
    string str;// = "ACaBbcC";
    cin >> str;
    vector<vector<int>> dp;
    for(int i = 0, len = 1; i < str.size(); i += len){
        if(str[i] >= 'A' && str[i] <= 'Z'){//如果是大写字母
            dp.push_back({i, 1});
            for(int j = i; j < str.size(); ++j){//找到名字
                if(j+1 != str.size()-1){//如果下一个不是最后一个字母
                    if(str[j+1] >= 'A' && str[j+1] <= 'Z') break;//如果下一个是大写字母,结束
                    if(str[j+1] >= 'a' && str[j+1] <= 'z') ++dp[dp.size()-1][1];//如果下一个是小写字母,计数加一
                }else//如果下一个是最后一个字母
                    if(str[j] >= 'a' && str[j] <= 'z') ++dp[dp.size()-1][1];//如果最后一个是小写字母,计数加一
            }
            len = dp[dp.size()-1][1];
        }
    }
    // //swapdp(dp, str);//排序标签
    // for(int i = 0; i < dp.size(); ++i){
    //     cout << dp[i][0] << " " << dp[i][1] << endl;
    // }
    vector<int> res = mindp(dp, str);
    cout << str.substr(res[0], res[1]) << endl;

    return 0;
}