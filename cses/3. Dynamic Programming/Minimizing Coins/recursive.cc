#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, K = 110, INF = 1e9;
int f[N], c[K];
bool solved[N];
int n, k;

int solve(int x) {
    if (x < 0) return INF;
    else if (x == 0) return 0;
    else if (solved[x]) return f[x];
    else {
        f[x] = INF;
        for (int i = 0; i < k; ++i) {
            f[x] = min(f[x], solve(x - c[i]) + 1);
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
    int v = solve(n);
    if (v == INF) cout << -1 << endl;
    else cout << v << endl;

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
