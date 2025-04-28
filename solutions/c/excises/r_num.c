#include <stdio.h>
#include <string.h>

int romanToInt(char *s) {
    int num = 0;
    int prev = 0;
    
    for (int i = strlen(s) - 1; i >= 0; i--) {// 从右往左遍历
        int current = 0;
        switch (s[i]) {// 从右往左遍历
            case 'I':
                current = 1;
                break;
            case 'V':
                current = 5;
                break;
            case 'X':
                current = 10;
                break;
            case 'L':
                current = 50;
                break;
            case 'C':
                current = 100;
                break;
            case 'D':
                current = 500;
                break;
            case 'M':
                current = 1000;
                break;
            default:
                return -1; // 非法字符
        }
        
        if (current < prev) {
            num -= current;// 例如 IV = 5 - 1
        } else {
            num += current;// 例如 VI = 5 + 1
        }
        
        prev = current;// 保存当前值
    }
    
    return num;
}

int main() {
    char romanNum[64];
    printf("Please enter a roman number: ");
    scanf("%s", romanNum);

    int result = romanToInt(romanNum);
    if (result == -1) {
        printf("Invalid roman number\n");
    } else {
        printf("The equivalent arabic number is: %d\n", result);
    }

    return 0;
}
/*优化后的代码
#include <stdio.h>
#include <string.h>

int romanToInt(char *s) {
    int num = 0;
    int prev = 0;
    int romanValues[26] = {0};
    romanValues['I' - 'A'] = 1;
    romanValues['V' - 'A'] = 5;
    romanValues['X' - 'A'] = 10;
    romanValues['L' - 'A'] = 50;
    romanValues['C' - 'A'] = 100;
    romanValues['D' - 'A'] = 500;
    romanValues['M' - 'A'] = 1000;

    for (int i = strlen(s) - 1; i >= 0; i--) {
        int current = romanValues[s[i] - 'A'];
        if (current == 0) {
            return -1; // 非法字符
        }

        if (current < prev) {
            num -= current;
        } else {
            num += current;
        }

        prev = current;
    }

    return num;
}

int main() {
    char romanNum[64];
    printf("Please enter a roman number: ");
    scanf("%s", romanNum);

    int result = romanToInt(romanNum);
    if (result == -1) {
        printf("Invalid roman number\n");
    } else {
        printf("The equivalent arabic number is: %d\n", result);
    }
    return 0;
}



*/