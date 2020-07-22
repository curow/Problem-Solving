class Solution {
public:
    bool divisorGame(int N) {
        vector<bool> f(N + 1, false);
        for (int i = 2; i <= N; ++i) {
            for (int j = 1; j < i; ++j) {
                if (i % j == 0 && f[i - j] == false) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[N];
    }
};
