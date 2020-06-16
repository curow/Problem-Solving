class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {

        auto get_avaiable_nums = [&](int i, int j, vector<char> &not_used) {
            set<char> used;
            for (int k = 0; k < 9; ++k) {
                used.insert(board[i][k]);
                used.insert(board[k][j]);
                used.insert(board[(i / 3) * 3 + k / 3][(j / 3) * 3 + k % 3]);
            }
            for (char x = '1'; x <= '9'; ++x) {
                if (used.count(x) == 0) not_used.push_back(x);
            }
        };

        function<bool(int, int)> solve = [&](int idx) {
            if (idx >= 81) return true;
            for (int k = idx; k < 81; ++k) {
                int i = k / 9, j = k % 9;
                if (board[i][j] == '.') {
                    vector<char> avaiable_nums;
                    get_avaiable_nums(i, j, avaiable_nums);
                    if (avaiable_nums.empty()) return false;
                    for (char x : avaiable_nums) {
                        board[i][j] = x;
                        bool success = solve(k + 1);
                        if (success) return true;
                        else board[i][j] = '.';
                    }
                    return false;
                }
            }
            return true;
        };

        solve();
    }
};class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {

        auto get_avaiable_nums = [&](int i, int j, vector<char> &not_used) {
            set<char> used;
            for (int k = 0; k < 9; ++k) {
                used.insert(board[i][k]);
                used.insert(board[k][j]);
                used.insert(board[(i / 3) * 3 + k / 3][(j / 3) * 3 + k % 3]);
            }
            for (char x = '1'; x <= '9'; ++x) {
                if (used.count(x) == 0) not_used.push_back(x);
            }
        };

        function<bool(int)> solve = [&](int idx) {
            if (idx >= 81) return true;
            for (int k = idx; k < 81; ++k) {
                int i = k / 9, j = k % 9;
                if (board[i][j] == '.') {
                   vector<char> avaiable_nums;
                    get_avaiable_nums(i, j, avaiable_nums);
                    if (avaiable_nums.empty()) return false;
                    for (char x : avaiable_nums) {
                        board[i][j] = x;
                        bool success = solve(k + 1);
                        if (success) return true;
                        else board[i][j] = '.';
                    }
                    return false;
                }
            }
            return true;
        };

        solve(0);
    }
};
