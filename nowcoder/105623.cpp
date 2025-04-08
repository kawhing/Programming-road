#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
/*小苯的Z串匹配
https://ac.nowcoder.com/acm/contest/105623/C
小苯有一个长度为n的数组α，同时他还另有一个长度也为n的字符串S，仅由'<'，>'和'Z'三种字符组成
居说，串S恰好是用来“匹配”α数组的，具体的：
如果Si'<'，则意味着必须有：ai<0。·如果Si=‘>'，则意味着必须有：ai>0。
如果 Si='Z'，则意味着必须有：αi-1*ai>0，（1<i≤n)。
然而，现在的数组α并不一定满足S的匹配要求，因此小苯需要进行一些修改操作，具体的：·小苯可以选择一个数字ai（1≤i≤n)，将ai修改为任意整数（-10^9≤≤10^9)。
现在，小苯想知道他至少需要多少次修改，才能使得α满足S的匹配要求，请你帮他算一算吧。
*/
//自测通过 用例通过0 得分0
ll getResult(vector<ll> &a, string s, ll n){
	ll count = 0;
	for(ll i = 0; i < n; ++i){
		if(s[i] == '<'){
			if(a[i] < 0){
				continue;
			}else{
				if(i+1 < n && s[i+1] == 'Z'){
					if(a[i+1] < 0){
						a[i+1] *= -1;
						++count; 
					}
				}else{
					a[i] *= -1;
					++count;
				}
			}
		}else if(s[i] == '>'){
			if(a[i] > 0) continue;
			else{
				if(i+1 < n && s[i+1] == 'Z'){
					if(a[i+1] > 0){
						a[i] *= -1;
						++count;
					}
				}else{
					a[i] *= -1;
					++count;
				}
			}
		}else if(s[i] == 'Z' && i > 0){
			if(a[i]*a[i-1] > 0) continue;
			else{
				a[i] *= -1;
				++count;
			}
		}
	}
	return count;	
}
void test(){
	int t;
	cin >> t;
	vector<ll> result;
	for(int i = 0; i < t; ++i){
		ll n;
		cin >> n;
		vector<ll> a(n);
		string s;
		for(ll j = 0; j < n; ++j) cin >> a[j];
		cin >> s;
		result.push_back(getResult(a, s, n));
	}
	for(ll i = 0; i < t; ++i) 
		cout << result[i] << endl;
}
int main() {
	test();
	return 0;
}