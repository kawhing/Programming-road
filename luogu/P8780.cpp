#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll a, b, n;
	cin >> a >> b >> n;
	ll week = n/(5*a+2*b);
	ll day = week*7;
	n -= week*(5*a+2*b);
	if(n > 0){
		ll temp = 0;
		
		while(n > 0){
			++day;
			if(day%7 >= 1 && day%7 <= 5) n -= a;
			else n -= b;
		}
	}

	cout << day << endl;
	return 0;
}