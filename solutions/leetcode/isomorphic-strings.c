bool isIsomorphic(char* s, char* t) {
    int test = 0;
    int sSize = strlen(s);
    int tSize = strlen(t);
    if(sSize == 1 && *s == *t) test = 1;
    else if(sSize != tSize) return test;
    else{
        for(int i = 0; i < sSize-1; ++i){
            for(int j = i+1; j < sSize; ++j){
                if((s[i] == s[j] && t[i] == t[j]) || s[i] != s[j] && t[i] != t[j]){
                    test = 1;
                }else{
                    test = 0;
                    return test;
                }
            }
        }
    }
    return test;
}