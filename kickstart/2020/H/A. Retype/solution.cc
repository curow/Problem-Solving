#include <bits/stdc++.h>
using namespace std;

void solve() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        long long n, k, s;
        cin >> n >> k >> s;
        cout << "Case #" << t << ": " << min(k + n, n + 2 * k - 2 * s) << endl;
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
