#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;
const ll INF = 1e18;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    edges.reserve(m);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        ll a, b, w;
        cin >> a >> b >> w;
        edges.push_back({a, b, w});
        adj[a].push_back(b);
    }
    ll score[n + 1];
    for (int i = 1; i <= n; ++i) score[i] = -INF;
    score[1] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (auto e : edges) {
            ll a, b, w;
            tie(a, b, w) = e;
            score[b] = max(score[b], score[a] + w);
        }
    }
    ll bug_room = -1;
    for (auto e : edges) {
        ll a, b, w;
        tie(a, b, w) = e;
        if (score[b] < score[a] + w) {
            bug_room = b;
            break;
        }
    }
    if (bug_room != -1) {
        bool visited[n + 1];
        function<void(int)> dfs = [&](int a) -> void {
            visited[a] = true;
            for (auto b : adj[a]) {
                if (visited[b]) continue;
                dfs(b);
            }
        };
        for (int i = 1; i <= n; ++i) visited[i] = false;
        dfs(1);
        if (visited[bug_room]) {
            for (int i = 1; i <= n; ++i) visited[i] = false;
            dfs(bug_room);
            if (visited[n]) {
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << score[n] << endl;
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
