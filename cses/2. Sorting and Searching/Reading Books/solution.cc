#include <bits/stdc++.h>
#define int __int64_t
using namespace std;

const int N = 2e5 + 10;
int a[N], s[N], t[N];

__int32_t main() {
    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // solve the problem
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 2 * a[0] << endl;
        return 0;
    }
    sort(a, a + n);
    s[0] = a[0];
    for (int i = 1; i < n; ++i) {
        s[i] = s[i - 1] + a[i];
    }
    int l = 0, r = n - 1;
    double v = (double) s[n - 1] / 2;
    while (l < r) {
        int m = (l + r) >> 1;
        if (s[m] > v) r = m;
        else l = m + 1;
    }
    int nx = 0, ny = l, tx = 0, ty = 0;
    auto go = [&](int &cur, int &idx) -> void {
        t[idx] = cur = max(cur, t[idx]) + a[idx];
        idx = (idx + 1) % n;
    };
    for (int i = 0; i < n; ++i) {
        go(tx, nx);
        go(ty, ny);
    }
    cout << max(tx, ty) << endl;

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
