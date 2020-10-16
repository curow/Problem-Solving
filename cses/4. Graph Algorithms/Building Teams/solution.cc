#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> adj[N];
bool visited[N];
int team[N];

bool dfs(int s) {
    for (int x : adj[s]) {
        if (visited[x]) {
            if (team[x] == team[s]) return false;
            else continue;
        }
        visited[x] = true;
        team[x] = 3 - team[s];
        if (!dfs(x)) return false;
    }
    return true;
}
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        if (visited[i]) continue;
        visited[i] = true;
        team[i] = 1;
        if (!dfs(i)) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    for (int i = 1; i <= n; ++i) cout << team[i] << " ";
    cout << endl;
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
