int strStr(char* haystack, char* needle) {
    if (strlen(needle) == 0) {
        return 0;
    }
    
    for (int i = 0; haystack[i] != '\0'; ++i){
        if(strncmp(haystack + i, needle, strlen(needle)) == 0){
            return i;
        }
    }
    
    return -1;
}