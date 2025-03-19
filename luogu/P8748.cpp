#include <iostream>
using namespace std;

// not rearly reslove
bool isRun(int year){
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int what_year(long long &ms, long long year_4_ms){
    if(ms > year_4_ms){
        int year = ms / year_4_ms;
        ms -= year*year_4_ms;
        long long yu = ms % year_4_ms;
        year *= 4;
        if(yu <= 365*24*60*60*1000){
            return year;
        }else if(yu <= 365*2*60*60*1000){
            ms -= 365*24*60*60*1000;
            return year+1;
        }else if(yu <= (365*3+1)*60*60*1000){
            ms -= 365*2*60*60*1000;
            return year+2;
        }else{
            ms -= (365*3+1)*60*60*1000;
            return year+3;
        }
    }
    return 0;
}
int what_month(long long &ms, int year){
    if(isRun(year)){// 闰年
        if(ms < 31*24*60*60*1000){// 在1月
            return 1;
        }else if(ms < (31+29)*24*60*60*1000){// 在2月
            ms -= 31*24*60*60*1000;
            return 2;
        }else if(ms < (31+29+31)*24*60*60*1000){// 在3月
            ms -= (31+29)*24*60*60*1000;
            return 3;
        }else if(ms < (31+29+31+30)*24*60*60*1000){// 在4月
            ms -= (31+29+31)*24*60*60*1000;
            return 4;
        }else if(ms < (31+29+31+30+31)*24*60*60*1000){// 在5月
            ms -= (31+29+31+30)*24*60*60*1000;
            return 5;
        }else if(ms < (31+29+31+30+31+30)*24*60*60*1000){// 在6月
            ms -= (31+29+31+30+31)*24*60*60*1000;
            return 6;   
        }else if(ms < (31+29+31+30+31+30+31)*24*60*60*1000){// 在7月
            ms -= (31+29+31+30+31+30)*24*60*60*1000;
            return 7;
        }else if(ms < (31+29+31+30+31+30+31+31)*24*60*60*1000){// 在8月
            ms -= (31+29+31+30+31+30+31)*24*60*60*1000;
            return 8;
        }else if(ms < (31+29+31+30+31+30+31+31+30)*24*60*60*1000){// 在9月
            ms -= (31+29+31+30+31+30+31+31)*24*60*60*1000;
            return 9;
        }else if(ms < (31+29+31+30+31+30+31+31+30+31)*24*60*60*1000){// 在10月
            ms -= (31+29+31+30+31+30+31+31+30)*24*60*60*1000;
            return 10;
        }else if(ms < (31+29+31+30+31+30+31+31+30+31+30)*24*60*60*1000){// 在11月
            ms -= (31+29+31+30+31+30+31+31+30+31)*24*60*60*1000;
            return 11;
        }else{// 在12月
            ms -= (31+29+31+30+31+30+31+31+30+31+30)*24*60*60*1000;
            return 12;
        }
    }else{
        if(ms < 31*24*60*60*1000){// 在1月
            return 1;
        }else if(ms < (31+28)*24*60*60*1000){// 在2月
            ms -= 31*24*60*60*1000;
            return 2;
        }else if(ms < (31+28+31)*24*60*60*1000){// 在3月
            ms -= (31+28)*24*60*60*1000;
            return 3;
        }else if(ms < (31+28+31+30)*24*60*60*1000){// 在4月
            ms -= (31+28+31)*24*60*60*1000;
            return 4;
        }else if(ms < (31+28+31+30+31)*24*60*60*1000){// 在5月
            ms -= (31+28+31+30)*24*60*60*1000;
            return 5;
        }else if(ms < (31+28+31+30+31+30)*24*60*60*1000){// 在6月
            ms -= (31+28+31+30+31)*24*60*60*1000;
            return 6;   
        }else if(ms < (31+28+31+30+31+30+31)*24*60*60*1000){// 在7月
            ms -= (31+28+31+30+31+30)*24*60*60*1000;
            return 7;
        }else if(ms < (31+28+31+30+31+30+31+31)*24*60*60*1000){// 在8月
            ms -= (31+28+31+30+31+30+31+31)*24*60*60*1000;
            return 8;
        }else if(ms < (31+28+31+30+31+30+31+31+30)*24*60*60*1000){// 在9月
            ms -= (31+28+31+30+31+30+31+31)*24*60*60*1000;
            return 9;
        }else if(ms < (31+28+31+30+31+30+31+31+30+31)*24*60*60*1000){// 在10月
            ms -= (31+28+31+30+31+30+31+31+30)*24*60*60*1000;
            return 10;
        }else if(ms < (31+28+31+30+31+30+31+31+30+31+30)*24*60*60*1000){// 在11月
            ms -= (31+28+31+30+31+30+31+31+30+31)*24*60*60*1000;
            return 11;
        }else{// 在12月
            ms -= (31+28+31+30+31+30+31+31+30+31+30)*24*60*60*1000;
            return 12;
        }
    }
    return 0;
}

int what_day(long long ms, int month){
    int day = 0;
    day = ms / (24*60*60*1000);
    ms -= day*(24*60*60*1000);
    if(ms%(24*60*60*1000)== 0){
        return day;
    }
    return day+1;
}

int what_hour(long long ms){
    int hour = 0;
    hour = ms / (60*60*1000);
    ms -= hour*(60*60*1000);
    if(ms%(60*60*1000)== 0){
        return hour;
    }
    return hour+1;
}

int  what_minute(long long ms){
    int minute = 0;
    minute = ms / (60*1000);
    ms -= minute*(60*1000);
    if(ms%(60*1000)== 0){
        return minute;
    }
    return minute+1;
}
int what_second(long long ms){
    int second = 0;
    second = ms / 1000;
    ms -= second*1000;
    if(ms%1000 == 0){
        return second;
    }
    return second+1;
}

void test(){
    int year_4_ms = 4*365*24*60*60*1000;// 4 years in ms
    long long ms = 46800999;
    int year = what_year(ms, year_4_ms);
    int month = what_month(ms, year);
    int day = what_day(ms, month);
    int hour = what_hour(ms);
    int minute = what_minute(ms);
    int second = what_second(ms);
    cout << hour << ":" << minute << ":" << second << endl;
}

int main(){
    test();
    return 0;
}