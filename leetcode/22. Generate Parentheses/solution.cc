class Solution {
public:
    unordered_set<string> ss;

    bool balance(string s) {
        int res = 0;
        for (char c : s) {
            if (c == '(') --res;
            else ++res;
            if (res > 0) return false;
        }
        return res == 0;
    }


    void generateAll(string build, int open, int close, int max) {
        if (open == close && open == max) {
            if (balance(build)) {
                ss.insert(build);
            }
            return;
        }
        if (open < max) {
            generateAll(build + "(", open + 1, close, max);
        }
        if (close < open) {
            generateAll(build + ")", open, close + 1, max);
        }
    }

    vector<string> generateParenthesis(int n) {
        generateAll("", 0, 0, n);
        return vector<string>(ss.begin(), ss.end());
    }
};
