#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> adj[N];
bool visited[N];
int parent[N];

vector<int> route;
bool dfs(int s, int p) {
    visited[s] = true;
    parent[s] = p;
    for (int x : adj[s]) {
        if (visited[x]) {
            if (x == p) continue;
            vector<int> circle;
            circle.push_back(x);
            for (int v = s; v != x; v = parent[v]) {
                circle.push_back(v);
            }
            circle.push_back(x);
            cout << circle.size() << endl;
            for (int v : circle) {
                cout << v << " ";
            }
            cout << endl;
            return true;
        } else if (dfs(x, s)) {
            return true;
        }
    }
    return false;
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
        if (dfs(i, -1)) return;
    }
    cout << "IMPOSSIBLE" << endl;
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
