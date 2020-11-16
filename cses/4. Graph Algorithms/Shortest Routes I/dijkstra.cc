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
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; ++i) {
        ll a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    ll distance[n + 1];
    for (int i = 1; i <= n; ++i) distance[i] = INF;
    distance[1] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 1});
    bool processed[n + 1];
    for (int i = 1; i <= n; ++i) processed[i] = false;
    while (!pq.empty()) {
        ll a = pq.top().second; pq.pop();
        if (processed[a]) continue;
        for (auto u : adj[a]) {
            int b, w;
            tie(b, w) = u;
            if (distance[a] + w < distance[b]) {
                distance[b] = distance[a] + w;
                pq.push({distance[b], b});
            }
        }
        processed[a] = true;
    }
    for (int i = 1; i <= n; ++i) cout << distance[i] << " ";
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
