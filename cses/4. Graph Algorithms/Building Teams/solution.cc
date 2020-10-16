#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> adj[N];
bool visited[N];
int team[N];

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
        queue<int> q;
        q.push(i);
        team[i] = 1;
        visited[i] = true;
        while (!q.empty()) {
            int s = q.front(); q.pop();
            for (int x : adj[s]) {
                if (visited[x]) {
                    if (team[x] == team[s]) {
                        cout << "IMPOSSIBLE" << endl;
                        return;
                    } else {
                        continue;
                    }
                }
                q.push(x);
                team[x] = 3 - team[s];
                visited[x] = true;
            }
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
