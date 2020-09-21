#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, K = 110, MOD = 1e9 + 7;
int n, k, f[K][N], c[K];

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
    for (int i = 0; i <= k; ++i) f[i][0] = 1;

    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <=n; ++j) {
            f[i][j] += f[i - 1][j];
            if (j >= c[i]) f[i][j] += f[i][j - c[i]];
            f[i][j] %= MOD;
        }
    }
    printf("%d\n", f[k][n]);

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
