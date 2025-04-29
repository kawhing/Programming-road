#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> queen;
int total = 0;     
int printCount = 0; 

bool isValid(int row, int col) {
    for(int i = 0; i < row; ++i){
    	if(queen[i] == col || abs(queen[i]-col) == abs(i - row)) return false;
	}
	return true;
}

void dfs(int row) {
    if(row == n){
    	++total;
    	if(printCount < 3){
    		cout << queen[0]+1;
    		for(int i = 1; i < n; ++i){
    			cout << " " << queen[i]+1;
			}
			cout << endl;
			++printCount;
		}
	}
	for(int col = 0; col < n; ++col){
		if(isValid(row, col)){
			queen[row] = col;
			dfs(row+1);
		}
	}
}

int main() {
    cin >> n;
    queen.resize(n);
    
    dfs(0);
    
    cout << total << endl;
    return 0;
}