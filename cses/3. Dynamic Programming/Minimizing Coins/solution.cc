#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, INF = 1e9 + 10;
int f[N];

int main() {
    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif
    #ifdef DEBUG
    freopen("input.txt", "r", stdin); // redirects standard input
    freopen("output.txt", "w", stdout); // redirects standard output
    #endif

    // solve the problem
    int n, x;
    cin >> n >> x;
    int c[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    f[0] = 0;
    for (int j = 1; j <= x; ++j) {
        f[j] = INF;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = x; j >= 1; --j) {
            for (int k = 1; k * c[i] <= j; ++k) {
                f[j] = min(f[j], f[j - k * c[i]] + k);
            }
        }
    }
    if (f[x] == INF) cout << -1 << endl;
    else cout << f[x] << endl;

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
