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
    ll n, m;
    cin >> n >> m;
    vector<ll> adj[n + 1], reversed[n + 1];
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        reversed[b].push_back(a);
    }
    bool visited[n + 1];
    for (ll i = 1; i <= n; ++i) visited[i] = false;
    vector<ll> post_order;
    post_order.reserve(n);
    function<void(ll)> dfs = [&](ll x) {
        if (visited[x]) return;
        visited[x] = true;
        for (ll u : adj[x]) {
            dfs(u);
        }
        post_order.push_back(x);
    };
    for (ll i = 1; i <= n; ++i) dfs(i);
    bool impossible = false;
    auto it = post_order.rbegin();
    while (it != post_order.rend()) {
        if (*it == 1) {
            break;
        } else if (*it == n) {
            impossible = true;
            break;
        }
        ++it;
    }
    if (impossible) {
        cout << 0 << endl;
        return;
    }
    ll dp[n + 1];
    for (ll i = 1; i <= n; ++i) dp[i] = 0;
    dp[1] = 1;
    while (it != post_order.rend()) {
        ll x = *it;
        for (ll u : reversed[x]) {
            dp[x] += dp[u];
            dp[x] %= MOD;
        }
        if (x == n) break;
        ++it;
    }
    cout << dp[n] << endl;
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
