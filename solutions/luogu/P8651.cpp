#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool runYear(int year){
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
string temp(vector<int> pat){
	string temp = to_string(pat[0]);
	if(pat[1] >= 10)
		temp +=  "-" + to_string(pat[1]);
	else temp +=  "-0" + to_string(pat[1]);
	if(pat[2] >= 10) 
		 temp += "-" + to_string(pat[2]);
	else temp += "-0" + to_string(pat[2]);
	return temp;
}
void toDates(vector<int> pat, vector<string> &dates){
	if(pat[0] >= 60 && pat[0] <= 99){
        	pat[0] += 1900;
		}else if(pat[0] >= 0 && pat[0] <= 59){
			pat[0] += 2000;
		}
		if(pat[1] >= 1 && pat[1] <= 12){
			if(pat[1] == 2){
				if(runYear(pat[0])){
					if(pat[2] >= 1 && pat[2] <= 29){
						dates.push_back(temp(pat));
					}else{
						return;
					}
				}else{
					if(pat[2] >= 1 && pat[2] <= 28){
						dates.push_back(temp(pat));
					}else{
						return;
					}					
				}
			}else if(pat[1] == 1 || pat[1] == 3 || pat[1] == 5 || pat[1] == 7 || pat[1] == 8 || pat[1] == 10 || pat[1] == 12){
				if(pat[2] >= 1 && pat[2] <= 31){
					dates.push_back(temp(pat));
				}else{
					return;
				}
			}else if(pat[1] == 4 || pat[1] == 6 || pat[1] == 9 || pat[1] == 11){
				if(pat[2] >= 1 && pat[2] <= 30){
					dates.push_back(temp(pat));
				}else{
					return;
				}
			} 		
		}else{
			return;
		}
}
void sortDates(vector<string> &dates){//自己实现的，能用但不是特别好，其实可以改为正常的整形数字来比较，当时没有想出来，所以没有使用sort函数代替
	for(int i = 0; i < dates.size()-1; ++i){
		for(int j = 0; j < dates.size()-i-1; ++j){
			int temp1 = stoi(dates[j].substr(0, 4)), temp2 = stoi(dates[j+1].substr(0, 4));
			if(temp1 > temp2) swap(dates[j], dates[j+1]); 
			else if(temp1 == temp2){
				temp1 = stoi(dates[j].substr(5, 2)), temp2 = stoi(dates[j+1].substr(5, 2));
				if(temp1 > temp2) swap(dates[j], dates[j+1]);
				else if(temp1 == temp2){
					temp1 = stoi(dates[j].substr(8, 2)), temp2 = stoi(dates[j+1].substr(8, 2));
					if(temp1 > temp2) swap(dates[j], dates[j+1]);
				}
					
			}
		}
	}
}
void printVector(vector<string> dates){
	for(int i = 0; i < dates.size(); ++i){
		cout << dates[i] << endl;
	}
}
void test(){
	string date;
	vector<string> dates; 
	cin >> date;

	vector<int> pat(3);
	pat[0] = stoi(date.substr(0, 2));
	pat[1] = stoi(date.substr(3, 2));
	pat[2] = stoi(date.substr(6, 2));
	toDates(pat, dates);
	toDates({pat[2], pat[1], pat[0]}, dates);
    toDates({pat[2], pat[0], pat[1]}, dates);
	//sortDates(dates);//自己实现的，效果不好
    sort(dates.begin(), dates.end());
    dates.erase(unique(dates.begin(), dates.end()), dates.end());
	printVector(dates);
}
int main(){
	test();
	return 0;
}