#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main() {
    long long n = 202420242024;
    long long a = 20, b = 24;
    long long lcm_ab = lcm(a, b);

    long long count_a = n / (lcm_ab / a);
    long long count_b = n / (lcm_ab / b);
    long long count_ab = n / lcm_ab;

    long long result = n * (a + b) / 2 - count_ab * lcm_ab;
    cout << result << endl;

    return 0;
}