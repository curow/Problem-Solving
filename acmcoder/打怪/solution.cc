#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
bool revenge[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        revenge[i] = x == 1 ? true : false;
    }
    int armor[n];
    for (int i = 0; i < n; ++i) armor[i] = 1;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += armor[i];
        if (revenge[i] && i + 1 < n && !revenge[i + 1]) armor[i + 1] += 1;
    }
    cout << cnt << endl;
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
