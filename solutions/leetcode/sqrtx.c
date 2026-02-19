int mySqrt(int x) {
    for (long long int i = 1; i < x; ++i){
        long long int j = i+1;
        if (i*i == x){
            return i;
        }else if (i*i < x && j*j > x){
                return i;  
        }
    }
    return x;
}