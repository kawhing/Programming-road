#include <iostream>
#include <vector>
using namespace std;

int main(){
    int start, end;
    cin >> start >> end;
    int year = 0;
    vector<int> run;
    for(int i = start; i <= end; i++){
        if((i % 4 == 0 && i % 100 != 0) || i % 400 == 0){
            run.push_back(i);
        }
    }
    cout << run.size() << endl;
    for(int i = 0; i < run.size(); i++){
        cout << run[i] << " ";
    }
    return 0;
}