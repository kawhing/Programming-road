char* addBinary(char* a, char* b) {
int len1 = strlen(a);
    int len2 = strlen(b);
    int maxlen = len1 > len2 ? len1 : len2;
    int carry = 0;
    char* result = (char*)malloc((maxlen + 2) * sizeof(char)); 
    result[maxlen + 1] = '\0';

    int i = len1 - 1, j = len2 - 1, k = maxlen;
    while (i >= 0 || j >= 0 || carry > 0) {
        if (i >= 0) {
            carry += a[i--] - '0';
        }
        if (j >= 0) {
            carry += b[j--] - '0';
        }
        result[k--] = (carry % 2) + '0';
        carry /= 2;
    }

    return &result[k+1];
}