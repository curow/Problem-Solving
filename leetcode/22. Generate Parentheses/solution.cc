class Solution {
public:
    unordered_set<string> ss;

    int balance(string s) {
        int res = 0;
        for (char c : s) {
            if (c == '(') ++res;
            else --res;
        }
    }

    void generateAll(string build, int remain) {
        if (balance(build) > 0) return;
        if (remain == 0) {
            if (balance(build) == 0) {
                ss.insert(build);
            }
            return;
        }
        generateAll(build + "(", remain - 1);
        generateAll(build + ")", remain - 1);
    }

    vector<string> generateParenthesis(int n) {
        generateAll("", n * 2);
        return vector<string>(ss.begin(), ss.end());
    }
};
