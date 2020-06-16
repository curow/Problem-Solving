class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {

        function<vector<char>(int, int)> get_avaiable_nums = [&](int i, int j) {
            vector<char> not_used;
            set<char> used;
            for (int k = 0; k < 9; ++k) {
                used.insert(board[i][k]);
                used.insert(board[k][j]);
                used.insert(board[(i / 3) * 3 + k / 3][(j / 3) * 3 + k % 3]);
            }
            for (char x = '1'; x <= '9'; ++x) {
                if (used.count(x) == 0) not_used.push_back(x);
            }
            return not_used;
        };

        function<bool()> solve = [&]() {
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    if (board[i][j] == '.') {
                        vector<char> avaiable_nums = get_avaiable_nums(i, j);
                        if (avaiable_nums.empty()) return false;
                        for (char x : avaiable_nums) {
                            board[i][j] = x;
                            bool success = solve();
                            if (success) return true;
                            else board[i][j] = '.';
                        }
                        return false;
                    }
                }
            }
            return true;
        };

        solve();
    }
};
