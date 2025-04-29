#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <string>   
using namespace std;

int get_max(vector<int> score){
    int max = 0;
    for(int i = 0; i < score.size(); ++i){
        if(score[i] > max) max = score[i];
    }
    return max;
}

int get_min(vector<int> score){
    int min = 100;
    for(int i = 0; i < score.size(); ++i){
        if(score[i] < min) min = score[i];
    }
    return min;
}

string get_average(vector<int> score){
    double sum = 0;
    for(int i = 0; i < score.size(); ++i){
        sum += score[i];
    }
    ostringstream out;
    out << fixed << setprecision(2) << sum/score.size();
    string rounded_number = out.str();
    //cout << rounded_number << endl;
    return rounded_number;
}
int main(){
    int n,max = 0, min = 0, average = 0;//n为学生人数，max为最高分，min为最低分，average为平均分
    cin >> n;
    vector<int> score(n);
    for(int i = 0; i < n; ++i){
        cin >> score[i];
    }
    cout << get_max(score) << endl;
    cout << get_min(score) << endl;
    cout << get_average(score) << endl;
}