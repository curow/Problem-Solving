#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

const lld PI = 3.14159265358979323846;
const ll MOD = 1000000007;
const ll INF = 1e18;
const ll EXP = 30;

void solve() {
    ll n, q;
    cin >> n >> q;
    ll succ[n + 1][EXP + 1];
    for (ll i = 1; i <= n; ++i) {
        cin >> succ[i][0];
    }
    for (ll j = 1; j <= EXP; ++j) {
        for (ll i = 1; i <= n; ++i) {
            succ[i][j] = succ[succ[i][j - 1]][j - 1];
        }
    }
    for (ll i = 0; i < q; ++i) {
        ll x, k;
        cin >> x >> k;
        ll e = 0;
        while (k > 0) {
            bool walk = k % 2;
            if (walk) {
                x = succ[x][e];
            }
            k /= 2;
            ++e;
        }
        cout << x << endl;
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
