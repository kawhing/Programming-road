bool isHappy(int n) {
    int temp[810] = {0}; 
    int num = n;
    while(1){
        int tmp = 0;
        while(num > 0){
            int digit = num % 10;
            tmp += digit * digit;
            num /= 10;
        }
        if(tmp == 1){
            return true;
        }else if(temp[tmp] == 1){
            return false;
        }else{
            temp[tmp] = 1;
            num = tmp;
        }
    }
}