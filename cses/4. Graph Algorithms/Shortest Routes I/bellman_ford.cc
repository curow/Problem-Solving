#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;

const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;
const ll INF = 1e18;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    edges.reserve(m);
    for (int i = 0; i < m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    ll distance[n + 1];
    for (int i = 1; i <= n; ++i) distance[i] = INF;
    distance[1] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (auto e : edges) {
            ll a, b, c;
            tie(a, b, c) = e;
            distance[b] = min(distance[b], distance[a] + c);
        }
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
