#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10, X = 1e5 + 10;
int price[N], pages[N], value[X];

int solve(int n, int x) {
    for (int j = 0; j <= x; ++j) value[j] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = x; j >= 0; --j) {
            if (j >= price[i])
                value[j] = max(value[j], value[j - price[i]] + pages[i]);
        }
    }
    return value[x];
}

int main() {
#ifdef TIMING
    auto start = chrono::steady_clock::now();
#endif
#ifdef DEBUG
    freopen("input.txt", "r", stdin);    // redirects standard input
    freopen("output.txt", "w", stdout);  // redirects standard output
#endif

    // solve the problem
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> price[i];
    for (int i = 1; i <= n; ++i) cin >> pages[i];
    cout << solve(n, x) << endl;

#ifdef TIMING
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
#endif
    return 0;
}
