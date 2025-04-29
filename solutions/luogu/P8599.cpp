#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void test(){
    int n;
    cin >> n;
    int count_valid = 0;
    vector<int> digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int count = 0;

    do{
        for(int i = 0; i <= 7; ++i){
            for(int j = i+1; j <= 8; ++j){
                long long a = 0, b = 0, c = 0;
                for(int k = 0; k < i; ++k){
                    a = a*10+digits[k];
                }
                for(int k = i; k < j; ++k){
                    b = b*10+digits[k];
                }
                for(int k = j; k < 9; ++k){
                    c = c*10+digits[k];
                }
                if(c != 0 && b%c == 0){
                    long long result = a+b/c;
                    if(result == n) ++count;
                }
            }
        }
    }while(next_permutation(digits.begin(), digits.end()));
    cout << count << endl;
}

int main(){
    test();
    return 0;
}