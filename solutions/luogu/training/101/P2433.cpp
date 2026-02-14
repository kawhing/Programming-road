#include <bits/stdc++.h>
using namespace std;

void problem1() {
    cout << "I love Luogu!" << endl;
}

void problem2() {
    cout << 6 << " " << 4 << endl;
}

void problem3() {
    cout << 3 << endl;
    cout << 12 << endl;
    cout << 2 << endl;
}

void problem4() {
    cout << 166.667 << endl;
}

void problem5() {
    cout << (260 + 220) / 32 << endl;  // 15秒，整数
}

void problem6() {
    cout << sqrt(36 + 81) << endl;  // 对角线长度 ≈10.8167
}

void problem7() {
    cout << 110 << endl;
    cout << 90 << endl;
    cout << 0 << endl;
}

void problem8() {
    double PI = 3.141593;
    cout << PI * 2 * 5 << endl;
    cout << PI * 25 << endl;
    cout << PI * 125 * (4.0 / 3) << endl;
}

void problem9() {
    cout << (((1 + 1) * 2 + 1) * 2 + 1) * 2 << endl;
}

void problem10() {
    cout << 9 << endl;
}

void problem11() {
    cout << 100.0 / 3 << endl;
}

void problem12() {
    cout << 'M' - 'A' + 1 << endl;
    cout << 'R' << endl; 
}

void problem13() {
    double PI = 3.141593;
    double V = (4.0 / 3) * PI * (4*4*4 + 10*10*10);
    double a = cbrt(V);
    int ans = floor(a);
    cout << ans << endl;
}

void problem14() {
    // 方程 x*(120-x) = 3500  -> x^2 - 120x + 3500 = 0
    int delta_sqrt = 20;  // sqrt(120^2 - 4*3500) = 20
    int ans1 = (120 + delta_sqrt) / 2;
    int ans2 = (120 - delta_sqrt) / 2;
    cout << min(ans1, ans2) << endl;  // 50
}

void solve(int n) {
    if (n == 1) problem1();
    else if (n == 2) problem2();
    else if (n == 3) problem3();
    else if (n == 4) problem4();
    else if (n == 5) problem5();
    else if (n == 6) problem6();
    else if (n == 7) problem7();
    else if (n == 8) problem8();
    else if (n == 9) problem9();
    else if (n == 10) problem10();
    else if (n == 11) problem11();
    else if (n == 12) problem12();
    else if (n == 13) problem13();
    else if (n == 14) problem14();
}

int main() {
    int n;
    cin >> n;
    solve(n);
    return 0;
}