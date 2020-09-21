#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, K = 110, MOD = 1e9 + 7;
int n, k, f[N][K], c[K];

int main() {
    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif
    #ifdef DEBUG
    freopen("input.txt", "r", stdin); // redirects standard input
    freopen("output.txt", "w", stdout); // redirects standard output
    #endif

    // solve the problem
    scanf("%d %d", &k, &n);
    for (int i = 1; i <= k; ++i) scanf("%d", &c[i]);
    for (int j = 0; j <= k; ++j) f[0][j] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            f[i][j] += f[i][j - 1];
            if (i >= c[j]) f[i][j] += f[i - c[j]][j];
            f[i][j] %= MOD;
        }
    }
    printf("%d\n", f[n][k]);

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
