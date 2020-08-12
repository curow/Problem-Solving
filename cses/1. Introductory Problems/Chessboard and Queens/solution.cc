#include <bits/stdc++.h>

using namespace std;


int main() {
    const int n = 8;
    vector<vector<bool>> free(n, vector<bool>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char x;
            cin >> x;
            free[i][j] = x == '.' ? true : false;
        }
    }
    vector<bool> column(n, true), diag_up(2 * n - 2, true), diag_down(2 * n - 2, true);
    int count = 0;
    function<void(int)> search;
    search = [&](int y) {
        if (y == n) {
            ++count;
        } else {
            for (int x = 0; x < n; ++x) {
                if (free[y][x] && column[x] && diag_up[x + y] && diag_down[x + (n - 1 - y)]) {
                    column[x] = diag_up[x + y] = diag_down[x + (n - 1 - y)] = false;
                    search(y + 1);
                    column[x] = diag_up[x + y] = diag_down[x + (n - 1 - y)] = true;
                }
            }
        }
    };
    search(0);
    cout << count << endl;
    return 0;
}
