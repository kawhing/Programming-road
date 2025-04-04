#include <iostream>
#include <string> 
using namespace std;
//时间复杂度较高,不能完全通过测试案例
void test(){
	string str;// = "abababdb";
	long long k, count = 0;
	char c1, c2;
	cin >> k;
	cin >> str >> c1 >> c2;
	for(long long i = 0; i <= str.size()-k; ++i){
		if(str[i] == c1 && i < str.size()-1){
			for(long long j = i+1; j < str.size(); ++j){
				if(j-i+1 >= k){
					if(str[j] == c2){
						++count;
						//cout << i << " " << j << endl;	
					}
				}
			}
		}
	}
	cout << count << endl;
}
int main() {
	test();
	return 0;
}