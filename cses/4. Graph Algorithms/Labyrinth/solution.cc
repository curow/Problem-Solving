#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
char maze[N][N];
int n, m;
vector<tuple<int, int, char>> directions = {{-1, 0, 'U'}, {1, 0, 'D'}, {0, -1, 'L'}, {0, 1, 'R'}};
map<char, pair<int, int>> back_home = {{'D', {-1, 0}}, {'U', {1, 0}}, {'R', {0, -1}}, {'L', {0, 1}}};

vector<char> solution;
bool bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty()) {
        int a, b;
        tie(a, b) = q.front(); q.pop();
        for (auto [da, db, code] : directions) {
            int na = a + da, nb = b + db;
            if (na < 1 || na > n || nb < 1 || nb > m) continue;
            if (maze[na][nb] == 'B') {
                x = na, y = nb;
                maze[x][y] = code;
                while (maze[x][y] != 'A') {
                    solution.push_back(maze[x][y]);
                    int dx, dy;
                    tie(dx, dy) = back_home[maze[x][y]];
                    x += dx, y += dy;
                }
                reverse(solution.begin(), solution.end());
                return true;
            }
            if (maze[na][nb] != '.') continue;
            maze[na][nb] = code;
            q.push({na, nb});
        }
    }
    return false;
}

void solve() {
    cin >> n >> m;
    int x = 0, y = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> maze[i][j];
            if (maze[i][j] == 'A') x = i, y = j;
        }
    }
    if (bfs(x, y)) {
        cout << "YES" << endl;
        cout << solution.size() << endl;
        for (char c : solution) cout << c;
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
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
