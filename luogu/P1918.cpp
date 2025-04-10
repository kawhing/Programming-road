#include <bits/stdc++.h>
using namespace std;

int main(){
   int n, q;
    cin >> n;
	map<int, int> maps; 
	for(int i = 1; i <= n; ++i){
		int a;
		cin >> a;
		maps[a] = i;	
	}
	cin >> q;
	while(q--){
		int a;
		cin >> a;
		cout << maps[a] << endl;
	}
    return 0;
}