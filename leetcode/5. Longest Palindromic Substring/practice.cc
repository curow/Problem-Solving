class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();
        if (n <= 1) return s;
        string best = s.substr(0, 1);
        vector<vector<bool>> f(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) f[i][i] = true;
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j] && (i + 1 >= j - 1 || f[i + 1][j - 1])) {
                    f[i][j] = true;
                    if (len > best.size()) {
                        best = s.substr(i, len);
                    }
                }
            }
        }
        return best;
    }
};
