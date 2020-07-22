class Solution {
public:
    int waysToStep(int n) {
        const int mod = 1e9 + 7;
        int a, b, c;
        tie(a, b, c) = make_tuple(1, 2, 4);
        if (n == 1) return a;
        else if (n == 2) return b;
        else if (n == 3) return c;
        for (int i = 4; i <= n; ++i) {
            tie(a, b, c) = make_tuple(b, c, ((a + b) % mod + c) % mod);
        }
        return c;
    }
};
