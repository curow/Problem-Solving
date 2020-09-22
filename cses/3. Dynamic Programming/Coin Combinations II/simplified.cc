#include <bits/stdc++.h>
using namespace std;

const int N = 110, X = 1e6 + 10, MOD = 1e9 + 7;
int c[N], f[X];

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
    for (int i = 1; i <= n; ++i) cin >> c[i];

    f[0] = 1;
    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i <= x; ++i) {
            if (i >= c[j])
                f[i] = (f[i] + f[i - c[j]]) % MOD;
        }
    }
    cout << f[x] << endl;

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
