class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> f(n);
        if (s[0] == '0') {
            return 0;
        } else {
            f[0] = 1;
        }
        for (int i = 1; i < n; ++i) {
            if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i - 1] == '2') {
                    f[i] = i >= 2 ? f[i - 2] : 1;
                } else {
                    return 0;
                }
            } else {
                f[i] = f[i - 1];
                if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                    f[i] += i >= 2 ? f[i - 2] : 1;
                }
            }
        }
        return f[n - 1];
    }
};
