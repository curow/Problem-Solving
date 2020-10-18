#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> adj[N];
bool visited[N];

vector<int> route;
int dfs(int s) {
    if (visited[s]) {
        int len = route.size();
        if (len <= 3) return 0;
        int cnt = 1;
        do {
            ++cnt;
        } while (len - cnt >= 0 && route[len - cnt] != route.back());
        if (cnt >= 4) return cnt;
        else return 0;
    }
    visited[s] = true;
    for (int x : adj[s]) {
        route.push_back(x);
        int cnt = dfs(x);
        if (cnt) return cnt;
        route.pop_back();
    }
    return 0;
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
        route.push_back(i);
        int cnt = dfs(i);
        if (cnt) {
            cout << cnt << endl;
            int len = route.size();
            for (int j = len - cnt; j <= len - 1; ++j) cout << route[j] << " ";
            cout << endl;
            return;
        }
        route.pop_back();
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
