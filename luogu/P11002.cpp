#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void get_date(string date){
    //cout << date << endl;
    string part1, part2, part3;
    part1 = date.substr(0, 10);
    part2 = date.substr(11, 8);
    part3 = date.substr(20, date.size()-19);
    //cout << day << endl << hour << endl << sub << endl;
    int year, month, day, hour, min, sec;
    hour = part2[0]*10+part2[1];
    min = part2[3]*10+part2[4];
    sec = part2[6]*10+part2[7];

    year = part1[0]*1000+part1[1]*100+part1[2]*10+part1[3];
    month = part1[5]*10+part1[6];
    day = part1[8]*10+part1[9];
    int val = stoi(part3);

    if(min%val == 0){
        cout << date << endl;
    }
    if(min>val){
        min = (min/val)*val;
        cout << part1 << " " << hour << ":" << min << ":" << "00" << endl;
    }else{
        if(val > 60){

        }else{
            
        }
    }
}
void test(){
    int t;
    cin >> t;
    for(int i = 0; i < 2; ++i){
        string date;
        getline(cin, date);
    }
}

int main(){
    //test();
    get_date("2016-09-07 18:24:33 10");
    return 0;
}