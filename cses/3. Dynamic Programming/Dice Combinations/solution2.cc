#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, MOD = 1e9 + 7;
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
    int n;
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 6 && j <= i; ++j) {
            f[i] = (f[i] + f[i - j]) % MOD;
        }
    }
    cout << f[n] << endl;

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
