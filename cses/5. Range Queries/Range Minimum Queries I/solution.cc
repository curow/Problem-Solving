#include <bits/stdc++.h>
#define int __int64_t
using namespace std;

const int N = 2e5 + 10, K = 18;
int f[N][K + 1], log_table[N];


__int32_t main() {
    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // solve the problem
    log_table[1] = 0;
    for (int i = 2; i < N; ++i) {
        log_table[i] = log_table[i / 2] + 1;
    }
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> f[i][0];
    }
    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 0; i + (1 << j) <= n; ++i) {
            f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        int j = log_table[b - a + 1];
        cout << min(f[a][j], f[b - (1 << j) + 1][j]) << endl;
    }

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
