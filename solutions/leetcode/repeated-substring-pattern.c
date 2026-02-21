bool repeatedSubstringPattern(char * s){
    int n = strlen(s);
    for(int len = 1; len <= n/2; ++len){
        if (n % len == 0){
            bool found = true;
            for(int i = len; i < n; ++i){
                if(s[i] != s[i % len]){
                    found = false;
                    break;
                }
            }
            if(found){
                return true;
            }
        }
    }
    return false;
}
