#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int year, count = 1;
    cin >> year;
    string result;
    vector<string> sky = {"jia", "yi", "bing", "ding", "wu", "ji", "geng", "xin", "ren", "gui"};
    vector<string> earth = {"zi", "chou", "yin", "mao", "chen", "si", "wu", "wei", "shen", "you", "xu", "hai"};
    if(year >= 2020)
        result = sky[(year - 2020 + 6) % 10] + earth[(year - 2020) % 12];
    else
        result = sky[(2020 - year + 4) % 10] + earth[(2020 - year + 10) % 12];
    cout << result << endl;
    return 0;
}