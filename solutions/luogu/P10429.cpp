#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void test(){
    long long n;
    cin >> n;
    if(n == 1) {
        int temp;
        cin >> temp;
        cout << temp << endl;
        return;
    }else if(n == 2){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        cout << ((temp1 >= temp2) ? (temp1-temp2) : (temp2-temp1));
        return;
    }
    long long studentsSum = 0;
    vector<int> students(n);
    for(int i = 0; i < n; i++){
        cin >> students[i];
        studentsSum += students[i];
    }
    long long diff = studentsSum;
    
    for(int l1 = 0; l1 < n; ++l1){
        for(int r1 = l1; r1 < n; ++r1){
            for(int l2 = r1+1; l2 < n; ++l2){
                for(int r2 = l2; r2 < n; ++r2){
                    long long sum1 = 0, sum2 = 0;  
                    for(int i = l1; i <= r1; ++i) sum1 += students[i];
                    for(int i = l2; i <= r2; ++i) sum2 += students[i];
                    diff = min(diff, abs(sum1-sum2));
                }
            }
        }    
    }
    cout << diff << endl;
}

int main(){
    test();
    return 0;
}