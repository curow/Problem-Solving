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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> distance(n + 1, vector<ll>(n + 1, INF));
    for (int i = 0; i < m; ++i) {
        ll a, b, w;
        cin >> a >> b >> w;
        distance[a][b] = distance[b][a] = min(distance[a][b], w);
    }
    for (int i = 1; i <= n; ++i) distance[i][i] = 0;
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                distance[i][j] = min(distance[i][j],
                                     distance[i][k] + distance[k][j]);
                distance[j][i] = distance[i][j];
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        cout << (distance[a][b] != INF ? distance[a][b] : -1) << endl;
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
