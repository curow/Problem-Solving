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
    vector<vector<ll>> original(n + 1), reversed(n + 1);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        original[a].push_back(b);
        reversed[b].push_back(a);
    }
    vector<ll> post_order;
    post_order.reserve(n);
    bool visited[n + 1];
    for (ll i = 1; i <= n; ++i) visited[i] = false;
    function<void(ll, vector<vector<ll>>&, vector<ll>&)> dfs;
    dfs = [&](ll x, vector<vector<ll>>& adj, vector<ll>& nodes) -> void {
        if (visited[x]) return;
        visited[x] = true;
        for (ll u : adj[x]) {
            dfs(u, adj, nodes);
        }
        nodes.push_back(x);
    };
    for (ll i = 1; i <= n; ++i) dfs(i, original, post_order);
    for (ll i = 1; i <= n; ++i) visited[i] = false;
    for (auto it = post_order.rbegin(); it != post_order.rend(); ++it) {
        vector<ll> component;
        dfs(*it, reversed, component);
        if (component.size() > 1) {
            bool visited_again[n + 1];
            ll pre[n + 1];
            for (ll i = 1; i <= n; ++i) {
                visited_again[i] = false;
                pre[i] = -1;
            }
            function<bool(ll)> output_cycle = [&](ll x) {
                if (visited_again[x]) {
                    vector<ll> cycle;
                    cycle.push_back(x);
                    for (ll i = pre[x]; i != x; i = pre[i]) {
                        cycle.push_back(i);
                    }
                    cycle.push_back(x);
                    cout << cycle.size() << endl;
                    for (auto it = cycle.rbegin(); it != cycle.rend(); ++it) {
                        cout << *it << " ";
                    }
                    cout << endl;
                    return true;
                }
                visited_again[x] = true;
                for (ll u : original[x]) {
                    pre[u] = x;
                    if (output_cycle(u)) return true;
                }
                return false;
            };
            output_cycle(component[0]);
            return;
        }
    }
    cout << "IMPOSSIBLE" << endl;
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
