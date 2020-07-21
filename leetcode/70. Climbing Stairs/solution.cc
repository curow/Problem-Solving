class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        for (int i = 0; i < n - 1; ++i) {
            int x = b;
            b += a;
            a = x;
        }
        return b;
    }
};
