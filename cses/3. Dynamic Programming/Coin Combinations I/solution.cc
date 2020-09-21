#include <bits/stdc++.h>
using namespace std;

const int K = 110, N = 1e6 + 10, MOD = 1e9 + 7;
int k, n, c[K], f[N];
bool solved[N];

int solve(int x) {
    if (x < 0) return 0;
    else if (x == 0) return 1;
    else if (solved[x]) return f[x];
    else {
        f[x] = 0;
        for (int i = 0; i < k; ++i) {
            f[x] += solve(x - c[i]);
            f[x] %= MOD;
        }
        solved[x] = true;
        return f[x];
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
    for (int i = 0; i < k; ++i) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; ++i) {
        solved[i] = false;
    }
    cout << solve(n) << endl;

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
