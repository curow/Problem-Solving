#include <bits/stdc++.h>
using namespace std;

const int S = 63000, N = 510, MOD = 1e9 + 7;

bool ready[N][S];
int value[N][S];

int search(int n, int s) {
    if (s == 0) return 1;
    if (n <= 0 || s < 0) return 0;
    if (ready[n][s]) return value[n][s];
    value[n][s] = (search(n - 1, s) + search(n - 1, s - n)) % MOD;
    ready[n][s] = true;
    return value[n][s];
}

long long modulo_inverse(long long x) {
    long long p = MOD - 2, r = 1;
    while (p) {
        if (p & 1) r = (r * x) % MOD;
        p = p >> 1;
        x = (x * x) % MOD;
    }
    return r;
}

void solve() {
    int n;
    cin >> n;
    int s = n * (n + 1) / 2;
    if (s % 2 == 0) {
        cout << search(n, s / 2) * modulo_inverse(2) % MOD << endl;
    } else {
        cout << 0 << endl;
    }
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
