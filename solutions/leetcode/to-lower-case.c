char* toLowerCase(char* s) {
    int len = strlen(s);
    for(int i = 0; i < len; ++i){
        if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 32; 
    }
    return s;
}