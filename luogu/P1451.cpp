#include <bits/stdc++.h>
using  namespace std;

int n, m, usedNum = 0, number = 0;
int dx[4] = {0, 1, 0, -1};//上右下左 
int dy[4] = {1, 0, -1, 0};
void dfs(vector<vector<char>> &nums, vector<vector<bool>> &used, int x, int y){
	used[x][y] = true;
	for(int i = 0; i < 4; ++i){
		int nx = x+dx[i], ny = y+dy[i];
		if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if(!used[nx][ny] && nums[nx][ny] != '0'){
			used[nx][ny] = true;
			++usedNum;
			dfs(nums, used, nx, ny); 
		}
	}
}
int main(){
	cin >> n >> m;
	vector<vector<char>> nums(n, vector<char>(m));
	vector<vector<bool>> used(n, vector<bool>(m));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> nums[i][j];
			if(nums[i][j] == '0'){
				used[i][j] = true;
				++usedNum;
			}else used[i][j] = false;
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(nums[i][j] != '0' && !used[i][j]){
				++number;
				used[i][j] = true;
				dfs(nums, used, i, j);
				
			}
		}
	}
	cout << number << endl;
	return 0;
} 