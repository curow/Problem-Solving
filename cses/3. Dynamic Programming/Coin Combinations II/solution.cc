#include <bits/stdc++.h>
using namespace std;

const int K = 110, N = 1e6 + 10, MOD = 1e9 + 7;
int k, n, c[K], f[N][K];
bool solved[N][K];

int solve(int x, int i) {
    if (x < 0 || i < 0) return 0;
    else if (x == 0) return 1;
    else if (i == 0) return 0;
    else if (solved[x][i]) return f[x][i];
    else {
        f[x][i] = solve(x - c[i], i) + solve(x, i - 1);
        f[x][i] %= MOD;
        solved[x][i] = true;
        return f[x][i];
    }
}

int main() {
    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif
    #ifdef DEBUG
    freopen("input.txt", "r", stdin); // redirects standard input
    freopen("output.txt", "w", stdout); // redirects standard output
    #endif

    // solve the problem
    cin >> k >> n;
    for (int i = 1; i <= k; ++i) cin >> c[i];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= k; ++j)
            solved[i][j] = false;
    cout << solve(n, k) << endl;

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
