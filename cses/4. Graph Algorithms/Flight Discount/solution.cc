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
    int n, m;
    cin >> n >> m;
    vector<vector<pll>> original(n + 1), reversed(n + 1);
    vector<tuple<ll, ll, ll>> edges;
    edges.reserve(m);
    for (int i = 0; i < m; ++i) {
        ll a, b, w;
        cin >> a >> b >> w;
        original[a].push_back({b, w});
        reversed[b].push_back({a, w});
        edges.push_back({a, b, w});
    }
    vector<ll> from_1_distance(n + 1), to_n_distance(n + 1);
    auto dijkstra = [&](ll from, vector<ll> &distance, const vector<vector<pll>> &adj) {
        for (int i = 1; i <= n; ++i) distance[i] = INF;
        distance[from] = 0;
        vector<bool> processed(n + 1);
        for (int i = 1; i <= n; ++i) processed[i] = false;
        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.push({0, from});
        while (!pq.empty()) {
            ll a = pq.top().second; pq.pop();
            if (processed[a]) continue;
            for (auto u : adj[a]) {
                ll b, w;
                tie(b, w) = u;
                if (distance[b] > distance[a] + w) {
                    distance[b] = distance[a] + w;
                    pq.push({distance[b], b});
                }
            }
            processed[a] = true;
        }
    };
    dijkstra(1, from_1_distance, original);
    dijkstra(n, to_n_distance, reversed);
    ll ans = INF;
    for (auto e : edges) {
        ll a, b, w;
        tie(a, b, w) = e;
        ans = min(ans, from_1_distance[a] + w / 2 + to_n_distance[b]);
    }
    cout << ans << endl;
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
