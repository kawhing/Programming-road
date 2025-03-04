#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindromeRange(char* s, int start, int end) {
    for (int i = start, j = end; i < j; i++, j--) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

bool validPalindrome(char* s) {
    int sSize = strlen(s);
    for (int i = 0, j = sSize - 1; i < j; i++, j--) {
        if (s[i] != s[j]) {
            return isPalindromeRange(s, i+1, j) || isPalindromeRange(s, i, j-1);
        }
    }
    return true;
}

int main(){
    if (validPalindrome("abca")) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}