#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e3 + 10, INF = 1e9;
char maze[N][N];
bool visited[N][N];
int danger[N][N];
int n, m;
int si, sj;
vector<pair<int, int>> monsters;
map<char, pair<int, int>> directions = {
    {'U', {-1, 0}}, {'D', {1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}
};
map<char, char> reverse_direction = {
    {'U', 'D'}, {'D', 'U'}, {'L', 'R'}, {'R', 'L'}
};
 
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> maze[i][j];
            if (maze[i][j] == 'M') {
                danger[i][j] = 0;
                monsters.push_back({i, j});
            } else {
                danger[i][j] = INF;
                if (maze[i][j] == 'A') {
                    tie(si, sj) = {i, j};
                }
            }
        }
    }
    if (si == 1 || si == n || sj == 1 || sj == m) {
        cout << "YES" << endl;
        cout << 0 << endl;
        return;
    }
    for (auto [mi, mj] : monsters) {
        queue<tuple<int, int, int>> q;
        q.push({mi, mj, 0});
        visited[mi][mj] = true;
        while (!q.empty()) {
            int i, j, d;
            tie(i, j, d) = q.front();
            q.pop();
            for (const auto [_, delta] : directions) {
                int ni = i + delta.first, nj = j + delta.second;
                if (ni < 1 || ni > n || nj < 1 || nj > m) continue;
                if (visited[ni][nj] || maze[ni][nj] == '#' || maze[ni][nj] == 'M') continue;
                danger[ni][nj] = min(danger[ni][nj], d + 1);
                q.push({ni, nj, d + 1});
                visited[ni][nj] = true;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                visited[i][j] = false;
            }
        }
    }
    queue<tuple<int, int, int>> q;
    q.push({si, sj, 0});
    visited[si][sj] = true;
    while (!q.empty()) {
        int i, j, d;
        tie(i, j, d) = q.front();
        q.pop();
        for (const auto [ch, delta] : directions) {
            int ni = i + delta.first, nj = j + delta.second;
            if (ni < 1 || ni > n || nj < 1 || nj > m) continue;
            if (visited[ni][nj] || maze[ni][nj] == '#' || maze[ni][nj] == 'M') continue;
            if (danger[ni][nj] > d + 1) {
                q.push({ni, nj, d + 1});
                visited[ni][nj] = true;
                maze[ni][nj] = ch;
                if (ni == 1 || ni == n || nj == 1 || nj == m) {
                    string solution = "";
                    int ti = ni, tj = nj;
                    while (maze[ti][tj] != 'A') {
                        char code = maze[ti][tj];
                        solution += code;
                        ti += directions[reverse_direction[code]].first;
                        tj += directions[reverse_direction[code]].second;
                    }
                    reverse(solution.begin(), solution.end());
                    cout << "YES" << endl;
                    cout << solution.size() << endl;
                    cout << solution << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl;
}
 
int main() {
#ifdef TIMING
    auto start = chrono::steady_clock::now();
#endif
    ios_base::sync_with_stdio(false);
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
