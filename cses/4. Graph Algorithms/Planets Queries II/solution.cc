#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

const lld PI = 3.14159265358979323846;
const ll MOD = 1000000007;
const ll INF = 1e18;

void solve() {
    ll n, q;
    cin >> n >> q;
    ll succ[n + 1], dist[n + 1][n + 1];
    for (ll i = 1; i <= n; ++i) {
        cin >> succ[i];
    }
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
        dist[i][succ[i]] = min(dist[i][succ[i]], 1ll);
    }
    bool visited[n + 1];
    for (ll i = 1; i <= n; ++i) visited[i] = false;
    vector<ll> post_order;
    function<pair<bool, ll>(ll, vector<ll>&)> find_cycle = [&](ll x, vector<ll>& nodes) {
        if (visited[x]) return make_pair(true, x);
        visited[x] = true;
        if (succ[x] == x) {
            nodes.push_back(x);
            return make_pair(false, -1ll);
        } else {
            auto result = find_cycle(succ[x], nodes);
            nodes.push_back(x);
            return result;
        }
    };
    for (ll i = 1; i <= n; ++i) {
        if (visited[i]) continue;
        auto [has_cycle, first_node_in_cycle] = find_cycle(i, post_order);
        if (has_cycle) {
            ll d = 1;
            ll temp = succ[first_node_in_cycle];
            while (temp != first_node_in_cycle) {
                dist[first_node_in_cycle][temp] = d;
                temp = succ[temp];
                ++d;
            }
            for (auto it = post_order.rbegin(); *it != first_node_in_cycle; ++it) {
                ll x = *it;
                for (ll c : post_order) {
                    dist[x][c] = min(dist[x][c], dist[succ[x]][c] + 1);
                }
            }
        }
        for (auto it = post_order.begin(); it != post_order.end(); ++it) {
            ll x = *it;
            for (ll c : post_order) {
                dist[x][c] = min(dist[x][c], dist[succ[x]][c] + 1);
            }
        }
        post_order.clear();
    }
    for (ll i = 0; i < q; ++i) {
        ll a, b;
        cin >> a >> b;
        if (dist[a][b] != INF) cout << dist[a][b] << endl;
        else cout << -1 << endl;
    }
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
