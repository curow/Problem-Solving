#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> matrix(n + 2, vector<int>(m + 2, 0));
    auto insert = [&](int x1, int y1, int x2, int y2, int c) {
        matrix[x1][y1] += c;
        matrix[x1][y2 + 1] -= c;
        matrix[x2 + 1][y1] -= c;
        matrix[x2 + 1][y2 + 1] += c;
    };
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int x;
            cin >> x;
            insert(i, j, i, j, x);
        }
    }
    while (q--) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            matrix[i][j] += matrix[i - 1][j] + matrix[i][j - 1] - matrix[i - 1][j - 1];
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
