class Solution {
public:
    int longestValidParentheses(string s) {
        int n = size(s);
        vector<int> dp(n, 0);
        int res = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (dp[i - 1] > 0 && i - 1 - dp[i - 1] >= 0 && s[i - 1 - dp[i - 1]] == '(') {
                    dp[i] = dp[i - 1] + 2 + (i - 1 - dp[i - 1] - 1 >= 0? dp[i - 1 - dp[i - 1] - 1] : 0);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
