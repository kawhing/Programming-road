#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long pingxing(vector<vector<long long>> line, int n){
    long long count = 0;
    for(int i = 1; i < n; ++i){
        if(line[0][0] == line[i][0]) ++count;
    }
    return count;
}
vector<vector<bool>> line_intersection(vector<vector<long long>>line, int n){
    vector<vector<bool>> line_intersection(n, vector<bool>(n));
    for(int i = 0; i < n-1; ++i){
        for(int j = i; j < n; ++j){
            if(i == j) line_intersection[i][j] = false;
            else{
                if(line[i][0] == line[j][0])//平行
                    line_intersection[i][j] == false;
                else line_intersection[i][j] = true;//相交
            }
        }
    }
    return line_intersection;
}
void test(){
    int n;
    cin >> n;
    if(n == 1){
        cout << 2 << endl;
        return;
    }
    int count = 0;
    vector<vector<long long>> line(n, vector<long long>(2));
    for(int i = 0; i < n; ++i){
        cin >> line[i][0] >> line[i][1];
    }
    //全都平行
    if(pingxing(line, n) == n){
        cout << n+1 << endl;
        return;
    }else if(pingxing(line, n) == n-1){
        cout << (n+1)*2 << endl;
        return;
    }else{
        vector<vector<bool>> lineIntersection = line_intersection(line, n);
        if(1){

        }
    }
}

int main(){
    test();
    return 0;
}