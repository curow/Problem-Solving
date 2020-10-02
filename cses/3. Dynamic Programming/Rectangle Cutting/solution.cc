#include <bits/stdc++.h>
using namespace std;

const int N = 510, INF = 1e9;
bool ready[N][N];
int value[N][N];

int solve(int i, int j) {
    if (i == j) return 0;
    if (i == 1) return j - 1;
    if (j == 1) return i - 1;
    if (ready[i][j]) return value[i][j];
    if (ready[j][i]) return value[j][i];
    int ans = INF;
    for (int k = 1; k <= i / 2; ++k) ans = min(ans, solve(k, j) + solve(i - k, j) + 1);
    for (int k = 1; k <= j / 2; ++k) ans = min(ans, solve(i, k) + solve(i, j - k) + 1);
    value[i][j] = ans;
    ready[i][j] = true;
    return value[i][j];
}

/* int solve(int x, int y) { */
/*     for (int i = 1; i <= x; ++i) value[i][1] = i - 1; */
/*     for (int j = 1; j <= y; ++j) value[1][j] = j - 1; */
/*     for (int i = 1; i <= min(x, y); ++i) value[i][i] = 0; */
/* } */

int main() {
    #ifdef TIMING 
    auto start = chrono::steady_clock::now();
    #endif
    #ifdef DEBUG
    freopen("input.txt", "r", stdin); // redirects standard input
    freopen("output.txt", "w", stdout); // redirects standard output
    #endif

    // solve the problem
    int a, b;
    cin >> a >> b;
    cout << solve(a, b) << endl;

    #ifdef TIMING 
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
    #endif
    return 0;
}
