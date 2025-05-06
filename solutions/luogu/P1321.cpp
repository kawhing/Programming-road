#include <bits/stdc++.h>
using  namespace std;
typedef long long ll;

void solve(){
    string s;
    ll boyNum = 0, girlNum = 0;
	cin>>s;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]=='b') boyNum++;
		if (s[i]=='o'&&s[i-1]!='b') boyNum++;
		if (s[i]=='y'&&s[i-1]!='o'&&s[i-2]!='b') boyNum++;
		if (s[i]=='g') girlNum++;
		if (s[i]=='i'&&s[i-1]!='g') girlNum++;
		if (s[i]=='r'&&s[i-1]!='i'&&s[i-2]!='g') girlNum++;
		if (s[i]=='l'&&s[i-1]!='r'&&s[i-2]!='i'&&s[i-3]!='g') girlNum++;
	}
    cout << boyNum << endl << girlNum;
}
int main(){
    solve();
    return 0;
}