#include <iostream>
#include <vector>
#include <algorithm> 
#include <cmath>
#include <climits>
using namespace std;
typedef long long ll;

ll n,minDiff = LLONG_MAX;
typedef struct Perke{
	ll s, b;
}Perke;
vector<Perke> perke;

void dfs(int index, ll sSum, ll bSum, bool hasSelect){
	if(index == n){
		if(hasSelect){
			ll diff = abs(sSum-bSum);
			minDiff = min(diff, minDiff);
		}
		return;
	}
	dfs(index+1, sSum, bSum, hasSelect);//不选择当前 
	dfs(index+1, sSum*perke[index].s, bSum+perke[index].b, true);//选择当前 	
}
int main() {
	cin >> n;
	perke.resize(n);
	for(int i = 0; i < n; ++i){
		cin >> perke[i].s >> perke[i].b;
	}
	dfs(0, 1, 0, false);
    cout << minDiff << endl;
    return 0;
}