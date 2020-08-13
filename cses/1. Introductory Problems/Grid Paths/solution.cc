#include <bits/stdc++.h>

using namespace std;

int main() {
    const int n = 7;
    string code;
    cin >> code;
    code = "xx" + code;
    vector<vector<bool>> free(n + 2, vector<bool>(n + 2, true));
    for (int k = 0; k <= n + 1; ++k) {
        free[0][k] = free[n + 1][k] = free[k][0] = free[k][n + 1] = false;
    }
    unordered_map<char, pair<int, int>> go = {{'U', {-1, 0}}, {'D', {1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}};
    int count = 0;
    function<void(int, int, int)> search;
    search = [&](int y, int x, int p) {
        if (p == n * n + 1) {
            if (y == n && x == 1)
                ++count;
            return;
        } else if (y == n && x == 1) {
            return;
        } else {
            bool up = free[y - 1][x], down = free[y + 1][x];
            bool left = free[y][x - 1], right = free[y][x + 1];
            if (up && down && !left && !right) return;
            if (left && right && !up && !down) return;
            if (code[p] == '?') {
                for (auto &[_, direction] : go) {
                    int dy, dx;
                    tie(dy, dx) = direction;
                    int ny = y + dy, nx = x + dx;
                    if (free[ny][nx]) {
                        free[ny][nx] = false;
                        search(ny, nx, p + 1);
                        free[ny][nx] = true;
                    }
                }
            } else if (go.count(code[p])){
                int dy, dx;
                tie(dy, dx) = go[code[p]];
                int ny = y + dy, nx = x + dx;
                if (free[ny][nx]) {
                    free[ny][nx] = false;
                    search(ny, nx, p + 1);
                    free[ny][nx] = true;
                }
            } else {
                throw "Unsupported instruction!";
            }
        }
    };
    free[1][1] = false;
    search(1, 1, 2);
    cout << count << endl;
    return 0;
}
