class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            unordered_map<char, int> hash_row, hash_col;
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') ++hash_row[board[i][j]];
                if (board[j][i] != '.') ++hash_col[board[j][i]];
                if (hash_row[board[i][j]] > 1 || hash_col[board[j][i]] > 1) {
                    return false;
                }
            }
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                unordered_map<char, int> hash;
                for (int k = 0; k < 3; ++k) {
                    for (int s = 0; s < 3; ++s) {
                        char x = board[i * 3 + k][j * 3 + s];
                        if (x == '.') continue;
                        ++hash[x];
                        if (hash[x] > 1) return false;
                    }
                }
            }
        }
        return true;
    }
};
