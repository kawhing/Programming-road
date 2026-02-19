//将日期转换为二进制表示
//仅仅是一个leetcode题解类，非完整代码
class Solution {
public:
    string convertDateToBinary(string date) {
        string b_year, b_month, b_day;
        int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,2));
        int day = stoi(date.substr(8,2));
        for(int i = 11; i >= 0; --i){
            if((1 << i) <= year){
                b_year.push_back('1');
                year -= (1 << i);
            }else if(b_year.size() > 0) b_year.push_back('0');
        }
        for(int i = 3; i >= 0; --i){
            if((1 << i) <= month){
                b_month.push_back('1');
                month -= (1 << i);
            }else if(b_month.size() > 0) b_month.push_back('0');
        }
        for(int i = 4; i >= 0; --i){
            if((1 << i) <= day){
                b_day.push_back('1');
                day -= (1 << i);
            }else if(b_day.size() > 0)b_day.push_back('0');
        }
        date = b_year + "-" + b_month + "-" + b_day;
        return date;
    }
};