#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// 定义一个函数，检查字符串s是否可以由它的一个子串重复多次构成
bool repeatedSubstringPattern(char * s){
    // 获取字符串s的长度
    int n = strlen(s);
    // 遍历可能的子串长度，从1到字符串长度的一半
    for (int len = 1; len <= n / 2; len++) {
        // 如果字符串长度可以被子串长度整除，那么可能存在一个重复的子串
        if (n % len == 0) {
            // 假设找到了一个重复的子串
            bool found = true;
            // 遍历字符串，检查每个字符是否与子串的对应字符相同
            for (int i = len; i < n; i++) {
                // 如果字符不同，那么假设失败，跳出循环
                if (s[i] != s[i % len]) {
                    found = false;
                    break;
                }
            }
            // 如果找到了一个重复的子串，返回true
            if (found) {
                return true;
            }
        }
    }
    // 如果没有找到重复的子串，返回false
    return false;
}

int main() {
    //定义三个测试字符串
    char *s1 = "abab";
    char *s2 = "aba";
    char *s3 = "abcabcabcabc";

    // 打印测试结果
    printf("s1: %s\n", repeatedSubstringPattern(s1) ? "true" : "false");
    printf("s2: %s\n", repeatedSubstringPattern(s2) ? "true" : "false");
    printf("s3: %s\n", repeatedSubstringPattern(s3) ? "true" : "false");

    return 0;
}
