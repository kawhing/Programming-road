#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
//U535982 J-A 小梦的AB交换 通过6 得分30
using namespace std;
typedef long long ll;
ll minOperate(string s, ll sSize){
	int count = 0;
	for(ll i = 1; i < sSize-1; ++i){
		if(s[i] == s[i-1]){
			if(s[i] == s[i+1]){
				for(ll j = i+2; j < sSize; ++j){
					if(s[j] != s[j-1]) continue;
					else if(s[j] == s[j+1]){
						if(s[j] != s[j] && s[j] == s[j+1]){
							swap(s[j], s[i]);
							++count;
						}
					}
				}
			}else if(s[i] != s[i+1]){
				swap(s[i], s[i+1]);
				++count;	
			}
		}else if(s[i] != s[i-1]){
			continue;
		}
	}
	return count;
}
void print(vector<ll> result){
	for(ll i = 0; i < result.size(); ++i){
		cout << result[i] << endl;
	}
}
void test(){
	ll t;
	cin >> t;// 组数
	vector<ll> result;
	for(ll i = 0; i < t; ++i){
		ll n;// s长度的一半 
		cin >> n;
		string s;
		cin >> s;
		result.push_back(minOperate(s, n*2));
	}
	print(result);  
}
int main() {
	test();
	return 0;
}