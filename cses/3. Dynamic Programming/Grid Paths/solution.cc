#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10, MOD = 1e9 + 7;
bool no_trap[N][N];
int value[N][N];

int solve(int x, int y) {
    for (int i = 0; i <= x; ++i) {
        for (int j = 0; j <= y; ++j) {
          if (no_trap[i][j]) {
            if (i == 1 && j == 1)
              value[i][j] = 1;
            else
              value[i][j] = (value[i - 1][j] + value[i][j - 1]) % MOD;
          } else {
            value[i][j] = 0;
          }
        }
    }
    return value[x][y];
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
    int n;
    cin >> n;
    for (int k = 0; k <= n; ++k) {
      no_trap[0][k] = no_trap[k][0] = false;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            char c;
            cin >> c;
            if (c == '*')
              no_trap[i][j] = false;
            else
              no_trap[i][j] = true;
        }
    }
    cout << solve(n, n) << endl;

#ifdef TIMING
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
#endif
    return 0;
}
