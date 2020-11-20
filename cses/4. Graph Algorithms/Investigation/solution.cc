#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef tuple<long long, long long, long long> tll;

const lld PI = 3.14159265358979323846;
const ll MOD = 1000000007;
const ll INF = 1e18;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<pll> adj[n + 1];
    vector<ll> pre[n + 1];
    vector<tll> edges;
    edges.reserve(m);
    for (ll i = 0; i < m; ++i) {
        ll a, b, w;
        cin >> a >> b >> w;
        edges.push_back({a, b, w});
    }
    sort(edges.begin(), edges.end());
    ll last_a, last_b, last_w;
    last_a = last_b = 0;
    last_w = INF;
    for (auto e : edges) {
        ll a, b, w;
        tie(a, b, w) = e;
        if (last_a == a && last_b == b && w > last_w) continue;
        adj[a].push_back({b, w});
        pre[b].push_back(a);
        tie(last_a, last_b, last_w) = e;
    }
    ll dist[n + 1], visited[n + 1];
    dist[1] = 0;
    for (ll i = 2; i <= n; ++i) dist[i] = INF;
    for (ll i = 1; i <= n; ++i) visited[i] = false;
    set<ll> shortest_pre[n + 1];
    vector<ll> order;
    priority_queue<tll, vector<tll>, greater<tll>> pq;
    pq.push({0, 1, 1});
    while (!pq.empty()) {
        ll c, a, p;
        tie(c, a, p) = pq.top(); pq.pop();
        if (!visited[a]) {
            visited[a] = true;
            order.push_back(a);
            dist[a] = c;
            for (auto u : adj[a]) {
                ll b, w;
                tie(b, w) = u;
                if (dist[a] + w <= dist[b]) {
                    pq.push({dist[a] + w, b, a});
                }
            }
        }
        if (c > dist[a]) continue;
        shortest_pre[a].insert(p);
    }
    ll cnt[n + 1], mi[n + 1], mx[n + 1];
    for (ll x : order) {
        if (x == 1) {
            cnt[x] = 1;
            mi[x] = 0;
            mx[x] = 0;
        } else {
            cnt[x] = 0;
            mi[x] = INF;
            mx[x] = -INF;
            for (ll p : pre[x]) {
                if (!shortest_pre[x].count(p)) continue;
                cnt[x] += cnt[p];
                cnt[x] %= MOD;
                mi[x] = min(mi[x], mi[p] + 1);
                mx[x] = max(mx[x], mx[p] + 1);
            }
        }
    }
    cout << dist[n] << " " << cnt[n] << " " << mi[n] << " " << mx[n] << endl;
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
