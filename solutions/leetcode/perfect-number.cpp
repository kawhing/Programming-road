class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0, temp = num;
        for(int i = 1; i < num; ++i){
            if(temp % i == 0){
                sum += i;
            }
        }
        if(sum == num){
            return true;
        }
        return false;
    }
};