#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int matrix[N][N];
long long prefix_sum[N][N];

void solve() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> matrix[i][j];
                prefix_sum[i][j] = prefix_sum[i - 1][j - 1] + matrix[i][j];
            }
        }
        long long best = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                best = max(best, prefix_sum[i][j]);
                if (i == j) best = max(best, prefix_sum[n][n] - prefix_sum[i][j]);
                else if (i > j) best = max(best, prefix_sum[n][n - (i - j)]);
                else best = max(best, prefix_sum[n - (j - i)][n]);
            }
        }
        cout << "Case #" << t << ": " << best << endl;
    }
}

int main() {
#ifdef TIMING
    auto start = chrono::steady_clock::now();
#endif
    ios_base::sync_with_stdio(false);
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
