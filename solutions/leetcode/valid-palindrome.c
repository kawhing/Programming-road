bool isPalindrome(char* s) {
    int len = strlen(s);
    char str[len + 1];

    int num = 0;
    for(int i = 0; i < len; ++i){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            str[num] = s[i] + 32;
            ++num;
        }else if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            str[num] = s[i];
            ++num;
        }
    }
    str[num] = '\0';

    len = strlen(str);
    for(int i = 0; i < len/2; ++i){
        if(str[i] != str[len-i-1]){
            return false;
        }
    }

    return true;
}