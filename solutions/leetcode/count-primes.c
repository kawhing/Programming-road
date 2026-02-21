int countPrimes(int n) {
    if (n <= 2) return 0;
    int count = 0;
    int mark[n];
    for (int i = 0; i < n; ++i) {
        mark[i] = 1;
    }
    for (int i = 2; i * i < n; ++i) {
        if (mark[i]) {
            for (int j = i * i; j < n; j += i) {
                mark[j] = 0;
            }
        }
    }
    for (int i = 2; i < n; ++i) {
        if (mark[i]) ++count;
    }
    return count;
}