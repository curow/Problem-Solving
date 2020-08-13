#include <bits/stdc++.h>

using namespace std;

int main() {
    const int n = 7;
    vector<vector<bool>> free(n + 2, vector<bool>(n + 2, true));
    for (int k = 0; k <= n + 1; ++k) {
        free[0][k] = free[n + 1][k] = free[k][0] = free[k][n + 1] = false;
    }
    int count = 0;
    vector<pair<int, int>> go = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    function<void(int, int, int)> search;
    search = [&](int y, int x, int p) {
        if (p == n * n + 1) {
            if (y == n && x == n)
                ++count;
            return;
        } else if (y == n && x == n) {
            return;
        } else {
            bool up = free[y - 1][x], down = free[y + 1][x];
            bool left = free[y][x - 1], right = free[y][x + 1];
            if (left && right && !up && !down) return;
            if (up && down && !left && !right) return;
            for (auto &[dy, dx] : go) {
                int ny = y + dy, nx = x + dx;
                if (free[ny][nx]) {
                    free[ny][nx] = false;
                    search(ny, nx, p + 1);
                    free[ny][nx] = true;
                }
            }
        }
    };
    free[1][1] = free[1][2] = false;
    search(1, 2, 3);
    cout << count * 2 << endl;
    return 0;
}
