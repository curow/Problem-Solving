#include <bits/stdc++.h>
using namespace std;

int search(int n) {
    int l = 1, r = sqrt(2 * n) + 1;
    while (l < r) {
        int mid = (l + r) / 2 + 1;
        if (mid * (mid + 1) / 2 <= n) l = mid;
        else r = mid - 1;
    }
    return l;
}

void solve() {
    int n;
    while (cin >> n) {
        int k = search(n);
        int s = 1;
        if (k >= 3) s += (k - 2) * (k - 1) / 2;
        cout << s + (n - k * (k + 1) / 2) << endl;
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
