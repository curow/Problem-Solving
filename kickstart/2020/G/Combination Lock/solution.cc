#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 2e18;

void solve() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        ll w, n;
        cin >> w >> n;
        vector<ll> wheels(w);
        for (ll &x : wheels) cin >> x;
        sort(wheels.begin(), wheels.end());
        long long best = INF;
        for (ll x : wheels) {
            ll cnt = 0;
            for (ll y : wheels) {
                ll cost = min(abs(x - y), n - abs(x - y));
                cnt += cost;
            }
            best = min(best, cnt);
        }
        cout << "Case #" << t << ": " << best << endl;
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
