#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 10, INF = 1e9;
bool ready[N][N];
int value[N][N];
string a, b;
int n, m;

int solve(int i, int j) {
    if (i == 0) return j;
    if (j == 0) return i;
    if (ready[i][j]) return value[i][j];
    int ans = INF;
    if (a[i] == b[j])
        ans = min(ans, solve(i - 1, j - 1));
    else
        ans = min(ans, solve(i - 1, j - 1) + 1);
    ans = min(ans, solve(i - 1, j) + 1);
    ans = min(ans, solve(i, j - 1) + 1);
    ready[i][j] = true;
    value[i][j] = ans;
    return value[i][j];
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
    cin >> a >> b;
    n = a.size();
    m = b.size();
    a = " " + a;
    b = " " + b;
    cout << solve(n, m) << endl;

#ifdef TIMING
    auto end = chrono::steady_clock::now();
    cout << "\nElapsed time in milliseconds : "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms\n";
#endif
    return 0;
}
