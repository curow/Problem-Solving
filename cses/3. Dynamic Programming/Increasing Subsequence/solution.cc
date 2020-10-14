#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<int> dp;
    dp.reserve(n);
    dp.push_back(a[1]);
    for (int i = 2; i <= n; ++i) {
        auto it = upper_bound(dp.begin(), dp.end(), a[i]);
        if (it == dp.end() && dp.back() < a[i]) dp.push_back(a[i]);
        else if (it == dp.begin() || *(it - 1) < a[i]) *it = a[i];
    }
    cout << dp.size() << endl;
}

int main() {
#ifdef TIMING
    auto start = chrono::steady_clock::now();
#endif
    ios_base::sync_with_stdio(0);
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
