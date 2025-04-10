#include <bits/stdc++.h>
using namespace std;
//使用map容器完美通过
map<string, int> students;
int main(){
	int t;
	cin >> t;
	while(t--){
		int op;
		cin >> op;
		if(op == 1){
			string name;
			int score;
			cin >> name >> score;
			students[name] = score;
			cout << "OK" << endl; 
		}else if(op == 2){
			string name;
			cin >> name;
			if(students.find(name) != students.end()) cout << students[name] << endl;
			else cout << "Not found" << endl;
		}else if(op == 3){
			string name;
			cin >> name;
			if(students.find(name) != students.end()){
				students.erase(name);
				cout << "Deleted successfully" << endl;
			}else cout << "Not found" << endl;
		}else if(op == 4){
			cout << students.size() << endl;
		}
	}
	return 0;
} 