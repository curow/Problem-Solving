#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
char building[N][N];
int n, m;
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > m) return;
    if (building[x][y] == '#') return;
    building[x][y] = '#';
    for (auto &[dx, dy] : directions) {
        dfs(x + dx, y + dy);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <=m; ++j) {
            cin >> building[i][j];
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (building[i][j] == '#') continue;
            ++cnt;
            dfs(i, j);
        }
    }
    cout << cnt << endl;
}

int main() {
#ifdef TIMING
    auto start = chrono::steady_clock::now();
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);  // redirects standard input
    /* freopen("output.txt", "w", stdout); // redirects standard output */
#endif
    // solve the problem
    solve();
#ifdef TIMING
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
#endif
    return 0;
}
