#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 110, MOD = 1e9 + 7;
bool ready[M][N];
int ans[M][N];
int value[N];
int n, m;

int solve(int x, int i) {
    if (i == 1) return 1;
    if (ready[x][i]) return ans[x][i];
    if (value[i - 1] != 0) {
        if (abs(value[i - 1] - x) <= 1) {
            ans[x][i] = solve(value[i - 1], i - 1);
        } else {
            ans[x][i] = 0;
        }
    } else {
        for (int k : {x - 1, x, x + 1}) {
            if (k >= 1 && k <= m)
                ans[x][i] = (ans[x][i] + solve(k, i - 1)) % MOD;
        }
    }
    ready[x][i] = true;
    return ans[x][i];
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
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> value[i];
    if (value[n] != 0) {
        cout << solve(value[n], n) << endl;
    } else {
        int total = 0;
        for (int x = 1; x <= m; ++x)
            total = (total + solve(x, n)) % MOD;
        cout << total << endl;
    }

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
