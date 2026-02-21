class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; // Handle overflow case
        }

        long long a = labs((long long)dividend);
        long long b = labs((long long)divisor);
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;

        long long result = 0;
        while (a >= b) {
            long long temp = b, multiple = 1;
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }
            result += multiple;
            a -= temp;
        }

        return sign == 1 ? result : -result;
    }
};