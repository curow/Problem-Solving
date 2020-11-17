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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<pll> adj[n + 1];
    for (int i = 0; i < m; ++i) {
        ll a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    ll visit_count[n + 1];
    for (int i = 1; i <= n; ++i) visit_count[i] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 1});
    vector<ll> k_shortest_cost;
    while (!pq.empty()) {
        ll c, a;
        tie(c, a) = pq.top(); pq.pop();
        if (visit_count[a] >= k) continue;
        if (a == n) k_shortest_cost.push_back(c);
        ++visit_count[a];
        for (auto u : adj[a]) {
            ll b, w;
            tie(b, w) = u;
            pq.push({c + w, b});
        }
    }
    for (ll c : k_shortest_cost) cout << c << " ";
    cout << endl;
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
