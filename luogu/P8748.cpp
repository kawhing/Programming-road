#include <iostream>
using namespace std;

// 将天数去掉
void inOneDay(long long &ms, long long day_ms){
    int temp = ms / day_ms;
    ms -= day_ms*temp;
}
// 计算出多少小时
void  what_hour(long long &ms){
    long long hour = 60*60*1000;
    int temp = ms/hour;
    ms -= hour* temp;
    if(temp < 10) cout << "0";
    cout << temp << ":";
}
// 计算出多少分钟
void what_minute(long long &ms){
    int minute = 60*1000;
    int temp = ms/minute;
    ms -= minute*temp;
    if(temp < 10) cout << "0";
    cout << temp << ":";
}
// 计算出多少秒
void what_second(long long &ms){
    int temp = ms/1000;
    ms -= temp*1000;
    if(temp < 10) cout << "0";
    cout << temp << endl;
}

void test(){
    long long day_ms = 24 * 60 * 60 * 1000;
    long long ms;// = day_ms + 1000*60*60*3+1000*60*3 + 1000*5;
    cin >> ms;
    inOneDay(ms, day_ms);
    what_hour(ms);
    what_minute(ms);
    what_second(ms);
    //cout << ms << endl;
}

int main(){
    test();
    return 0;
}