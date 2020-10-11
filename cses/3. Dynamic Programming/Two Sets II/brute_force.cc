#include <bits/stdc++.h>
using namespace std;

int n, target_sum;
int cnt = 0;
int subset_sum = 0;

void search(int k) {
    if (k == n + 1) {
        if (subset_sum == target_sum) ++cnt;
        return;
    }
    subset_sum += k;
    search(k + 1);
    subset_sum -= k;
    search(k + 1);
}

void solve() {
    cin >> n;
    int s = n * (n + 1) / 2;
    if (s % 2 == 0) {
        target_sum = s / 2;
        search(1);
    }
    cout << cnt / 2 << endl;
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
