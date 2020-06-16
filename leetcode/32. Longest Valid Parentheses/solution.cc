class Solution {
public:
    int longestValidParentheses(string s) {
        int n = size(s);
        int left = 0, right = 0, res = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') ++left;
            else ++right;

            if (left == right) {
                res = max(res, left * 2);
            } else if (left < right) {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '(') ++left;
            else ++right;

            if (left == right) {
                res = max(res, left * 2);
            } else if (left > right) {
                left = right = 0;
            }
        }
        return res;
    }
};
