#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isHui(string date){
    for(int i = 0; i < date.size() / 2; ++i){
        if(date[i] != date[date.size() - i - 1]){
            return false;
        }
    }
    return true;
}

bool isABHui(string s){
    if(!isHui(s)) return false;
    if(s[0] == s[2] && s[1] == s[3]) return true;
    return false;
}

string returnDate(int year, int month, int day){
    char buf[9];
    sprintf(buf, "%04d%02d%02d", year, month, day);
    return string(buf);
}

string returnNextDate(string s){

    int year = 0, month, day;
    year = (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 + (s[3] - '0');
    month = (s[4] - '0') * 10 + (s[5] - '0');
    day = (s[6] - '0') * 10 + (s[7] - '0');
    if(day < 28){
        ++day;
        return returnDate(year, month, day);
    }else{
        if(month == 2){
            if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
                if(day == 29){
                    day = 1;
                    ++month;
                    return returnDate(year, month, day);
                }else{
                    ++day;
                    return returnDate(year, month, day);
                }
            }else{
                if(day == 28){
                    day = 1;
                    ++month;
                    return returnDate(year, month, day);
                }else{
                    ++day;
                    return returnDate(year, month, day);
                }
            }
        }else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10){
            if(day == 31){
                day = 1;
                ++month;
                return returnDate(year, month, day);
            }else{
                ++day;
                return returnDate(year, month, day);
            }
        }else if(month == 4 || month == 6 || month == 9 || month == 11){
            if(day == 30){
                day = 1;
                ++month;
                return returnDate(year, month, day);
            }else{
                ++day;
                return returnDate(year, month, day);
            }
        }else{
            if(day == 31){
                day = 1;
                month = 1;
                ++year;
                return returnDate(year, month, day);
            }else{
                ++day;
                return returnDate(year, month, day);
            }
        }
    }
}

int main() {
    int N = 20200202;
    cin >> N;
    string s = to_string(N);
    
    s = returnNextDate(s);
    while(!isHui(s)){
        s = returnNextDate(s);
    }
    cout << s << endl;

    while(!isABHui(s)){
        s = returnNextDate(s);
    }
    cout << s << endl;
    return 0;
}