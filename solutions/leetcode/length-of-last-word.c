int lengthOfLastWord(char* s) {
    int len = strlen(s);
    int test = 1;

    for(int i = 0; i < len; ++i){
        if(s[i] == ' '){
            test = 0;
        }
    }

    if(test == 1){
        return len;
    }else{
        for(int i = len-1; i >= 0; --i){
            if(s[i] != ' ' && i != 0){
                for(int j = i-1; j >= 0; --j){
                    if(s[j] == ' '){
                        return i-j;
                    }                  
                }

                for(int j = i-1; j >= 0; --j){
                    if(s[j] != ' '){
                        test = 1;
                    }
                }

                if(test == 1){
                    return i+1;
                }
            }else if(s[i] != ' ' && i == 0){
                return 1;
            }
        }
    }   
    return -1;    
}