class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1000000007;
        long ans = 0;  // 用 long 防止中间结果溢出
        for (int i = 1; i <= n; ++i) {
            int len = 0;
            // 计算 i 的二进制位数
            for (int x = i; x; x >>= 1) len++;
            // 将 ans 左移 len 位，再加上 i，并取模
            ans = ((ans << len) + i) % MOD;
        }
        return ans;
    }
};