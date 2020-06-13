typedef long long LL;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        LL dvd = llabs(dividend), dvs = llabs(divisor), ans = 0;
        while (dvs <= dvd) {
            LL temp = dvs, m = 1;
            while ((temp << 1) <= dvd) {
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            ans += m;
        }
        return sign * ans;
    }
};
