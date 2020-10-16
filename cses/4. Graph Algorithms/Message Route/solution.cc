#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> adj[N];
bool visited[N];
int before[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty()) {
        int s = q.front(); q.pop();
        for (int x : adj[s]) {
            if (visited[x]) continue;
            q.push(x);
            visited[x] = true;
            before[x] = s;
        }
    }
    if (!visited[n]) cout << "IMPOSSIBLE" << endl;
    else {
        stack<int> solution;
        int x = n;
        while (x != 1) {
            solution.push(x);
            x = before[x];
        }
        solution.push(1);
        cout << solution.size() << endl;
        while (!solution.empty()) {
            cout << solution.top() << " ";
            solution.pop();
        }
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
