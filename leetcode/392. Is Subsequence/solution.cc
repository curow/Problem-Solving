class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.size(), m = s.size();
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1, false));
        for (int i = 0; i <= n; ++i) f[i][0] = true;

        s = " " + s;
        t = " " + t;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                f[i][j] = f[i - 1][j] || (t[i] == s[j] && f[i - 1][j - 1]);
            }
        }
        return f[n][m];
    }
};
